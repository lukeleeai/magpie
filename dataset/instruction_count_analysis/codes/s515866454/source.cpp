#include"stdc++.h"

#define mod 1000000007

#define ll long long int

#define ar array

#define mp make_pair

using namespace std;



int main()

{

	ios::sync_with_stdio(false);

	cin.tie(NULL);

	int x;

	cin>>x;

	ll ans = 0, j= 0;

	ll a[int(1e5)];

	memset(a,0x3f,sizeof(a));

	a[0] = x;

	int i = 0;

	for(i = 1;i<x;i++)

	{

		ans = i*(i+1)/2;

		a[i] = i+(x-ans);

		if(ans>x)

		{

			a[i] = i;

			break;

		}

	}

	cout<<*min_element(a,a+int(1e5))<<endl;

	return 0;

}