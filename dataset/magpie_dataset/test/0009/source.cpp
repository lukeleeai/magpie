#include"stdc++.h"

using namespace std;

#define ll long long



const ll INF= 1LL << 60;



//入力

ll N;

ll K;

ll h[100010];

//dp

ll dp[100010];





void chmin(ll& a, ll b){

  if(a>b){

    a=b;

  }

}



int main(){

  cin >> N >> K;

  for(int i=0;i<N;i++) cin >>h[i];

  for(int i=0;i<100010;i++) dp[i]=INF;

  

  dp[0]=0;

  

  for(int i=0;i<N;i++){

    for(int j=i+1;j<=i+K;j++){

      chmin(dp[j],dp[i]+abs(h[i]-h[j]));

      //cout<<i<<","<<j<<":"<<dp[j]<<endl;

    }

  }

  

  cout << dp[N-1] << endl; 

}