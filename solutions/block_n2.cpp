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
 
typedef unsigned uint;
#ifdef LOCAL
const int N = 1005;
#else
const int N = 1000500;
#endif
const int S = 4;
const int MS = 2 * S;
const int INF = (int)1e9;
 
bool get_bit(uint mask, int p)
{
    return mask & (1U << p);
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
    return set_bit(set_bit(mask, 2 * p, (x + 1) % 2), 2 * p + 1, (x + 1) / 2);
}

uint bit_rev[1 << MS];
int bit_sum[S + 1][1 << MS];
uint bit_left_shift[S][1 << MS];
uint bit_right_shift[S][1 << MS];
uint bit_min[2 * S][1 << MS][1 << MS];

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

    int get_val(int p)
    {
        return val + bit_sum[p + 1][mask];
    }

    BlockMin rev()
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
 
    BlockMin apply_reversed(BlockMin o, int a, int b, int len)
    {
        o = o.rev().right_shift(b).left_shift(S - len);
        o.val++;
        o = o.right_shift(a);
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

    void eprint()
    {
        eprintf("val = %d; mask = { ", val);
        for (int i = 0; i < S; i++)
            eprintf("%d ", get_trit(mask, i));
        eprintf("}\n");
    }
};
 
int get_odd_rad(char s[], int n, int i)
{
    int r = 1;
    while (i - r >= 0 && i + r < n && s[i - r] == s[i + r])
        r++;
    return r;
}
 
int get_even_rad(char s[], int n, int i)
{
    int r = 0;
    while (i - r - 1 >= 0 && i + r < n && s[i - r - 1] == s[i + r])
        r++;
    return r;
}
 
template <typename Block>
void apply_seg(Block dp[], Block new_dp[], int a, int b, int c, int d)
{
    for (int i = a; i <= b; )
    {
        int j = d - (i - a);
        int p1 = i / S;
        int p2 = j / S;
        int len1 = min(b - i + 1, S - i % S);
        int len2 = min(j - c + 1, j % S + 1);
        int len = min(len1, len2);
        new_dp[p2] = new_dp[p2].apply_reversed(dp[p1], j % S - len + 1, i % S, len);
        i += len;
    }
}
 
template <typename Block>
void process(char s[], int n, Block dp[], Block new_dp[])
{
    for (int i = 0; i < n; i++)
    {
        int r = get_odd_rad(s, n, i);
        apply_seg(dp, new_dp, i - r + 1, i, i + 1, i + r);
        r = get_even_rad(s, n, i);
        if (r > 0)
            apply_seg(dp, new_dp, i - r, i - 1, i + 1, i + r);
    }
}
 
#ifdef STRESS
int slow_res[N];
bool is_pal(string s)
{
    string t = s;
    reverse(t.begin(), t.end());
    return s == t;
}
void calc_slow(char s[])
{
    string ss = s;
    int n = ss.length();
    fill(slow_res, slow_res + n + 1, INF);
    slow_res[0] = 0;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j <= n; j++)
            if (is_pal(ss.substr(i, j - i)))
                slow_res[j] = min(slow_res[j], slow_res[i] + 1);
}
#endif
 
void solve()
{
    char s[N];
#ifndef STRESS
    scanf("%s", s);
    int n = strlen(s);
#else
    int n = 20;
    for (int i = 0; i < n; i++)
        s[i] = rand() % 3 + 'a';
    s[n] = 0;
    calc_slow(s);
#endif
 
    init_table();

    BlockMin dp[N];
    fill(dp, dp + n + 1, BlockMin());
    dp[0].val = 0;
    for (int i = 1; i < S; i++)
        dp[0].mask = set_trit(dp[0].mask, i, 1);

    process(s, n, dp, dp);
 
    for (int i = 1; i <= n; i++)
    {
        int x = dp[i / S].get_val(i % S);
#ifndef STRESS
        printf("%d\n", x);
#else
        if (x != slow_res[i])
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
        eprintf("it = %d\n", it);
        solve();
    }
#endif
 
    eprintf("\n\ntime: %.3lf\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}