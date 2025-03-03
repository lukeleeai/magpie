/***********************

*  Author: xuziyuan    * 

***********************/



#include "stdc++.h"



#define rt0 return 0

#define rep(i,n) for(LL i=0;i<n;i++)

#define repn(i,n) for(LL i=1;i<=n;i++)

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



LL n,k,t[100010],d[100010],ans=0,have=0,rans=0;

bool vis[100010];

vector <pii> v,swp;

vector <LL> ks[100010],all[100010],canbe;



bool cmp(pii a,pii b)

{

	return a.fi>b.fi;

}



bool cmp2(LL a,LL b)

{

	return a>b;

}



int main()

{

	cin>>n>>k;

	rep(i,n)

	{

		cin>>t[i]>>d[i];

		v.pb({d[i],t[i]});

		all[t[i]].pb(d[i]);

	}

	sort(v.begin(),v.end(),cmp);

	rep(i,k) ks[v[i].se].pb(v[i].fi),ans+=v[i].fi;

	//cout<<ans<<endl;

	repn(i,n) sort(ks[i].begin(),ks[i].end()),sort(all[i].begin(),all[i].end(),cmp2);

	repn(i,n)

	{

		//cout<<i<<' '<<ks[i].size()<<endl;

		if(ks[i].size()==0)

		{

			if(all[i].size()>0) swp.pb({all[i][0],i});

			continue;

		}

		have++;

		//cout<<i<<endl;

		if(ks[i].size()>0) for(LL j=0;j<ks[i].size()-1;j++) canbe.pb(ks[i][j]);//,cout<<ks[i][j]<<endl;

		//cout<<'p'<<endl;

	}

	sort(canbe.begin(),canbe.end());

	sort(swp.begin(),swp.end());

	reverse(swp.begin(),swp.end());

	LL use=0;

	rans=ans+sqr(have);

	rep(i,swp.size())

	{

		if(use>=canbe.size()) break;

		have++;

		ans=ans-canbe[use++]+swp[i].fi;

		rans=max(rans,ans+sqr(have));

		//cout<<ans<<' '<<have<<' '<<canbe[use-1]<<' '<<swp[i].fi<<endl;

	}

	cout<<rans<<endl;

	rt0;

}