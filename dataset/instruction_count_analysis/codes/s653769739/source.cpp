#include<iostream>

#include<algorithm>

#include<string>

#include<cstring>

using namespace std;



int main()

{

	int n, i,j,temp,way[101];

	cin >> n;

	int f[101][10];

	long long p[101][11],ans,re;

	for (i = 0; i < n; i++)

		for (j = 0; j < 10; j++)

			cin >> f[i][j];

	for (i = 0; i < n; i++)

		for (j = 0; j < 11; j++)

			cin >> p[i][j];

	for (int t = 1023; t ; t--)

	{

		re = 0;

		temp = t;

		memset(way, 0, sizeof(way));

		for (i = 0; i < 10; i++)

		{

			if (temp & 1)

			{

				for (j = 0; j < n; j++)

				{

					if (f[j][i])

						way[j]+=1;

				}

			}

			temp>>=1;

		}

		for (i = 0; i < n; i++)

			re += p[i][way[i]];

		if (t == 1023)

			ans = re;

		else

			if (re > ans)

				ans = re;

	}

	cout << ans << endl;

}