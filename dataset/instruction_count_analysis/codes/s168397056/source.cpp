#include<iostream>

#include<cstdio>

#include<cstring>

using namespace std;

typedef unsigned long long ULL;

ULL N, w;

ULL W[105];

ULL Value[105];

ULL f[200000];

inline ULL max(ULL x, ULL y) {

	return x > y ? x : y;

}

int main() {

	cin >> N >> w;

	ULL ans = 0;

	for (ULL i = 1; i <= N; i++)

		cin >> W[i] >> Value[i];

	memset(f, 0, sizeof(f));

	for (ULL i = 1; i <= N; i++)

		for (ULL j = w; j >= W[i]; j--)

			f[j] = max(f[j], f[j - W[i]] + Value[i]);

	cout << f[w];

	return 0;

}