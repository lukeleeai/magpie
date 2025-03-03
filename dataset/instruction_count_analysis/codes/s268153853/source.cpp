#include "stdc++.h"

#define INF 1000000000

#define LINF 1000000000000000000

#define MOD 1000000007

#define mod 1000007

#define INF63 1061109567

#define INF127 9187201950435737471

#define UINF 18446744073709551615

#define F first

#define S second

#define ll long long

#define N 200010

using namespace std;

ll n,k,c;

string s;

vector<ll> wk1,wk2;

int main(){

	ll i,j;

	cin>>n>>k>>c>>s;

	for(i=0;i<s.size();i++)

	{

		if(s[i]=='o')

		{

			wk1.push_back(i);

			i+=c;

		}

	}

	for(i=s.size()-1;i>=0;i--)

	{

		if(s[i]=='o')

		{

			wk2.push_back(i);

			i-=c;

		}

	}

	sort(wk1.begin(),wk1.end());

	sort(wk2.begin(),wk2.end());

	if(wk1.size()>k||wk2.size()>k||wk1.size()!=wk2.size())

	{

		return 0;

	}

	for(i=0;i<wk1.size();i++)

	{

		if(wk1[i]==wk2[i])

		{

			cout<<wk1[i]+1<<" ";

		}

	}

	puts("");

	return 0;

}