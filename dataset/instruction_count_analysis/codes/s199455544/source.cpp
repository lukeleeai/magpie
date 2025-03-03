//       Author: Mostafa Mounir Shehab

 

#include "stdc++.h"

using namespace std;

 

#define PI  acos(-1)

#define EPS (1e-10)

#define endl "\n"

#define SZ(v) (int)(v.size())

#define IO ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL), cerr.tie(NULL);

typedef long long ll;

typedef long double ld;

 



 

ll MOD=1e9 + 7;

ll OO=1e15;

const int N=1e5 + 5,M=1e5 + 5;

int arr[N];

ll dp[N][3];





int n,m,k,cnt,SU,idx,len,MN,MX,T;

int l,r,mid;

int a,b,c;

int ans;



vector<int> adj[N];



ll Solve(int u,int p,bool color){

	

	ll &ret = dp[u][color];

	if(~ret)

		return ret;

	ret = 1;

	

	for(int i:adj[u]){

		if(i == p) continue;

		

		ll val = Solve(i,u,true);

		if(color)

			val += Solve(i,u,false);

		

		ret*=val;

		ret%=MOD;

	}



	return ret;

}









int main(){

	IO

	

	memset(dp,-1,sizeof dp);

	

	cin>>n;

	for(int i=1;i<n;++i){

		cin>>a>>b;

		adj[a].push_back(b);

		adj[b].push_back(a);

	}

	

	ll val = Solve(1,-1,0)+Solve(1,-1,1);

	val%= MOD;

	

	

	cout<<val<<endl;

	

	

}
