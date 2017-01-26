#define _CRT_SECURE_NO_WARNINGS
#include "testlib.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

typedef unsigned long long ull;
const int N = (int)1e6;
const int P = 31;

ull pow_p[N];

void init()
{
	pow_p[0] = 1;
	for (int i = 1; i < N; i++)
		pow_p[i] = pow_p[i - 1] * P;
}

vector<ull> build_pref_hash(const string &s)
{
	int n = (int)s.length();
	if (n > N)
		throw;
	vector<ull> h(n);
	for (int i = 0; i < n; i++)
	{
		h[i] = (s[i] - 'a' + 1) * pow_p[i];
		if (i > 0)
			h[i] += h[i - 1];
	}
	return h;
}

ull get_hash(const vector<ull> &h, int l, int r)
{
	ull res = h[r];
	if (l > 0)
		res -= h[l - 1];
	return res * pow_p[N - 1 - l];
}

bool is_pal(const vector<ull> &h, const vector<ull> &rh, int l, int r)
{
	int n = (int)h.size();
	return get_hash(h, l, r) == get_hash(rh, n - 1 - r, n - 1 - l);
}

string cut_from_sides(string s)
{
	int left = rnd.next(s.length());
	int right = rnd.next(s.length() - left);
	return s.substr(left, (int)s.length() - left - right);
}

char rand_char()
{
	return rnd.next(3) + 'a';
}

string gen_pal(int depth)
{
	if (depth == 0)
		return string(1, rand_char());

	string p = gen_pal(depth - 1);
	string u = gen_pal(depth - 1);

	int cnt = rnd.next(5) + 1;
	string s;
	for (int i = 0; i < cnt; i++)
		s += p + u;
	s += p;
	s = cut_from_sides(s);
	if ((int)s.length() > N)
		s = s.substr(0, N);

	string rs = s;
	reverse(rs.begin(), rs.end());
	vector<ull> h = build_pref_hash(s);
	vector<ull> rh = build_pref_hash(rs);

	int center;
	if (rnd.next(2) == 0)
	{
		vector<int> pref;
		for (int i = 1; i <= (int)s.length(); i++)
			if (is_pal(h, rh, 0, i - 1))
				pref.push_back(i);
		center = pref[rnd.next((int)pref.size())];
	}
	else
	{
		vector<int> suf;
		for (int i = 1; i <= (int)s.length(); i++)
			if (is_pal(h, rh, (int)s.length() - i, (int)s.length() - 1))
				suf.push_back(i);
		center = 2 * s.length() - suf[rnd.next((int)suf.size())];
	}

	int lpos = (center - 1) / 2;
	int rpos = center / 2;
	string sl, sr;
	for (int i = 0; ; i++)
	{
		int x = lpos - i;
		int y = rpos + i;
		if (x < 0 && y >= (int)s.length())
			break;
		char a, b;
		if (x < 0)
			a = b = s[y];
		else if (y >= (int)s.length())
			a = b = s[x];
		else
			a = s[x], b = s[y];
		if (x == y)
			sl += a;
		else
			sl += a, sr += b;
	}
	reverse(sl.begin(), sl.end());
	s = sl + sr;

	int append = rnd.next(5);
	for (int i = 0; i < append; i++)
	{
		char c = rand_char();
		s = c + s + c;
	}

	return s;
}

int main(int argc, char *argv[])
{
	registerGen(argc, argv, 1);
	init();
	string res = gen_pal(atoi(argv[1]));
	res = cut_from_sides(res);
	if ((int)res.length() > N)
		res = res.substr(0, N);
	cout << res << endl;

	return 0;
}
