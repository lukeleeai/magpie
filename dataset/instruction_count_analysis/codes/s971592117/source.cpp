#include<cstdio>

#include<cmath>

#include<cstring>

#include<cstdlib>

#include<algorithm>

#include<iostream>

#include<queue>

#include<string>

#include<map>

#include<set>

#include<stack>

#include<vector>

#define ll long long

#define mt(a) memset(a,0,sizeof(a))

#define MAXI 2000000000

#define PAI pair<int,int>



using namespace std;



ll  f[200009],w[200009],v[200009];

int main()

{

	int n, m,vv=0;

	scanf("%d%d", &n, &m);

	for (int i = 1; i <= n; i++)

	{

		scanf("%lld%lld", &w[i], &v[i]);

		vv += v[i];

	}

	for (int i = 1; i <= vv; i++)

		f[i] = MAXI;

	for (int i = 1; i <= n; i++)

	{

		for (int c = vv; c >= v[i]; c--)

		{

			f[c] = min(f[c], f[c - v[i]] + w[i]);

		}

	}

	ll maxx = -MAXI;

	for (int i = 0; i <= vv; i++)

		if (f[i] <= m) maxx = i;

	printf("%lld\n", maxx);

	return 0;

}