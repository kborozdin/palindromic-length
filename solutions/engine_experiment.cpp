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
#ifndef LOCAL
const int N = 1000500;
#else
const int N = 105;
#endif
const int DN = 2 * N;

struct DPVector {
	vector<int> v;
	DPVector() {}
	bool empty()
	{
		return v.empty();
	}
	int &back()
	{
		return v.back();
	}
	int &operator[](int x)
	{
		return v[x];
	}
	void push_back(int x)
	{
		v.push_back(x);
	}
	int size()
	{
		return v.size();
	}
	void swap(DPVector &other)
	{
		v.swap(other.v);
	}
	void clear()
	{
		v.clear();
	}
	void resize(int new_len, int val)
	{
		v.resize(new_len, val);
	}
};

struct GappedVector
{
	DPVector a, b;
	int apos, per;

	GappedVector() : apos(), per() {}
	GappedVector(int _per) : apos(), per(_per) {}

	int min_set(int p, int x)
	{
		if (a.empty())
			apos = p;
		a.push_back(x);
		if (p >= per - (int)b.size())
			a.back() = min(a.back(), b[p - (per - (int)b.size())]);
		int ans = a.back();
		if (p == per - 1)
		{
			a.swap(b);
			a.clear();
		}
		return ans;
	}

	void clear()
	{
		a.clear();
		b.clear();
		apos = 0;
	}
};

int n;
char s[N];
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
	tail = 2 * n;
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

int get_rad(int v, int i)
{
	int c = r[head];
	int can = i - rpos(v) + 1;
	if (v > c)
		v = reflect(v, c);
	return min((rad[v] + 1) / 2, can);
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

int BABY[N];

void check_left_side(int v, int i)
{
	int per = get_period(v, i);
	int cur_left_side = get_left_side(v, i);
	if (left_side[per] != cur_left_side)
	{
		per_dp[per].clear();
		BABY[per] = -1;
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
	if (BABY[per] != -1 && per > 1 && BABY[per] != l[jmp] && abs(BABY[per] - l[jmp]) != per)
		throw;
	BABY[per] = l[jmp];
	int idx = per - 1 - (i - baby_len + 1 - left_side[per]) % per;
	int last = per_dp[per].min_set(idx, dp[i - baby_len + 1] + 1);
	dp[i + 1] = min(dp[i + 1], last);
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
	string ss = s;
	fill(slow_dp, slow_dp + n + 1, INF);
	slow_dp[0] = 0;
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j <= n; j++)
			if (is_pal(ss.substr(i, j - i)))
				slow_dp[j] = min(slow_dp[j], slow_dp[i] + 1);
}
#endif

void solve()
{
#ifndef STRESS
	scanf("%s", s);
	n = strlen(s);
#else
	fill(l, l + 2 * n, 0);
	fill(r, r + 2 * n, 0);
	fill(rad, rad + 2 * n, 0);
	fill(left_side, left_side + 2 * n, 0);
	fill(dead_center, dead_center + 2 * n, false);
	fill(BABY, BABY + n + 1, -1);
	for (int i = 0; i < 2 * n; i++)
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

	for (int i = 0; i < n; i++)
	{
		add_char(i);
		for (int v = r[head]; v != tail; v = jump_over(v, i))
			calc_dp(v, i);
#ifndef STRESS
		printf("%d\n", dp[i + 1]);
#else
		if (dp[i + 1] != slow_dp[i + 1])
		{
			eprintf("failed at %s\n", s);
			throw;
		}
#endif
	}
}

#ifdef STRESS
void test_all_strings(int pos, int len, int alpha)
{
	if (pos == len)
	{
		n = len;
		s[n] = 0;
		solve();
		return;
	}
	for (char c = 'a'; c < 'a' + alpha; c++)
	{
		s[pos] = c;
		test_all_strings(pos + 1, len, alpha);
	}
}
void test_random_strings(int iters, int len, int alpha)
{
	n = len;
	s[n] = 0;
	for (int i = 0; i < iters; i++)
	{
		for (int j = 0; j < n; j++)
			s[j] = 'a' + rand() % alpha;
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
	for (int alpha = 2; alpha <= 30; alpha++)
		for (int len = alpha; len <= 17; len++)
		{
			eprintf("alpha = %d, len = %d\n", alpha, len);
			if (pow(alpha + 0., len + 0.) < 2e5)
				test_all_strings(0, len, alpha);
			else
				test_random_strings((int)1e5, len, alpha);
		}
#endif

	eprintf("\n\ntime: %.3lf\n", (double)clock() / CLOCKS_PER_SEC);
	return 0;
}