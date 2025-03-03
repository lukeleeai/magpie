/***********************

*  Author: xuziyuan    * 

***********************/



#include "stdc++.h"



#define rt0 return 0

#define rep(i,n) for(int i=0;i<n;i++)

#define repn(i,n) for(int i=1;i<=n;i++)

#define replet(c) for(char c='a';c<='z';c++)

#define LL long long

#define pii pair <LL,LL>

#define pb push_back

#define fi first

#define se second

#define mpr make_pair

#define sqr(a) ((a)*(a))



using namespace std;



const LL MOD=1e9+7;



LL n,k,ans=0,rans,pos,have=0;

vector <pii> v;

bool vis[100010];

priority_queue <LL,vector <LL>,greater <LL> > q;



bool cmp(pii a,pii b)

{

	return a.fi>b.fi;

}



int main()

{

	cin>>n>>k;

	rep(i,n)

	{

		LL t,d;

		cin>>t>>d;

		v.pb({d,t});

	}

	sort(v.begin(),v.end(),cmp);

	rep(i,n)

	{

		if(!vis[v[i].se])

		{

			vis[v[i].se]=true;

			ans+=v[i].fi;

			//cout<<v[i].fi<<endl;

			have++;

		}

		else ans+=v[i].fi,q.push(v[i].fi);

		if(i==k-1)

		{

			pos=i;

			break;

		}

	}

	rans=ans+sqr(have);

	for(int i=pos+1;i<n;i++)

	{

		if(q.empty()) break;

		if(vis[v[i].se]) continue;

		vis[v[i].se]=true;

		ans=ans-q.top()+v[i].fi;

		q.pop();

		have++;

		rans=max(rans,ans+sqr(have));

	}

	cout<<rans<<endl;

	rt0;

}