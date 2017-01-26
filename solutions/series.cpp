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

//#define STRESS

typedef unsigned int uint;
const int N = 1000500;
const int INF = (int)1e9;

void minize(int &a, int b)
{
	a = min(a, b);
}

int n;
char s1[N + 1];
char *s = s1 + 1;
vector<pair<int, int>> series;
int dp[N], last_dp[N];

void add_char(int i)
{
	vector<pair<int, int>> new_series;
	new_series.emplace_back(1, 1);
	if (i - 1 >= 0 && s[i] == s[i - 1])
		new_series.emplace_back(2, 1);
	for (int j = 0; j < (int)series.size(); j++)
	{
		auto e = series[j];
		int leading = e.first;
		int per = e.second;
		char before_big = s[i - leading - 1];
		char before_not_so_big = s[i - leading - 1 + per];
		if (leading - per == (j == 0 ? 0 : series[j - 1].first))
			before_not_so_big = 0;
		char very_new = s[i];
		if (very_new == before_big && very_new == before_not_so_big)
			new_series.emplace_back(leading + 2, per);
		else if (very_new == before_big && very_new != before_not_so_big)
			new_series.emplace_back(leading + 2, leading + 2 - new_series.back().first);
		else if (very_new != before_big && very_new == before_not_so_big)
			new_series.emplace_back(leading - per + 2, per);
	}
	series.clear();
	for (auto e : new_series)
	{
		if (series.empty() || series.back().second != e.second)
			series.push_back(e);
		else
			series.back().first = e.first;
	}
	for (int j = 0; j < (int)series.size(); j++)
	{
		int baby_len = (j - 1 >= 0 ? series[j - 1].first : 0) + series[j].second;
		if (baby_len == series[j].first)
			last_dp[i - series[j].first + 1] = INF;
		minize(last_dp[i - series[j].first + 1], dp[i - baby_len + 1] + 1);
		minize(dp[i + 1], last_dp[i - series[j].first + 1]);
	}
}

#ifdef STRESS
bool is_pal(const string &s)
{
	string t = s;
	reverse(t.begin(), t.end());
	return s == t;
}
vector<uint> slow(const string &s)
{
	int n = (int)s.length();
	vector<uint> dp(n + 1);
	dp[0] = 1;
	for (int i = 0; i < n; i++)
		for (int j = 1; i + j <= n; j++)
			if (is_pal(s.substr(i, j)))
				dp[i + j] |= dp[i] << 1;
	return dp;
}
#endif

void solve()
{
#ifndef STRESS
	scanf("%s", s);
	n = strlen(s);
#else
	series.clear();
	memset(dp, 0, sizeof(dp));
	n = 10;
	for (int i = 0; i < n; i++)
		s[i] = rand() % 3 + 'a';
#endif

	fill(dp, dp + n + 1, INF);
	dp[0] = 0;

#ifdef STRESS
	auto dps = slow(s);
#endif

	for (int i = 0; i < n; i++)
	{
		add_char(i);
#ifndef STRESS
		printf("%d ", dp[i + 1]);
#else
		if (dps[i + 1] != dp[i + 1])
			throw;
#endif
	}
#ifndef STRESS
	printf("\n");
#endif
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

#ifndef STRESS
	solve();
#else
	srand(31415);
	while (true)
		solve();
#endif

	eprintf("\n\ntime: %.3lf\n", (double)clock() / CLOCKS_PER_SEC);
	return 0;
}