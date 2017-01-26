#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
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

typedef unsigned int uint;

const int INF = (int)1e9;
int PREDICT_STEP = 4;
const int S = 4;
const int MS = 2 * S;
#ifndef LOCAL
const int N = 1000500;
#else
const int N = 105;
#endif
const int DN = 2 * N;

bool get_bit(uint mask, int p)
{
	return (mask & (1U << p)) != 0;
}

uint set_bit(uint mask, int p, bool x)
{
	if (x)
		return mask | (1U << p);
	return mask & ~(1U << p);
}

int get_trit(uint mask, int p)
{
	return 2 * get_bit(mask, 2 * p + 1) + get_bit(mask, 2 * p) - 1;
}

uint set_trit(uint mask, int p, int x)
{
	return set_bit(set_bit(mask, 2 * p, (x + 1) % 2 != 0), 2 * p + 1, (x + 1) / 2 != 0);
}

uint bit_rev[1 << MS];
int bit_sum[S + 1][1 << MS];
uint bit_left_shift[S][1 << MS];
uint bit_right_shift[S][1 << MS];
uint bit_min[2 * S][1 << MS][1 << MS];
uint bit_iter[S + 1][S + 1][1 << MS];

void init_table()
{
	for (uint mask = 0; mask < (1U << MS); mask++)
	{
		uint new_mask = set_trit(0, 0, 0);
		int bal = 0;
		for (int i = 0; i < S; i++)
		{
			int t = get_trit(mask, i);
			bal += t;
			bit_sum[i + 1][mask] = bal;
			if (i > 0)
				new_mask = set_trit(new_mask, S - i, -t);
		}
		bit_rev[mask] = new_mask;
	}

	for (uint mask = 0; mask < (1U << MS); mask++)
		for (int i = 0; i < S; i++)
		{
			uint new_mask = mask >> (2 * i);
			new_mask = set_trit(new_mask, 0, 0);
			for (int j = S - i; j < S; j++)
				new_mask = set_trit(new_mask, j, 1);
			bit_left_shift[i][mask] = new_mask;

			new_mask = (mask << (2 * i)) & ((1 << (2 * S)) - 1);
			new_mask = set_trit(new_mask, 0, 0);
			for (int j = 1; j <= i; j++)
				new_mask = set_trit(new_mask, j, -1);
			bit_right_shift[i][mask] = new_mask;
		}

	for (uint mask1 = 0; mask1 < (1U << MS); mask1++)
		for (uint mask2 = 0; mask2 < (1U << MS); mask2++)
			for (int bal = 0; bal < 2 * S; bal++)
			{
				uint new_mask = 0;
				int sum1 = bal, sum2 = 0;
				int prv = 0;
				for (int i = 0; i < S; i++)
				{
					sum1 += get_trit(mask1, i);
					sum2 += get_trit(mask2, i);
					int nxt = min(sum1, sum2);
					new_mask = set_trit(new_mask, i, nxt - prv);
					prv = nxt;
				}
				bit_min[bal][mask1][mask2] = new_mask;
			}

	for (int len = 1; len <= S; len++)
		for (int cnt = 1; len * cnt <= S; cnt++)
			for (uint mask = 0; mask < (1U << MS); mask++)
			{
				int vals[S] = {};
				for (int i = 1; i < len * cnt; i++)
					vals[i] = vals[i - 1] + get_trit(mask, i % len);
				for (int i = len * cnt; i < S; i++)
					vals[i] = vals[i - 1] + 1;
				for (int i = 1; i < S; i++)
					vals[i] = min(vals[i], vals[i - 1] + 1);
				for (int i = S - 2; i >= 0; i--)
					vals[i] = min(vals[i], vals[i + 1] + 1);
				uint new_mask = set_trit(0, 0, 0);
				for (int i = 1; i < S; i++)
					new_mask = set_trit(new_mask, i, vals[i] - vals[i - 1]);
				bit_iter[len][cnt][mask] = new_mask;
			}
}

struct BlockMin
{
	int val;
	uint mask;

	BlockMin() : val(INF), mask()
	{
		for (int i = 0; i < S; i++)
			mask = set_trit(mask, i, 0);
	}

	BlockMin(int _val, uint _mask) : val(_val), mask(_mask) {}

	int get(int p)
	{
		return val + bit_sum[p + 1][mask];
	}

	BlockMin reverse()
	{
		return BlockMin(val + bit_sum[S][mask], bit_rev[mask]);
	}

	BlockMin left_shift(int len)
	{
		return BlockMin(val + bit_sum[len + 1][mask], bit_left_shift[len][mask]);
	}

	BlockMin right_shift(int len)
	{
		return BlockMin(val + len, bit_right_shift[len][mask]);
	}

	BlockMin apply(BlockMin o, int a, int b, int len, bool rev, bool inc)
	{
		if (rev)
		{
			o = o.reverse();
			b = S - 1 - (b + len - 1);
		}
		o = o.right_shift(S - 1 - (b + len - 1)).left_shift(S - len).right_shift(a);
		if (inc)
			o.val++;
		int bal = val - o.val;
		if (bal <= -2 * S)
			return *this;
		if (bal >= 2 * S)
			return o;
		int new_val = min(val, o.val);
		if (bal < 0)
			return BlockMin(new_val, bit_min[-bal][o.mask][mask]);
		return BlockMin(new_val, bit_min[bal][mask][o.mask]);
	}

	BlockMin reset_suf(int a)
	{
		return right_shift(S - a).left_shift(S - a);
	}

