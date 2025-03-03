#include <cstdio>

#include <vector>

#include <algorithm>

#include <cmath>

#include <numeric>

#include <set>

#include <map>

#include <stack>

#include <queue>

#include <time.h>

#include <list>

#include <bitset>

#include <iostream>



using namespace std;

typedef long long ll;

#define rep(i,n) for(int i=0;i<(n);++i)

#define INF 2147483600

const int V=200010;

using P=pair<int,int>;

vector<P> G[V];

int dist[V];

bool used[V];

void dijkstra(int s){

  fill_n(dist,V,INF);

  fill_n(used,V,false);

  priority_queue<P,vector<P>,greater<P>> q;

  q.push(P(0,s));

  while(!q.empty()){

    int d; int t;

    tie(d,t)=q.top();q.pop();

    if(used[t])continue;

    used[t]=true;dist[t]=d;

    for(P e: G[t]){

      if(dist[e.second]<=d+e.first)continue;

      q.push(P(d+e.first,e.second));

    }

  }

}



inline ll read(){

  ll ans=0,c=getchar_unlocked();

  while(c<'0'||c>'9')c=getchar_unlocked();

  while(c>='0'&&c<='9'){ans=ans*10+(c-'0'); c=getchar_unlocked();}

  return ans;

}

int main(){

  ll n,m,a,b;

  n=read();m=read();

  rep(i,m){

    a=read();b=read();

    G[a].emplace_back(1,b);

    G[b].emplace_back(1,a);

  }

  dijkstra(1);

  if(dist[n]<=2){

    printf("POSSIBLE\n");

  }else{

    printf("IMPOSSIBLE\n");

  }

  return 0;

}