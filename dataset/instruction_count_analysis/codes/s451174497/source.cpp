#include"stdc++.h"

using namespace std;

typedef long long ll;

typedef long double ld;

#define rep(i, n) for (ll i = 0; i < n; i++)

#define FOR(i, a, b) for (ll i = a; i < b; i++)

#define is(a, b) a == b

#define len(v) ll(v.size())



const ll mod=1e9+7;



//vector書き出し

template <class T>

void cout_vec(const vector<T> &vec1){

  rep(i,len(vec1)){

    cout<<vec1[i]<<' ';

  }

  cout<<'\n';

}



typedef pair<ll,ll> P;



ll n;



struct edge{

    ll to,cost;

};

ll INF=1e15;

vector<edge> g[100010];

vector<ll> d(100010);

 

void dijkstra(ll x,vector<ll> &d,vector<bool> &vis){

    rep(i,len(d)){

        d[i]=INF;

    }

    priority_queue<P,vector<P>,greater<P>> que;

    d[x]=0;

    que.push(P(0,x));

    while(!que.empty()){

        P p=que.top();

        que.pop();

        ll v=p.second;

        if(d[v]<p.first||vis[v]){

            continue;

        }

        vis[v]=true;

        rep(i,len(g[v])){

            edge e=g[v][i];

            if(d[e.to]>d[v]+e.cost){

                d[e.to]=d[v]+e.cost;

                que.push(P(d[e.to],e.to));

            }

        }

    }

}



int main(){

    cin.tie(0);

    ios::sync_with_stdio(false);

    cin>>n;

    rep(i,n-1){

      ll a,b;

      cin>>a>>b;

      g[a].push_back({b,1});

      g[b].push_back({a,1});

    }

    vector<ll> d(100010),d2(100010);

    vector<bool> vis(100010,false),vis2(100010,false);

    dijkstra(1,d,vis);

    dijkstra(n,d2,vis2);

    ll c1=0,c2=0;

    FOR(i,1,n+1){

      if(d[i]<=d2[i]){

        c1++;

      }else{

        c2++;

      }

    }

    if(c1>c2){

      cout<<"Fennec"<<endl;

    }else{

      cout<<"Snuke"<<endl;

    }

    /*

    FOR(i,1,n+1){

      cout<<d[i]<<'\n';

    }

    cout<<'\n';

    FOR(i,1,n+1){

      cout<<d2[i]<<'\n';

    }

    cout<<'\n';

    */

}