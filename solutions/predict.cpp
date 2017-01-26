#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <complex>
#include <random>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
using namespace std;



#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) (void)0
#endif

#ifdef LOCAL
#define STRESS
#endif

const int INF = (int)1e9;
int PREDICT_STEP = 5;
#ifndef LOCAL
const int N = 1000500;
#else
const int N = 105;
#endif
const int DN = 2 * N;

struct GappedVector;

struct DPVector
{
	int _size;
	vector<int> v;
	DPVector() : _size() {}
	bool empty()
	{
		return _size == 0;
	}
	int &operator[](int x)
	{
		return v[x];
	}
	void extend(int val)
	{
		while ((int)v.size() < _size)
			v.push_back(val);
	}
	int push_back(int x)
	{
		_size++;
		extend(0);
		int old_x = v[_size - 1];
		v[_size - 1] = x;
		return old_x;
	}
	void pop_back(int old_x = 0)
	{
		v[--_size] = old_x;
	}
	int size()
	{
		return _size;
	}
	void swap(DPVector &other)
	{
		::swap(_size, other._size);
		v.swap(other.v);
	}
	void clear()
	{
		_size = 0;
	}
	void resize(int new_len, int val)
	{
		_size = new_len;
		extend(val);
	}
	DPVector substr(int start, int len)
	{
		if (len <= 0)
			return DPVector();
		DPVector res;
		res._size = len;
		res.extend(INF);
		res.apply_seg(0, len - 1, *this, start, start + len - 1, false, false, false);
		return res;
	}
	DPVector iterate(int cnt)
	{
		DPVector res;
		for (int i = 0; i < cnt; i++)
			res = res.concat(*this);
		return res;
	}
	DPVector concat(DPVector o)
	{
		auto res = *this;
		res._size += o.size();
		res.extend(INF);
		res.reset_seg(size(), res.size() - 1, false);
		res.apply_seg(size(), res.size() - 1, o, 0, o.size() - 1, false, false, false);
		return res;
	}
	void apply_seg(int l, int r, DPVector &from, int c, int d, bool rev, bool inc, bool history);
	void apply_seg(int l, int r, GappedVector &from, int c, int d, bool history);
	void reset_seg(int l, int r, bool history);
};

enum HistoricEventType
{
	HE_UNDEF, HE_SET, HE_PUSH_BACK, HE_SET_VEC, HE_SWAP_VEC, HE_RESIZE_VEC
};

struct HistoricEvent
{
	HistoricEventType type;
	void *ptr;
	int arg1, arg2;
	void *ptr1;
	HistoricEvent(HistoricEventType _type, void *_ptr, int _arg1 = 0, int _arg2 = 0, void *_ptr1 = nullptr) :
		type(_type), ptr(_ptr), arg1(_arg1), arg2(_arg2), ptr1(_ptr1) {}
};

struct HistoryManager
{
	vector<HistoricEvent> events;

	void set(int *ptr, int val)
	{
		events.push_back(HistoricEvent(HE_SET, ptr, *ptr));
		*ptr = val;
	}

	void push_back(DPVector *ptr, int val)
	{
		int old_val = ptr->push_back(val);
		events.push_back(HistoricEvent(HE_PUSH_BACK, ptr, old_val));
	}

	void set_vec(DPVector *ptr, int id, int val)
	{
		events.push_back(HistoricEvent(HE_SET_VEC, ptr, id, (*ptr)[id]));
		(*ptr)[id] = val;
	}

	void swap_vec(DPVector *ptr1, DPVector *ptr2)
	{
		events.push_back(HistoricEvent(HE_SWAP_VEC, ptr1, 0, 0, ptr2));
		ptr1->swap(*ptr2);
	}

	void resize_vec(DPVector *ptr, int new_size)
	{
		events.push_back(HistoricEvent(HE_RESIZE_VEC, ptr, ptr->size()));
		ptr->resize(new_size, 0);
	}

