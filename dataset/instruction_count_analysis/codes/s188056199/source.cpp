#include"stdc++.h"

using namespace std;



int main(){

  int n,w[300],maxx[301][301],dp[301][301];

  cin>>n;

  while(n!=0){

    for(int i=0;i<n;i++)

      for(int j=0;j<n;j++){

        dp[i][j]=0;

        maxx[i][j]=0;

      }

    for(int i=0;i<n;i++)

      cin>>w[i];

    for(int i=0;i<n-1;i++)

      if(w[i]-w[i+1]>=-1&&w[i]-w[i+1]<=1)

        dp[i][i+1]=1;

    for(int k=2;k<=n;k++)

      for(int i=0;i+k<n;i++){

        if(dp[i+1][i+k-1]==1&&w[i]-w[i+k]>=-1&&w[i]-w[i+k]<=1)

          dp[i][i+k]=1;

        else

          for(int j=i+1;j<i+k-1;j++)

            if(dp[i][j]==1&&dp[j+1][i+k]==1){

              dp[i][i+k]=1;

              break;

            }

        

      }

    

    for(int k=1;k<n;k++)

      for(int i=0;i+k<n;i++){

        if(dp[i][i+k]==1)

          maxx[i][i+k]=k+1;

        else

          for(int j=i;j<i+k;j++)

            if(maxx[i][i+k]<maxx[i][j]+maxx[j+1][i+k])

              maxx[i][i+k]=maxx[i][j]+maxx[j+1][i+k];

      }

    cout << maxx[0][n-1]<<endl;

    cin>>n;

  }

}
