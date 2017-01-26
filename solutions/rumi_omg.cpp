#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
int m[3000500]={1, 2}, z[3000500], l[30]={0, 1}, newL[30]={0, 1}, p[30]={1, 1}, newP[30] = {1, 1}, n = 2, newN = 2;
char s[3000500];
int testMin(int & a, int b) {return a = std::min(a, b);}
int main() {
	scanf("%s", s + 1);printf("1\n");
	for(int N = 2; s[N] != 0; N++) m[N] = 1e9;
	for (int N = 2; s[N] != 0; N++) {
		for (int j = 0; j < n; j++) {
			int L = l[j] + 2, P = p[j];
			if (s[N] != s[N - L + 1 + P]) P = L - newL[newN - 1];
			if (s[N] != s[N - L + 1]) L -= P;
			if (L <= newL[newN - 1]) continue;
			if (P == newP[newN - 1] && newL[newN - 1] >= 2 * newP[newN - 1]) newL[newN - 1] = L;
			else newL[newN] = L, newP[newN] = P, newN++;
		}
		std::swap(newP, p), std::swap(newL, l), std::swap(newN, n), newN = 2;
		for (int j = 1; j < n; j++) {
			if (l[j] < 3 * p[j]) z[N - l[j]] = m[N - l[j]];
			testMin(m[N], testMin(z[N - l[j]], m[N - p[j] - l[j] % p[j] ]) + 1);
		}
		printf("%d\n", m[N] - 1);
	}
}
