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

namespace N3
{
	const int N = 10500;
	const int INF = (int)1e9;

	int dp[N];

	bool is_pal(const string &s)
	{
		string t = s;
		reverse(t.begin(), t.end());
		return s == t;
	}

	vector<int> solve(const string &s)
	{
		int n = (int)s.length();

		fill(dp, dp + n + 1, INF);
		dp[0] = 0;
		for (int i = 0; i < n; i++)
			for (int j = i; j < n; j++)
				if (is_pal(s.substr(i, j - i + 1)))
					dp[j + 1] = min(dp[j + 1], dp[i] + 1);

		return vector<int>(dp + 1, dp + n + 1);
	}
}

void solve()
{
	char buf[300500];
	scanf("%s", buf);
	string s(buf);

	auto res = N3::solve(s);
	for (int e : res)
		printf("%d ", e);
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