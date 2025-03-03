#include "stdc++.h"

using namespace std;



namespace TYC

{

	const int N = 605;



	int n, vis[N][N], cnt[5];



	void solve(int D, const int type)

	{

		int tim = 0;

		while (!(D & 3))

			D /= 4, tim++;

		if (D & 1)

		{

			for (int i = 0; i < n; i++)

				for (int j = 0; j < n; j++)

					if (((i >> tim) + (j >> tim)) & 1)

						vis[i][j] += type;

		}

		else

		{

			for (int i = 0; i < n; i++)

				for (int j = 0; j < n; j++)

					if ((i >> tim) & 1)

						vis[i][j] += type;

		}

	}



	void work()

	{

		int d1, d2;

		scanf("%d%d%d", &n, &d1, &d2);

		n <<= 1;

		solve(d1, 1);

		solve(d2, 2);

		for (int i = 0; i < n; i++)

			for (int j = 0; j < n; j++)

				cnt[vis[i][j]]++;

		int mx = 0, id = -1;

		for (int i = 0; i < 4; i++)

			if (cnt[i] > mx)

				mx = cnt[i], id = i;

		for (int i = 0, res = (n >> 1) * (n >> 1); i < n; i++)

			for (int j = 0; j < n && res; j++)

				if (vis[i][j] == id)

				{

					printf("%d %d\n", i, j);

					res--;

				}

	}

}



int main()

{

	TYC::work();

	return 0;

}