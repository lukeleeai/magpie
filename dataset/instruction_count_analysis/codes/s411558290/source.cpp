#pragma GCC optimize("Ofast,unroll-loops")

#include"stdc++.h"

#define ll long long

#define F first

#define S second

#define P pair

#define FOR(i,a,b) for(int i=a;i<=b;i++)

#define rep(i,a,b) for(int i=a;i<b;i++) 

#define V vector

#define RE return

#define ALL(a) a.begin(),a.end()

#define MP make_pair

#define PB push_back

#define PF push_front

#define FILL(a,b) memset(a,b,sizeof(a))

using namespace std;

int c[16],n,v[200005],dp[1<<16];

int dfs(int x){

	if(dp[x]!=-1)RE dp[x];

	int re=1000000000;

	rep(i,1,16){

		if(x&(1<<i)){

			rep(j,i+1,16){

				if(x&(1<<j)){

					re=min(re,dfs(x^(1<<i)^(1<<j)^(1<<(i^j)))+((x&(1<<(i^j)))?2:1));

				}

			}

			break;

		}

	}

	RE dp[x]=re;

}

int main(){

	ios::sync_with_stdio(0);

    cin.tie(0);

	cin>>n;

	int x,y,z;

	rep(i,1,n){

		cin>>x>>y>>z;

		v[x]^=z;v[y]^=z;

	}

	int ans=0;

	rep(i,0,n){

		c[v[i]]++;

	}

	FOR(i,1,15){

		ans+=c[i]/2;

		c[i]&=1;

	}

	int get=0;

	FILL(dp,-1);dp[0]=0;

	FOR(i,1,15)if(c[i])get^=(1<<i);

	cout<<dfs(get)+ans;

	RE 0;

}




