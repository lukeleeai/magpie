#include"stdc++.h"

using namespace std;

typedef long long ll;

typedef long double ld;

typedef pair<ld,ll> P;

bool node[605][605]={0};

ll edge_num[605]={0};

ld dp[605]={0};

priority_queue<P> pque[605];

ld solve(ll n){

  ld kdp[605]={0};

  bool used[605];

  for(int i=n;i>=1;i--) used[i]=false;

  used[n]=true;

  for(int i=n;i>1;i--){

    for(int j=1;j<=n;j++){

      if(node[j][i]){

        if(!used[i]) return 17441744;

        ld cos=(kdp[i]+(ld)(1))/(ld)edge_num[j];

        kdp[j]+=cos;

        used[j]=true;

      }

    }

  }

  return (used[1]?kdp[1]:17441744);

}

int main(){

  ll n,m;

  cin>>n>>m;

  for(int i=0;i<605;i++){

    for(int j=0;j<605;j++) node[i][j]=false;

  }

  for(int i=0;i<m;i++){

    ll a,b;

    cin>>a>>b;

    node[a][b]=true;

    edge_num[a]++;

  }

  bool used[605];

  for(int i=1;i<=n;i++) used[i]=false;

  used[n]=true;

  for(int i=n;i>1;i--){

    for(int j=1;j<=n;j++){

      if(node[j][i]&&used[i]){

        ld cos=(dp[i]+(ld)(1))/(ld)edge_num[j];

        pque[j].push(P(cos,i));

        dp[j]+=cos;

        used[j]=true;

      }

    }

  }

  ld ans=dp[1];

  for(int i=1;i<=n;i++){

    if(pque[i].empty()) continue;

    P p=pque[i].top();

    ll break_edge=p.second;

    edge_num[i]--;



    node[i][break_edge]=false;

    ld kans=solve(n);

    ans=min(ans,kans);

    node[i][break_edge]=true;

    edge_num[i]++;

  }

  cout<<fixed;

  cout<<setprecision(10)<<ans<<endl;

}
