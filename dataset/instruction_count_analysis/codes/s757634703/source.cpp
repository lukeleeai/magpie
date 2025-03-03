#include<cmath>

#include<cstdio>

#include<cstring>

#include<iostream>

#include<algorithm>

using namespace std;

int n, m, a[105], sum = 0;

int main()

{

	cin >> n;

	for (int i = 1; i <= n; i++)

	{

		cin >> a[i];

		sum += a[i];

	}

	cin >> m;

	while (m--)

	{

		int p, x;

		cin >> p >> x;

		cout << sum - a[p] + x << endl;

	}

	return 0;

}