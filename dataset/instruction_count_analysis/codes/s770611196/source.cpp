#include "stdc++.h"

using namespace std;

const int N = 2e5+20;

long long v[N], c[51][51];

void init()

{

	memset(c, 0, sizeof(c));

	c[0][0] = 1;

	for (int i = 1; i <= 50; i++)

	{

		c[i][0] = 1;

		for (int j = 1; j <= i; j++)

			c[i][j] = c[i - 1][j - 1] + c[i - 1][j];

	}

}

int main()

{

	int n, a, b;

	init();

	cin >> n >> a >> b;

		double ave;

		for (int i = 0; i < n; i++)

			cin >> v[i];

		sort(v, v + n);

		reverse(v, v + n);

		for (int i = 0; i < a; i++) 

			ave += v[i];

		ave /= a;

		int num = 0, k = 0;

		for (int i = 0; i < n; i++)

		{

			if (v[i] == v[a - 1])

			{

				num++;

				if (i < a) k++;

			}

		}	

		long long ans = 0; 

		if (k == a)

		{

			for (int i = a; i <= b; i++)

				ans += c[num][i];

		}

		else ans += c[num][k];

        cout.precision(20);

 		cout << fixed << ave << endl << ans;

}
