#include<iostream>

#include<string>

#include<algorithm>

#include<vector>

#include<iomanip>

#include<math.h>

#include<complex>

#include<queue>

#include<deque>

#include<map>

#include<set>

#include<bitset>

using namespace std;

#define REP(i,m,n) for(int i=(int)m ; i < (int) n ; i++ )

#define rep(i,n) REP(i,0,n)

typedef long long ll;

typedef pair<int,int> pint;

typedef pair<ll,int> pli;

const int inf=1e9+7;

const ll longinf=1LL<<60 ;

const ll mod=1e9+7 ;

int dx[4]={1,0,-1,0} , dy[4]={0,1,0,-1} ;

typedef vector<vector<pli>> wgraph;



vector<ll> bfs(wgraph v,int x){

    priority_queue<pli,vector<pli>,greater<pli>> q;

    vector<ll> dist(v.size(),longinf);

    dist[x]=0;

    q.push({0LL,x});

    while(q.size()){

        pli p=q.top();q.pop();

        ll d=p.first,now=p.second;

        if(dist[now]<d)continue;

        for(auto to:v[now]){

            if(dist[to.second]>d+to.first){

                dist[to.second]=d+to.first;

                q.push({dist[to.second],to.second});

            }

        }

    }

    return dist;

}

int main(){

    int n,m,s,t;

    cin>>n>>m>>s>>t;

    s--;t--;

    wgraph v1(n),v2(n);  

    rep(i,m){

        int x,y,z1,z2;

        scanf("%d %d %d %d",&x,&y,&z1,&z2);

        x--;y--;

        v1[x].push_back({z1,y});

        v1[y].push_back({z1,x});

        v2[x].push_back({z2,y});

        v2[y].push_back({z2,x});

    }

    vector<ll> dist1=bfs(v1,s);

    vector<ll> dist2=bfs(v2,t);

    vector<ll> ans(n);

    rep(i,n)ans[i]=1e15-dist1[i]-dist2[i];

    rep(i,n-1)ans[n-i-2]=max(ans[n-i-2],ans[n-i-1]);

    rep(i,n)printf("%lld\n",ans[i]);

   return 0;

}