#include <iostream>

#include "stdc++.h"

#define pb push_back

#define ob pop_back

#define xx first

#define yy second

#define dob double

#define rin(i,n,k) for(int i=0;i<n;i+=k)

#define int long long int

#define ss size()

using namespace std;

const int M=1e9+7,maxn=100010;

std::vector<int> adj[maxn];

std::vector<int> v1;

int ans,n,k,m,x,y,q,par[maxn],h[maxn],mach[maxn],sk[maxn],dp[maxn];

bool mark[maxn],bpart[maxn];

string s,s1,s2;

map <string ,int> mp;

bool markchaild[maxn];

bool dfsmach(int v){

    if(v==-1) return true;

    if(mark[v]==1) return false;

    mark[v]=1;

    for(int i=0;i<adj[v].ss;i++){

        int u=adj[v][i];

        if(dfsmach(mach[u])){

            bpart[u]=((bpart[v]+1)%2);

            mach[u]=v;

            mach[v]=u;

            return true;

        }

    }

    return false;

}





int32_t main() {

    cin>>n>>m>>k;

    if(n<=k&&m>=k)

        cout<<"Yes";

    else

        cout<<"No";

    return 0;

}