	void undo()
	{
		while (!events.empty())
		{
			auto ev = events.back();
			events.pop_back();
			if (ev.type == HE_SET)
			{
				*(int*)ev.ptr = ev.arg1;
				continue;
			}
			DPVector *ptr = (DPVector*)ev.ptr;
			if (ev.type == HE_PUSH_BACK)
				ptr->pop_back(ev.arg1);
			else if (ev.type == HE_SET_VEC)
				(*ptr)[ev.arg1] = ev.arg2;
			else if (ev.type == HE_SWAP_VEC)
				ptr->swap(*(DPVector*)ev.ptr1);
			else if (ev.type == HE_RESIZE_VEC)
				ptr->resize(ev.arg1, 0);
			else
				throw;
		}
	}

	void forget()
	{
		events.clear();
	}
}
hist;

void DPVector::apply_seg(int l, int r, DPVector &from, int c, int d, bool rev, bool inc, bool history)
{
	for (int i = l; i <= r; i++)
	{
		int j = rev ? d - (i - l) : c + (i - l);
		int x = from[j];
		if (inc)
			x++;
		if (history)
			hist.set_vec(this, i, min(v[i], x));
		else
			v[i] = min(v[i], x);
	}
}

void DPVector::reset_seg(int l, int r, bool history)
{
	for (int i = l; i <= r; i++)
	{
		if (history)
			hist.set_vec(this, i, INF);
		else
			v[i] = INF;
	}
}

struct GappedVector
{
	DPVector a, b;
	int apos, per;

	GappedVector() : apos(), per() {}
	GappedVector(int _per) : apos(), per(_per) {}

	int suf()
	{
		return per - b.size();
	}

	void apply_seg(int l, int r, DPVector &from, int c, int d, bool history)
	{
		if (a.empty())
			apos = l;
		int old_size = a.size();
		if (history)
			hist.resize_vec(&a, old_size + (r - l + 1));
		else
			a.resize(old_size + (r - l + 1), 0);
		int al = old_size;
		int ar = al + (r - l);
		a.reset_seg(al, ar, history);
		a.apply_seg(al, ar, from, c, d, true, true, history);
		if (r >= suf())
			a.apply_seg(al + max(0, suf() - l), ar, b, max(0, l - suf()), r - suf(), false, false, history);
		if (r == per - 1)
		{
			if (history)
			{
				hist.swap_vec(&a, &b);
				hist.resize_vec(&a, 0);
			}
			else
			{
				a.swap(b);
				a.resize(0, 0);
			}
		}
	}

	DPVector substr(int start, int len)
	{
		int end = start + len - 1;
		DPVector res;
		res._size = len;
		res.extend(INF);
		int left = max(start, apos);
		int right = min(end, apos + a.size() - 1);
		res.apply_seg(left - start, right - start, a, left - apos, right - apos, false, false, false);
		int bstart = max(suf(), apos + a.size());
		left = max(start, bstart);
		right = min(end, per - 1);
		res.apply_seg(left - start, right - start, b, left - suf(), right - suf(), false, false, false);
		return res;
	}

	void clear()
	{
		a.clear();
		b.clear();
		apos = 0;
	}
};

void DPVector::apply_seg(int l, int r, GappedVector &from, int c, int d, bool history)
{
	int last = min(from.apos + from.a.size() - 1, d);
	apply_seg(l, l + (last - c), from.a, c - from.apos, last - from.apos, false, false, history);
	int suf = from.suf();
	if (d >= suf)
	{
		int start = max(suf, c);
		apply_seg(l + (start - c), r, from.b, start - suf, d - suf, false, false, history);
	}
}

int n, dn;
char s[N];
char scan_s[N];
int l[DN], r[DN];
int rad[DN];
vector<int> starting[N];
int head, tail;
DPVector dp;
GappedVector per_dp[N];
int left_side[N];
bool dead_center[DN];

int lpos(int v)
{
	return (v - 1) / 2;
}

int rpos(int v)
{
	return v / 2;
}

int cent(int i)
{
	return 2 * i + 1;
}

void init()
{
	head = 0;
	tail = dn;
	r[head] = tail;
	l[tail] = head;
}

