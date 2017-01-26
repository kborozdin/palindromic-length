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

const int N = 1000500;
const int INF = (int)1e9;

void minize(int &a, int b)
{
	a = min(a, b);
}

int n;
char s[N];
int l[2 * N], r[2 * N];
int head, tail;
int dp[N], last_dp[N];

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

int get_period(int v, int i)
{
	return get_len(v, i) - get_len(r[v], i);
}

void link(int a, int b)
{
	r[a] = b;
	l[b] = a;
}

void append(int v)
{
	link(l[tail], v);
	link(v, tail);
}

int jump_over(int v, int i)
{
	if (l[v] == head || get_period(v, i) != get_period(l[v], i))
		return r[v];
	int len = get_len(v, i);
	int per = get_period(v, i);
	int to = get_center(len % per + per, i);
	if (v < to && get_period(to, i) < per)
		return to;
	return get_center(len % per, i);
}

void add_char(int i)
{
	for (int v = r[head]; v != tail; )
	{
		int len = get_len(v, i - 1);
		if (i - len - 1 < 0 || s[i] != s[i - len - 1])
		{
			link(l[v], r[v]);
			v = r[v];
		}
		else
			v = jump_over(v, i - 1);
	}
	if (i - 1 >= 0 && s[i - 1] == s[i])
		append(get_center(2, i));
	append(get_center(1, i));
}

void calc_dp(int v, int i)
{
	int jmp = jump_over(v, i);
	int baby_len = get_len(jmp, i) + get_period(v, i);
	int &last = last_dp[i - get_len(v, i) + 1];
	if (jmp == r[v])
		last = INF;
	minize(last, dp[i - baby_len + 1] + 1);
	minize(dp[i + 1], last);
}

void solve()
{
	scanf("%s", s);
	n = strlen(s);

	init();
	fill(dp, dp + n + 1, INF);
	dp[0] = 0;

	for (int i = 0; i < n; i++)
	{
		add_char(i);
		for (int v = r[head]; v != tail; v = jump_over(v, i))
			calc_dp(v, i);
		printf("%d ", dp[i + 1]);
	}
	printf("\n");
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);
#endif

	solve();

	eprintf("\n\ntime: %.3lf\n", (double)clock() / CLOCKS_PER_SEC);
	return 0;
}