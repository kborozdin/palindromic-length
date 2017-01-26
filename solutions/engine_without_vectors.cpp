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
const int N = 1005;
#endif
 
int n;
char s[N];
int l[2 * N], r[2 * N];
int rad[2 * N];
vector<int> starting[N];
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
 
void append_len(int len, int i)
{
    int v = get_center(len, i);
    rad[v] = len;
    link(l[tail], v);
    link(v, tail);
}
 
int jump_over(int v, int i)
{
//    if (l[v] == head || get_period(v, i) != get_period(l[v], i))
//        return r[v];
    int len = get_len(v, i);
    int per = get_period(v, i);
    int to = get_center(len % per + per, i);
    if (v < to && get_period(to, i) < per)
        return to;
    return get_center(len % per, i);
}
 
void add_char(int i)
{
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
                link(l[c], r[c]);
            starting[c / 2 - rad[c] / 2].push_back(c);
        }
    }
    for (int v : starting[i - get_len(c, i - 1)])
    {
        int inv_v = reflect(v, c);
        link(l[inv_v], r[inv_v]);
    }
    if (i - 1 >= 0 && s[i - 1] == s[i])
        append_len(2, i);
    append_len(1, i);
}
 
void calc_dp(int v, int i)
{
    int jmp = jump_over(v, i);
    int baby_len = get_len(jmp, i) + get_period(v, i);
    int &last = last_dp[i - get_len(v, i) + 1];
    if (jmp == r[v])
        last = INF;
    last = min(last, dp[i - baby_len + 1] + 1);
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
    memset(rad, 0, sizeof(rad));
    for (int i = 0; i < N; i++)
        starting[i].clear();
    memset(dp, 0, sizeof(dp));
    memset(last_dp, 0, sizeof(last_dp));
    n = 20;
    for (int i = 0; i < n; i++)
        s[i] = rand() % 3 + 'a';
    calc_slow();
#endif
 
    init();
    fill(dp, dp + n + 1, INF);
    dp[0] = 0;
 
    for (int i = 0; i < n; i++)
    {
        add_char(i);
        for (int v = r[head]; v != tail; v = jump_over(v, i))
            calc_dp(v, i);
#ifndef STRESS
        printf("%d\n", dp[i + 1]);
#else
        if (dp[i + 1] != slow_dp[i + 1])
            throw;
#endif
    }
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
    for (int it = 0; ; it++)
    {
        eprintf("test = %d\n", it);
        solve();
    }
#endif
 
    eprintf("\n\ntime: %.3lf\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}
