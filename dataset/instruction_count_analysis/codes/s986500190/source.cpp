#include "stdc++.h"

#define syosu(x) fixed<<setprecision(x)

using namespace std;

typedef long long ll;

typedef unsigned long long ull;

typedef pair<int,int> P;

typedef pair<double,double> pdd;

typedef pair<ll,ll> pll;

typedef vector<int> vi;

typedef vector<vi> vvi;

typedef vector<double> vd;

typedef vector<vd> vvd;

typedef vector<ll> vl;

typedef vector<vl> vvl;

typedef vector<string> vs;

typedef vector<P> vp;

typedef vector<vp> vvp;

typedef vector<pll> vpll;

typedef pair<int,P> pip;

typedef vector<pip> vip;

const int inf=1<<30;

const ll INF=1ll<<60;

const double pi=acos(-1);

const double eps=1e-8;

const ll mod=1e9+7;

const int dx[4]={-1,0,1,0},dy[4]={0,-1,0,1};



ll Pow(ll n,ll p){

	ll r=1;

	for(;p>0;p>>=1){

		if(p&1) r=(r*n)%mod;

		n=(n*n)%mod;

	}

	return r;

}



const int M=100005;

ll F[M];



void Init(){

	F[0]=1;

	for(int i=1;i<M;i++) F[i]=F[i-1]*i%mod;

}



ll Div(ll n,ll m){

	return n*Pow(m,mod-2)%mod;

}



int n;

vvi g;

vvl dp;



ll f(int x){

	return Div(F[x],Pow(2,x/2)*F[x/2]%mod);

}



int dfs(int v,int p){

	int S=1,B=0;

	vl DP;

	for(auto u:g[v]) if(u!=p){

		int N=dfs(u,v);

		S+=N;

		vl DP_(S+1);

		if(!B){

			for(int i=1;i<=N;i++){

				DP_[i+1]=dp[u][i]%mod;

				if(i%2==0) (DP_[1]+=dp[u][i]*f(i)%mod*(mod-1))%=mod;

			}

			B=1;

		}

		else{

			for(int i=1;i<=S-N;i++) for(int j=1;j<=N;j++){

				(DP_[i+j]+=DP[i]*dp[u][j])%=mod;

				if(j%2==0) (DP_[i]+=DP[i]*dp[u][j]%mod*f(j)%mod*(mod-1))%=mod;

			}

		}

		DP=DP_;

	}

	if(S==1){

		DP=vl(2);

		DP[1]++;

	}

	dp[v]=DP;

	return S;

}



int main(){

	Init();

	cin>>n;

	g=vvi(n);

	dp=vvl(n,vl(n+1));

	for(int i=1;i<n;i++){

		int u,v;

		cin>>u>>v;

		u--;v--;

		g[u].push_back(v);

		g[v].push_back(u);

	}

	dfs(0,-1);

	ll res=0;

	for(int i=2;i<=n;i++) if(i%2==0) (res+=dp[0][i]*f(i))%=mod;

	cout<<res<<endl;

}