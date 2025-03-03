#include <iostream>

#include <cstdio>

#include <cstdlib>

#include <cstring>

#include <algorithm>

#include <string>



using namespace std;



const int MaxN = 2e5 + 5;



char S[MaxN];

long long Pred[MaxN][26], L, R, T;

int Next[MaxN], n;



void InitPred()

{

	for (int i = 1; i <= n; i++)

	{

		for (int j = 0; j < 26; j++) Pred[i][j] = Pred[i - 1][j];

		Pred[i][S[i] - 'a']++;

	}

}



void Kmp()

{

	Next[1] = 0;

	for (int j = 0, i = 2; i <= n; i++)

	{

		for (; j > 0 && S[j + 1] != S[i]; j = Next[j]);

		if (S[j + 1] == S[i])

			j++;

		Next[i] = j;

	}

}



void SwapOffset(long long &a, long long &b)

{

	long long tmp = b;

	b += a;

	a = tmp;

}



long long Fib(long long len, int c)

{

	if (len <= n)

		return Pred[len][c];

	if (len <= n * 2)

		return Pred[n][c] + Pred[len - n][c];

	long long f1 = Pred[n][c], f2 = Pred[n][c] + Pred[T][c], l1 = n, l2 = n + T, tmp;

	while (len > l1 + l2)

	{

		SwapOffset(f1, f2);

		SwapOffset(l1, l2);

	}

	return f2 + Fib(len - l2, c);

}



long long Calc(long long len, int c)

{

	if (len <= n)

		return Pred[len][c];

	if (len <= n * 2)

		return Pred[n][c] + Pred[len - n][c];

	if (n % T == 0)

	{

		long long res = 1LL * (len - n) / T * Pred[T][c] + Pred[n][c];

		len -= n, len %= T;

		return res + Pred[len][c];

	}

	else

		return Fib(len, c);

}



int main()

{

	scanf("%s%lld%lld", S + 1, &L, &R);

	n = strlen(S + 1) / 2;

	InitPred();

	Kmp();

	T = n - Next[n];

	for (int i = 0; i < 26; i++)

		printf("%lld%c", Calc(R, i) - Calc(L - 1, i), i == 25 ? '\n' : ' ');

#ifdef GLOBAL_DEBUG

	system("pause");

#endif

	return 0;

}