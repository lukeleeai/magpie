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

typedef pair<ll,int> pint;

const int inf=1e9+7;

const ll longinf=1LL<<60 ;

const ll mod=1e9+7 ;

int dx[4]={1,0,-1,0} , dy[4]={0,1,0,-1} ;



int n,m;

vector<pint> v[2][101010];

ll a[2][101010],dist[2][101010];



void bfs(int x,int flag){

    priority_queue<pint,vector<pint>,greater<pint>> q;

    dist[flag][x]=0;

    q.push({0LL,x});

    while(q.size()){

        pint p=q.top();q.pop();

        ll d=p.first,now=p.second;

        if(dist[flag][now]<d)continue;

        for(auto to:v[flag][now]){

            if(dist[flag][to.second]>dist[flag][now]+to.first){

                dist[flag][to.second]=dist[flag][now]+to.first;

                q.push({dist[flag][to.second],to.second});

            }

        }

    }

}



int main(){

    cin>>n>>m;

    int s,t;

    cin>>s>>t;

    rep(i,m){

        int x,y;

        cin>>x>>y;

        ll a,b;

        cin>>a>>b;

        x--;y--;

        v[0][x].push_back({a,y});

        v[1][x].push_back({b,y});

        v[0][y].push_back({a,x});

        v[1][y].push_back({b,x});

    }

    rep(i,n)rep(j,2)dist[j][i]=longinf;

    bfs(s-1,0);

    bfs(t-1,1);

    ll ans[n];

    rep(i,n)ans[i]=dist[0][i]+dist[1][i];

    rep(i,n-1)ans[n-i-2]=min(ans[n-i-1],ans[n-i-2]);

    rep(i,n)cout<<(ll)1e15-ans[i]<<endl;

    return 0;

}
