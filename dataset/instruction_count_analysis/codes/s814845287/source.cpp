#include"stdc++.h"

using namespace std;

typedef long long ll;

typedef long double ld;

#define rep(i, n) for (ll i = 0; i < n; i++)

#define FOR(i, a, b) for (ll i = a; i < b; i++)

#define len(v) ll(v.size())



template <class T>

void cout_vec(const vector<T> &vec){

  for(auto itr:vec) cout<<itr<<' ';

  cout<<'\n';

}



typedef pair<ll,ll> P;

const ll mod=1e9+7;



int main(){

    cin.tie(0);

    ios::sync_with_stdio(false);

    int h,w;

    cin>>h>>w;

    char a[h+1][w+1];

    int dx[4]={1,-1,0,0};

    int dy[4]={0,0,1,-1};

    queue<P> que;

    ll dist[h+1][w+1];

    ll inf=1e15;

    rep(i,h+1)rep(j,w+1) dist[i][j]=inf;

    FOR(i,1,h+1)FOR(j,1,w+1){

      cin>>a[i][j];

      if(a[i][j]=='#'){

        que.push(P(i,j));

        dist[i][j]=0;

      }

    }

    while(!que.empty()){

      P v=que.front();

      que.pop();

      rep(i,4){

        int nx=v.first+dx[i];

        int ny=v.second+dy[i];

        if(1<=nx && nx<=h && 1<=ny && ny<=w){

          if(dist[nx][ny]==inf){

            dist[nx][ny]=dist[v.first][v.second]+1;

            que.push(P(nx,ny));

          }

        }

      }

    }

    ll ans=0;

    FOR(i,1,h+1)FOR(j,1,w+1) ans=max(ans,dist[i][j]);

    cout<<ans<<endl;

}