int get_len(int v, int i)
{
	if (v == tail)
		return 0;
	return 2 * (i + 1) - v;
}

int get_center(int len, int i)
{
	if (len == 0)
		return tail;
	return 2 * (i + 1) - len;
}

int reflect(int v, int o)
{
	return o + (o - v);
}

int get_period(int v, int i)
{
	return get_len(v, i) - get_len(r[v], i);
}

void link(int a, int b)
{
	r[a] = b;
	l[b] = a;
}

int get_rad(int v, int i, bool prediction = false)
{
	int c = r[head];
	int can = i - rpos(v) + 1;
	if (v == c && prediction)
		return can;
	if (v > c)
		v = reflect(v, c);
	return min((rad[v] + 1) / 2, can);
}

char imag_s(int i)
{
	int c = r[head];
	if (cent(i) > c)
		i = rpos(reflect(cent(i), c));
	return s[i];
}

int get_left_side(int v, int i)
{
	int per = get_period(v, i);
	int len = get_len(v, i);
	int plen = len % per;
	if (plen == 0)
		plen = per;
	int start = i - len + 1;
	int center_v = cent(start) - 1 + plen;
	int cur_rad = get_rad(center_v, i);
	int left_side = lpos(center_v) - cur_rad + 1;
	if (left_side > 0 && s[left_side - 1] == s[left_side - 1 + per])
		throw;
	return left_side;
}

void check_left_side(int v, int i)
{
	int per = get_period(v, i);
	int cur_left_side = get_left_side(v, i);
	if (left_side[per] != cur_left_side)
	{
		per_dp[per].clear();
		left_side[per] = cur_left_side;
	}
}

void append_len(int len, int i, vector<pair<int, int>> &to_check)
{
	int v = get_center(len, i);
	rad[v] = len;
	link(l[tail], v);
	link(v, tail);
	to_check.push_back(make_pair(v, i));
	if (l[v] != head)
		to_check.push_back(make_pair(l[v], i));
}

void remove(int v, int i, vector<pair<int, int>> &to_check)
{
	dead_center[v] = true;
	link(l[v], r[v]);
	if (l[v] != head)
		to_check.push_back(make_pair(l[v], i));
}

int jump_over(int v, int i)
{
	int len = get_len(v, i);
	int per = get_period(v, i);
	int to = get_center(len % per + per, i);
	if (v < to && get_period(to, i) < per)
		return to;
	return get_center(len % per, i);
}

bool is_leading(int v, int i)
{
	return l[v] == head || get_period(l[v], i) != get_period(v, i);
}

void add_char(int i)
{
	vector<pair<int, int>> to_check;
	int old_c, c;
	for (old_c = c = r[head]; ; c++)
	{
		int suf = get_len(c, i - 1);
		if (suf == 0)
			break;
		rad[c] = min(rad[reflect(c, old_c)], suf);
		if (rad[c] == suf && i - suf - 1 >= 0 && s[i - suf - 1] == s[i])
		{
			rad[c] += 2;
			break;
		}
		if (rad[c] > 0)
		{
			if (rad[c] == suf)
				remove(c, i, to_check);
			starting[lpos(c) - get_rad(c, i) + 1].push_back(c);
		}
	}
	auto &to_del = starting[i - get_len(c, i - 1)];
	for (int j = 0; j < (int)to_del.size(); j++)
	{
		int v = to_del[j];
		remove(reflect(v, c), i, to_check);
	}
	if (i - 1 >= 0 && s[i - 1] == s[i])
		append_len(2, i, to_check);
	append_len(1, i, to_check);
	for (int j = 0; j < (int)to_check.size(); j++)
	{
		int v = to_check[j].first;
		int p = to_check[j].second;
		if (v == head || dead_center[v] || !is_leading(v, p))
			continue;
		check_left_side(v, p);
	}
}

