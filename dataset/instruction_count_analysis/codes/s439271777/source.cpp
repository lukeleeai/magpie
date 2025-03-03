//By Don4ick 

//#define _GLIBCXX_DEBUG



#include "stdc++.h"



typedef long long ll;

typedef long double ld;

typedef unsigned int ui;



#define forn(i, n) for (int i = 1; i <= n; i++)

#define pb push_back

#define all(x) x.begin(), x.end()

#define y1 qewr1234



const double PI = acos(-1.0);

const int DIR = 4;

const int X[] = {1, 0, -1, 0};

const int Y[] = {0, 1, 0, -1};



const int N = 805;



using namespace std;



int n, m, k, dp[N][N], nw[N][N];

string s[N];

bool used[N][N];



bool good(int x, int y)

{

	return x >= 0 && x < n && y >= 0 && y < m;

}



int main()

{

	ios_base::sync_with_stdio(false);

	cin.tie();

	cout.tie();		



	//freopen(".in", "r", stdin);

	//freopen(".out", "w", stdout);



	//~read

	cin >> n >> m >> k;

	for (int i = 0; i < n; i++)

		cin >> s[i];

	//~solve

	memset(dp, -1, sizeof(dp));

	memset(nw, -1, sizeof(nw));

	int x1 = -1, y1 = -1;

	for (int i = 0; i < n; i++)

	{

		for (int j = 0; j < m; j++)

		{

			if (s[i][j] == 'S')

			{

				x1 = i, y1 = j;

				s[i][j] = '.';

			}

		}

	}

	dp[x1][y1] = 0;

	int d = 0;

	vector < pair < int, int > > v;

	v.pb({x1, y1});

	used[x1][y1] = true;

	while(true)

	{

		vector < pair < int, int > > t;

		for (auto it : v)

		{

			int i = it.first, j = it.second; 

			if (dp[i][j] == -1)

				continue;

			if (i == 0 || j == 0 || i == n - 1 || j == m - 1)

			{

				cout << (d + k - 1) / k << endl;

				return 0;

			}

			for (int dir = 0; dir < DIR; dir++)

			{

				int tx = i + X[dir];

				int ty = j + Y[dir];

				if (good(tx, ty)  && dp[i][j] >= bool(s[tx][ty] == '#'))

				{

					int ndp = dp[i][j] - bool(s[tx][ty] == '#') + k * bool((d + 1) % k == 0);

					if (!used[tx][ty])

						t.pb({tx, ty}), used[tx][ty] = true;

					nw[tx][ty] = max(nw[tx][ty], ndp);

				}

			}

			nw[i][j] = max(nw[i][j], dp[i][j] + bool((d + 1) % k == 0) * k);   

		}

		for (auto it : t)

			v.pb(it);

		for (auto it : v)

		{

			int i = it.first, j = it.second;

			dp[i][j] = nw[i][j];

			nw[i][j] = -1;

		}

		d++;

	}



	return 0;

}


