// In the name of God



#include"stdc++.h"



#define F first

#define S second

#define PB push_back

#define sz(s) int((s).size())

#define bit(n,k) (((n)>>(k))&1)



using namespace std;



typedef long long ll;

typedef pair<int,int> pii;

typedef pair<ll,ll> pll;



const int maxn=1e5+10,mod=1e9+7;

const ll inf=1e18;



int a[maxn],b[maxn],dp[maxn],sm[maxn],tot;

map<int,vector<pii> >mp;

vector<int>v;

set<pii>s;



void add(int id,int num){

    tot=(tot+num)%mod;

    while(id<maxn){

	sm[id]=(sm[id]+num)%mod;

	id+=(id & -id);

    }

}

int ask(int id){

    int ans=0;

    while(id>0){

	ans=(ans+sm[id])%mod;

	id-=(id & -id);

    }

    return ans;

}



int main(){

    int n,m;cin>>n>>m;

    for(int i=0;i<n;i++)

	cin>>a[i];

    for(int i=0;i<m;i++)

	cin>>b[i];

    for(int i=0;i<n;i++){

	if(a[i]<b[0] || b[m-1]<a[i])continue;

	int id=upper_bound(b,b+m,a[i])-b;

	int A=a[i]-b[id-1],B=b[id]-a[i];

	if(s.count({A,B})) continue;

	s.insert({A,B});

	mp[A].PB({B,i});

	v.PB(B);

    }

    mp[-1].PB({-1,n});

    v.PB(-1);

    sort(v.begin(),v.end());

    v.resize(unique(v.begin(),v.end())-v.begin());

    tot=1;

    for(auto it=mp.rbegin();it!=mp.rend();it++){

	vector<pii>&vec=it->S;

	for(pii p:vec){

	    p.F=lower_bound(v.begin(),v.end(),p.F)-v.begin()+1;

	    dp[p.S]=(tot-ask(p.F))%mod;

	}

	for(pii p:vec){

	    p.F=lower_bound(v.begin(),v.end(),p.F)-v.begin()+1;

	    add(p.F,dp[p.S]);

	}

    }

    if(dp[n]<0) dp[n]+=mod;

    cout<<dp[n]<<endl;

    return 0;

}
