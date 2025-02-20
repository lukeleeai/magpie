#include "stdc++.h"

#define PB push_back

#define MP make_pair

#define REP(i,n) for (int i=0;i<(n);i++)

#define FOR(i,a,b) for(int i=(a);i<(b);i++)

#define ALL(a) (a).begin(),(a).end()

using namespace std;

typedef pair<int,int> P;

typedef long long ll;

const int INF=1e9;

int dp[100100];

int main(){

  int m,n;

  cin>>m>>n;

  int c[550],e[550];

  vector<int>p(m);

  REP(i,100100)dp[i]=INF;

  REP(i,m)cin>>p[i];

  dp[0]=0;

  int sum=0;

  REP(i,n){

    cin>>c[i]>>e[i];

    for(int j=sum;j>=0;j--){

      dp[j+c[i]]=min(dp[j+c[i]],dp[j]+e[i]);

    }

    sum+=c[i];

    sum=min(sum,20000);

  }

  for(int i=sum;i>=0;i--){

    dp[i]=min(dp[i],dp[i+1]);

  }

  sort(ALL(p),greater<int>());

  sum=0;

  int ans=0;

  REP(i,m){

    sum+=p[i];

    ans=max(ans,sum-dp[i+1]);

  }

  cout<<ans<<endl;

}