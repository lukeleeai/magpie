#include<iostream>

#include<algorithm>

#include<vector>

#include<queue>

#include<iomanip>

using namespace std;

typedef long long ll;

typedef long double ld;

typedef pair<ld,ll> P;

vector<ll> node[605],dnode[605];

ll edge_size[605]={0};

vector<P> cos[605];

bool used[605];

ld first_solve(ll n){

  vector<ld> dist(605,0);

  for(int pos=n;pos>=1;pos--){

    for(int i=0;i<node[pos].size();i++){

      ll to=node[pos][i];

      ld now_cos=dist[pos]+1;

      now_cos/=(ld)edge_size[to];

      cos[to].push_back(P(now_cos,pos));

      dist[to]+=now_cos;

    }

  }

  return dist[1];

}

ld second_solve(ll n){

  vector<ld> dist(605,0);

  for(int pos=n;pos>=1;pos--){

    for(int i=0;i<node[pos].size();i++){

      ll to=node[pos][i];

      if(to==-1) continue;

      ld now_cos=dist[pos]+1;

      now_cos/=(ld)edge_size[to];

      dist[to]+=now_cos;

    }

  }

  return dist[1];

}

void dfs(ll pos){

  used[pos]=true;

  for(int i=0;i<dnode[pos].size();i++){

    ll to=dnode[pos][i];

    if(to==-1) continue;

    if(!used[to]){

      used[to]=true;

      dfs(to);

    }

  }

}

int main(){

  ll n,m;

  cin>>n>>m;

  for(int i=0;i<m;i++){

    ll s,t;

    cin>>s>>t;

    node[t].push_back(s);

    dnode[s].push_back(t);

    edge_size[s]++;

  }

  ld ans=first_solve(n);

  for(int i=1;i<=n;i++) used[i]=false;

  dfs(1);

  cout<<fixed;

  for(int i=1;i<n;i++){

    sort(cos[i].rbegin(),cos[i].rend());

    ll cut_edge=cos[i][0].second;

    if(used[i]&&edge_size[i]==1) continue;

    for(int j=0;j<node[cut_edge].size();j++){

      if(node[cut_edge][j]==i){

        node[cut_edge][j]=-1;

        edge_size[i]--;

        ans=min(ans,second_solve(n));

        node[cut_edge][j]=i;

        edge_size[i]++;

      }

    }

  }

  cout<<setprecision(10)<<ans<<endl;

}
