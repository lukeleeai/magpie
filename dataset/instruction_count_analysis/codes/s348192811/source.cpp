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

	for(int i = sqrt(x);i<=x;i++)

	{

		ll ans = i*(i+1)/2;

		if(ans>=x)

		{

			cout<<i<<endl;

			break;

		}

	}

	return 0;

}