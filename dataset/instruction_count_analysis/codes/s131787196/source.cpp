#include"stdc++.h"

#define ll long long

#define int ll

using namespace std;

ll c[55],f[250050],sz[55],fa[55];

struct node{

	ll cost,value,count;

	node(ll cost=0,ll value=0,ll count=0){this->cost=cost,this->value=value,this->count=count;}

	inline friend bool operator < (const node a,const node b){return a.cost*b.value<b.cost*a.value;}

}cs[555];

signed main(){

	ll n,x,d,ans=0;cin>>n>>x>>d;cin>>c[1];sz[1]=1;

	for(int i=2;i<=n;++i) cin>>c[i]>>fa[i],sz[i]=1;

	for(int i=n;i;--i) c[fa[i]]+=c[i],sz[fa[i]]+=sz[i];memset(f,0x3f,sizeof f);f[0]=0;

	for(int i=1;i<=n;++i){

		int T=min(n,d);if(i==1) T=n;

		for(int bit=1;bit<=T;T-=bit,bit<<=1) for(int j=n*n*n;j>=bit*sz[i];--j) f[j]=min(f[j],f[j-bit*sz[i]]+bit*c[i]);//bit>>=1;

		for(int j=n*n*n;j>=T*sz[i];--j) f[j]=min(f[j],f[j-T*sz[i]]+T*c[i]);

		if(i==1) cs[i]=node(c[i],sz[i],1e9);

		else cs[i]=node(c[i],sz[i],max(0ll,d-n));

	}

	sort(cs+1,cs+n+1);

	for(int has=0;has<=n*n*n;++has)if(f[has]<=x){

		int las=x-f[has],res=has;

		for(int i=1;i<=n;++i){

			int now=min(cs[i].count,las/cs[i].cost);

			res+=now*cs[i].value;las-=now*cs[i].cost;

		}

		ans=max(ans,res);

	}

	cout<<ans<<endl;

	return 0;

}