void calc_dp(int v, int i)
{
	int per = get_period(v, i);
	int jmp = jump_over(v, i);
	int baby_len = get_len(jmp, i) + per;
	int idx = per - 1 - (i - baby_len + 1 - left_side[per]) % per;
	per_dp[per].apply_seg(idx, idx, dp, i - baby_len + 1, i - baby_len + 1, false);
	dp.apply_seg(i + 1, i + 1, per_dp[per], idx, idx, false);
}

void calc_all_dp(int i)
{
	for (int v = r[head]; v != tail; v = jump_over(v, i))
		calc_dp(v, i);
}

int mod_sub(int a, int b, int mod)
{
	return ((a - b) % mod + mod) % mod;
}

void predict_dp(int v, int start, int until)
{
	int per = get_period(v, start - 1);
	int jmp = jump_over(v, start - 1);
	int baby = l[jmp];
	int baby_len = get_len(baby, start - 1);

	int pos_serend = 0;
	int baby_rad = get_rad(baby, until - 1, true);
	int ls = get_left_side(v, start - 1);
	if (ls < lpos(baby) - baby_rad + 1)
		pos_serend = rpos(baby) + baby_rad;
	else
		pos_serend = rpos(baby) + (lpos(baby) - ls) + 1;

	int len_of_periodicity = pos_serend - left_side[per];
	int big_center = left_side[per] + pos_serend;
	int big_rad = get_rad(big_center, until - 1, true);
	int big_diam = big_rad * 2 - big_center % 2;
	int pos_big_death = pos_serend;
	if (big_diam > len_of_periodicity)
		pos_big_death = rpos(big_center) + big_rad;

	int coef = 2 * start - 1 - left_side[per] - baby_len;
	if (start < pos_serend)
	{
		int dp_coef = coef + left_side[per];
		int can = min(pos_serend - start, mod_sub(coef, start, per) + 1);
		int from = per - 1 - mod_sub(coef, start, per);
		int to = per - 1 - mod_sub(coef, start + can - 1, per);
		per_dp[per].apply_seg(from, to, dp, dp_coef - (start + can - 1), dp_coef - start, true);
		if (start + can < pos_serend)
			per_dp[per].apply_seg(0, 0, dp, dp_coef - (start + can), dp_coef - (start + can), true);
	}

	int full = pos_serend - start;
	int prefix = min(full, mod_sub(coef, start, per) + 1);
	int mid_cnt = (full - prefix) / per;
	int suffix = full - prefix - mid_cnt * per;
	auto prefix_vec = per_dp[per].substr(per - 1 - mod_sub(coef, start, per), prefix);
	auto mid_vec = mid_cnt == 0 ? DPVector() : per_dp[per].substr(0, per).iterate(mid_cnt);
	auto suffix_vec = per_dp[per].substr(per - 1 - mod_sub(coef, start + prefix + mid_cnt * per, per), suffix);
	auto sub = prefix_vec.concat(mid_vec).concat(suffix_vec);
	dp.apply_seg(start + 1, start + full, sub, 0, sub.size() - 1, false, false, true);

	int left = pos_serend;
	int right = pos_big_death - 1;
	if (left <= right)
	{
	    dp.apply_seg(left + 1, right + 1, dp,
		    rpos(reflect(cent(right), big_center)), rpos(reflect(cent(left), big_center)), true, true, true);
	}
}

void predict(int start, int until)
{
	if (start == until)
		return;
	for (int v = r[head]; v != tail; v = jump_over(v, start - 1))
		predict_dp(v, start, until);
}

void predict_small_pals(int i, int until)
{
	int cur_r = get_rad(cent(i), until - 1);
	dp.apply_seg(i + 1, i + cur_r, dp, i - cur_r + 1, i, true, true, true);
	cur_r = get_rad(cent(i) - 1, until - 1);
	dp.apply_seg(i + 1, i + cur_r, dp, i - cur_r, i - 1, true, true, true);
}

void finalize_predict(int start, int until)
{
	hist.undo();
	//TODO
}

void finalize_predict_slow(int start, int until)
{
	hist.undo();
	//TODO
}

