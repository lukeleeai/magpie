//By Don4ick

#include "stdc++.h"



#define y2 dsfgs



const int N = (int)2005;



using namespace std;



int n, m, q, a[N][N], b[N][N], c[N][N];



int main()

{

	//freopen(".in", "r", stdin);

	//freopen(".out", "w", stdout);



	ios_base::sync_with_stdio(false);



	cin >> n >> m >> q;

	for (int i = 1; i <= n; i++)

	{

		string s;



		cin >> s;

		for (int j = 0; j < m; j++)

		{

			if (s[j] == '1')

				a[i][j + 1] = 1;

		}

	}

	for (int i = 1; i <= n; i++)

	{

		for (int j = 2; j <= m; j++)

		{

			b[i][j] += b[i][j - 1];

			if (a[i][j] == 1 && a[i][j - 1] == 1)

				b[i][j]++;			

		}

	}

	for (int i = 2; i <= n; i++)

	{

		for (int j = 1; j <= m; j++)

		{

			c[i][j] += c[i - 1][j];

			if (a[i][j] == 1 && a[i - 1][j] == 1)

				c[i][j]++;

		}		

	}

	for (int i = 1; i <= n; i++)

	{

		for (int j = 1; j <= m; j++)

		{

			a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];

		}

	}

	while(q--)

	{

		int x1, x2, y1, y2;

		cin >> x1 >> y1 >> x2 >> y2;

		int cnt = 0;

		for (int i = x1; i <= x2; i++)

		{

			cnt += b[i][y2] - b[i][y1];

		}

		for (int i = y1; i <= y2; i++)

		{

			cnt += c[x2][i] - c[x1][i];

		}

		cout << a[x2][y2] - a[x1 - 1][y2] - a[x2][y1 - 1] + a[x1 - 1][y1 - 1] - cnt << endl;

	}

	return 0;

}


