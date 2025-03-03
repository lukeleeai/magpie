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

ll n,k,c,nxt[N],pre[N],tms[N];

string s;

vector<ll> wk,r1,r2;

int main(){

	ll i,j;

	cin>>n>>k>>c>>s;

	for(i=0;i<s.size();i++)

	{

		if(s[i]=='o')

		{

			wk.push_back(i);

		}

	}

	memset(tms,0,sizeof(tms));

	for(i=wk.size()-1;i>=0;i--)

	{

		j=lower_bound(wk.begin(),wk.end(),wk[i]+c+1)-wk.begin();

		nxt[i]=j;

	}

	for(i=0;i<wk.size();i++)

	{

		j=upper_bound(wk.begin(),wk.end(),wk[i]-c-1)-wk.begin()-1;

		pre[i]=j;

	}

	i=0;

	while(i<wk.size())

	{

		r1.push_back(i);

		i=nxt[i]; 

	}

	i=wk.size()-1;

	while(i>=0)

	{

		r2.push_back(i);

		i=pre[i];

	}

	sort(r1.begin(),r1.end());

	sort(r2.begin(),r2.end());

	if(r1.size()>k||r2.size()>k)

	{

		return 0;

	}

	for(i=0;i<r1.size();i++)

	{

		tms[r1[i]]++;

	}

	for(i=0;i<r2.size();i++)

	{

		tms[r2[i]]++;

	}

	for(i=0;i<wk.size();i++)

	{

		if(tms[i]==2)

		{

			cout<<wk[i]+1<<endl;

		}

	}

	return 0;

}