	BlockMin iterate_pref(int len, int cnt)
	{
		return BlockMin(val, bit_iter[len][cnt][mask]);
	}

	void eprint()
	{
		eprintf("val = %d; mask = { ", val);
		for (int i = 0; i < S; i++)
			eprintf("%d ", get_trit(mask, i));
		eprintf("}\n");
	}
};

struct GappedVector;

struct DPVector
{
	int _size;
	vector<BlockMin> v;
	DPVector() : _size() {}
	bool empty()
	{
		return _size == 0;
	}
	BlockMin &operator[](int p)
	{
		return v[p];
	}
	int get(int p)
	{
		return v[p / S].get(p % S);
	}
	void extend()
	{
		while ((int)v.size() * S < _size)
			v.push_back(BlockMin());
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
	void resize(int new_len)
	{
		_size = new_len;
		extend();
	}
	DPVector substr(int start, int len)
	{
		if (len <= 0)
			return DPVector();
		DPVector res;
		res.resize(len);
		res.apply_seg(0, len - 1, *this, start, start + len - 1, false, false, false);
		return res;
	}
	DPVector iterate(int cnt)
	{
		DPVector res;
		if (size() * cnt <= S)
		{
			res.resize(size() * cnt);
			res[0] = v[0].iterate_pref(size(), cnt);
		}
		else
		{
			for (int i = 0; i < cnt; i++)
				res = res.concat(*this);
		}
		return res;
	}
	DPVector concat(DPVector o)
	{
		if (o.empty())
			return *this;
		auto res = *this;
		res.resize(res.size() + o.size());
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
	HE_UNDEF, HE_SET, HE_SET_VEC, HE_SWAP_VEC, HE_RESIZE_VEC
};

struct HistoricEvent
{
	HistoricEventType type;
	void *ptr;
	int arg1;
	BlockMin arg2;
	void *ptr1;
	HistoricEvent(HistoricEventType _type, void *_ptr, int _arg1 = 0, BlockMin _arg2 = BlockMin(),
		void *_ptr1 = nullptr) : type(_type), ptr(_ptr), arg1(_arg1), arg2(_arg2), ptr1(_ptr1) {}
};

struct HistoryManager
{
	vector<HistoricEvent> events;

	void set(int *ptr, int val)
	{
		events.push_back(HistoricEvent(HE_SET, ptr, *ptr));
		*ptr = val;
	}

	void set_vec(DPVector *ptr, int id, BlockMin val)
	{
		events.push_back(HistoricEvent(HE_SET_VEC, ptr, id, (*ptr)[id]));
		(*ptr)[id] = val;
	}

	void swap_vec(DPVector *ptr1, DPVector *ptr2)
	{
		events.push_back(HistoricEvent(HE_SWAP_VEC, ptr1, 0, BlockMin(), ptr2));
		ptr1->swap(*ptr2);
	}

	void resize_vec(DPVector *ptr, int new_size)
	{
		events.push_back(HistoricEvent(HE_RESIZE_VEC, ptr, ptr->size()));
		ptr->resize(new_size);
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
			if (ev.type == HE_SET_VEC)
				(*ptr)[ev.arg1] = ev.arg2;
			else if (ev.type == HE_SWAP_VEC)
				ptr->swap(*(DPVector*)ev.ptr1);
			else if (ev.type == HE_RESIZE_VEC)
				ptr->resize(ev.arg1);
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
	for (int i = c; i <= d; )
	{
		int j = rev ? r - (i - c) : l + (i - c);
		int p1 = i / S;
		int p2 = j / S;
		int len1 = min(d - i + 1, S - i % S);
		int len2 = rev ? min(j - l + 1, j % S + 1) : min(r - j + 1, S - j % S);
		int len = min(len1, len2);
		BlockMin res = v[p2].apply(from[p1], rev ? j % S - len + 1 : j % S, i % S, len, rev, inc);
		if (history)
			hist.set_vec(this, p2, res);
		else
			v[p2] = res;
		i += len;
	}
}

void DPVector::reset_seg(int l, int r, bool history)
{
	int p1 = l / S;
	int p2 = r / S;
	if (l % S != 0)
	{
		BlockMin res = v[p1].reset_suf(l % S);
		if (history)
			hist.set_vec(this, p1, res);
		else
			v[p1] = res;
		p1++;
	}
	for (int p = p1; p <= p2; p++)
	{
		if (history)
			hist.set_vec(this, p, BlockMin());
		else
			v[p] = BlockMin();
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
			a.resize(old_size + (r - l + 1));
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
				a.resize(0);
			}
		}
	}

	DPVector substr(int start, int len)
	{
		int end = start + len - 1;
		DPVector res;
		res.resize(len);
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
		a.resize(0);
		b.resize(0);
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
	printf("%d\n", dp.get(i + 1));
#else
	if (dp.get(i + 1) != slow_dp[i + 1])
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
	for (int i = 0; i <= n; i++)
		per_dp[i] = GappedVector(i);
	dp.resize(n + 1);
	dp[0].val = 0;
	for (int i = 1; i < S; i++)
		dp[0].mask = set_trit(dp[0].mask, i, 1);
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

	init_table();
#ifndef STRESS
	solve();
#else
	srand(31415);
	for (int alpha = 2; alpha <= 3; alpha++)
		for (int len = alpha; len <= 30; len++)
			for (PREDICT_STEP = 1; PREDICT_STEP <= 4; PREDICT_STEP++)
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