#include<iostream>

#include<algorithm>

using namespace std;



int dp[330];

int s,d,m;

int k[110],w[110][55],p[110][55],f[110];



int main(){

  

  while(cin >> s >> d >> m){

    for(int i=0;i<s;i++){

      cin >> k[i];

      for(int j=0;j<k[i];j++)cin >> w[i][j] >> p[i][j];

    }

    for(int i=0;i<d;i++)cin >> f[i];



    for(int i=0;i<=m;i++)dp[i] = -1;

    

    dp[0] = 0;



    for(int i=0;i<d;i++){

      for(int x=0;x<k[f[i]];x++){

	int v = p[f[i]][x], c = w[f[i]][x];

	for(int j=m-v;j>=0;j--){

	  if(dp[j]>=0)dp[j+v] = max(dp[j+v],dp[j]+c);

	}

      }

    }

	

    int ans = 0;

    for(int i=1;i<=m;i++)

      if(dp[i] > dp[ans])ans = i;

    cout << dp[ans] << " " << ans << endl;

  }

}