#ifdef STRESS
int slow_dp[N];
bool is_pal(string p)
{
	string t = p;
	reverse(t.begin(), t.end());
	return p == t;
}
void calc_slow()
{
	string ss = scan_s;
	fill(slow_dp, slow_dp + n + 1, INF);
	slow_dp[0] = 0;
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j <= n; j++)
			if (is_pal(ss.substr(i, j - i)))
				slow_dp[j] = min(slow_dp[j], slow_dp[i] + 1);
}
#endif

void print_ans(int i)
{
#ifndef STRESS
	printf("%d\n", dp[i + 1]);
#else
	if (dp[i + 1] != slow_dp[i + 1])
	{
		eprintf("failed at %s\n", scan_s);
		throw;
	}
#endif
}

void solve()
{
#ifndef STRESS
	scanf("%s", scan_s);
	n = strlen(scan_s);
	dn = 2 * n;
#else
	dn = 2 * n;
	fill(l, l + dn, 0);
	fill(r, r + dn, 0);
	fill(rad, rad + dn, 0);
	fill(left_side, left_side + n + 1, 0);
	fill(dead_center, dead_center + dn, false);
	for (int i = 0; i <= n; i++)
	{
		starting[i] = vector<int>();
		per_dp[i] = GappedVector();
	}
	dp = DPVector();
	calc_slow();
#endif

	init();
	dp.resize(n + 1, INF);
	for (int i = 0; i <= n; i++)
		per_dp[i] = GappedVector(i);
	dp[0] = 0;
	for (int i = 0; i < n; i++)
		left_side[i] = -INF;

	for (int start = 0; start < n; )
	{
		int until = min(min(n, start + PREDICT_STEP),
			start + start - get_len(r[head], start - 1));
		predict(start, until);
		int i;
		for (i = start; i < until; i++)
		{
			s[i] = scan_s[i];
			if (s[i] != imag_s(i))
			{
				hist.undo();
				predict(start, i);
				for (int j = start; j < i; j++)
					predict_small_pals(j, i);
				break;
			}
			predict_small_pals(i, until);
			print_ans(i);
		}
		if (start + PREDICT_STEP != i)
		{
			finalize_predict_slow(start, i - 1);
			for (int j = start; j < i; j++)
			{
				add_char(j);
				calc_all_dp(j);
			}
		}
		else
		{
			finalize_predict(start, i - 1);
			for (int j = start; j < i; j++)
			{
				add_char(j);
				calc_all_dp(j);
			}
		}
		if (i < n)
		{
			s[i] = scan_s[i];
			add_char(i);
			calc_all_dp(i);
			print_ans(i);
		}
		start = i + 1;
	}
}

#ifdef STRESS
void test_all_strings(int pos, int len, int alpha)
{
	if (pos == len)
	{
		n = len;
		scan_s[n] = 0;
		solve();
		return;
	}
	for (char c = 'a'; c < 'a' + alpha; c++)
	{
		scan_s[pos] = c;
		test_all_strings(pos + 1, len, alpha);
	}
}
void test_random_strings(int iters, int len, int alpha)
{
	n = len;
	scan_s[n] = 0;
	for (int i = 0; i < iters; i++)
	{
		for (int j = 0; j < n; j++)
			scan_s[j] = 'a' + rand() % alpha;
		solve();
	}
}
#endif

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);
#endif

#ifndef STRESS
	solve();
#else
	srand(31415);
	for (int alpha = 2; alpha <= 3; alpha++)
		for (int len = alpha; len <= 30; len++)
			for (PREDICT_STEP = 5; PREDICT_STEP <= 20; PREDICT_STEP += 5)
			{
				eprintf("step = %d alpha = %d, len = %d\n", PREDICT_STEP, alpha, len);
				if (pow(alpha + 0., len + 0.) < 2e5)
					test_all_strings(0, len, alpha);
				else
					test_random_strings((int)1e5, len, alpha);
			}
#endif

	eprintf("\n\ntime: %.3lf\n", (double)clock() / CLOCKS_PER_SEC);
	return 0;
}