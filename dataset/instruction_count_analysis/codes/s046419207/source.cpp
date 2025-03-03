#include "stdc++.h"

using namespace std;



namespace TYC

{

	typedef long long ll;

	typedef pair<int, int> pii;

	const int N = 1e5 + 5;



	int n, A[N], B[N], P[N];

	map<int, int> idA, idB;



	inline int read()

	{

		int x = 0, f = 0, ch = getchar();

		while (!isdigit(ch))

			f |= (ch == '-'), ch = getchar();

		while (isdigit(ch))

			x = x * 10 + ch - '0', ch = getchar();

		return f ? -x : x;

	}



	inline void End(const int t)

	{

		puts(t ? "Yes" : "No");

		exit(0);

	}



	void work()

	{

		n = read();

		for (int i = 1; i <= n; i++)

			A[i] = read(), idA[A[i]] = i;

		for (int i = 1; i <= n; i++)

			B[i] = read(), idB[B[i]] = i;

		sort(A + 1, A + 1 + n);

		sort(B + 1, B + 1 + n);

		for (int i = 1; i <= n; i++)

			if (A[i] > B[i])

				End(0);

		for (int i = 1; i < n; i++)

			if (A[i] == A[i + 1] || B[i] == B[i + 1])

				End(1);

		for (int i = 1; i <= n; i++)

			if (i < n && A[i + 1] <= B[i])

				End(1);

			else

				P[idA[A[i]]] = idB[B[i]];

		int c = 1, u = P[1];

		while (u != 1)

			c++, u = P[u];

		End(c != n);

	}

}



int main()

{

	TYC::work();

	return 0;

}