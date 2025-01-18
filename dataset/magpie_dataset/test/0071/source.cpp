#include "stdc++.h"

using namespace std;



int main () {

  int n,k;

  cin>>n>>k;

  int a[n];

  for (int i=0;i<n;i++) {

    cin>>a[i];

  }

  int dp[100101];

  long long p=100000000000;

  for (int i=0;i<100101;i++) {

    dp[i]=p;

  }

  dp[0]=0;

  if (n==2) {

    cout<<abs(a[1]-a[0])<<endl;

  }

  else {

    for (int i=0;i<n;i++) {

      for (int j=1;j<k+1;j++) {

        if (dp[i+j]>dp[i]+abs(a[i]-a[i+j])) {

          dp[i+j]=dp[i]+abs(a[i]-a[i+j]);

        }

      }

    }

    cout<<dp[n-1]<<endl;

  }

}