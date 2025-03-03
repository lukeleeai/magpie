#include <cstdio>

#include <cstring>

#include <cstdlib>

#include <queue>

#include <cmath>

#include <iostream>

#include <algorithm>

#define mt(a) memset(a,0,sizeof(a))

#define ll long long

using namespace std;

int main(void)

{

	int n,c,k;

	int p[200005];

	mt(p);

	cin>>n>>c>>k;

	for(int i=1;i<=n;i++)

		cin>>p[i];

	sort(p+1,p+1+n);

	ll ans = 1;

	int t = 1;

	int sum = 1;

	for(int i=2;i<=n;i++)

	{

		if(p[i]<=p[t]+k&&sum<c)

		{

			sum++;

		}

		else

		{

			sum = 1;

			ans++;

			t = i;

		}		

	}

	cout<<ans<<endl;

	return 0;

}