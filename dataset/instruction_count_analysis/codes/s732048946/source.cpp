#include <cstdio>

#include <cstring>

#include <iostream>

#include <string>

#include <cmath>

#include <bitset>

#include <vector>

#include <map>

#include <set>

#include <queue>

#include <deque>

#include <algorithm>

#include <complex>

#include <unordered_map>

#include <unordered_set>

#include <random>

#include <cassert>

#include <fstream>

#define popcount __builtin_popcount

using namespace std;

typedef long long ll;

typedef pair<int, int> P;

const ll MOD=1e9+7;

int main()

{

    string s; cin>>s;

    int c[100010];

    int n=s.size();

    c[0]=0;

    for(int i=0; i<n; i++){

        if(s[i]=='a') c[i+1]=(c[i]+1)%3;

        else c[i+1]=(c[i]+2)%3;

    }

    int nx[2][100010];

    int p[3][100010];

    for(int j=0; j<3; j++) p[j][n]=n;

    int mn[100010];

    mn[n]=n+1;

    for(int i=n-1; i>=0; i--){

        for(int j=0; j<3; j++) p[j][i]=p[j][i+1];

        p[c[i]][i]=i;

        mn[i]=mn[i+1];

        if(i<n-1 && s[i]==s[i+1]) mn[i]=i+2;

        if(s[i]=='a'){

            nx[0][i]=i+1;

            if(mn[i]<=n) nx[1][i]=p[(c[i]+2)%3][mn[i]];

            else nx[1][i]=n+1;

        }else{

            nx[1][i]=i+1;

            if(mn[i]<=n) nx[0][i]=p[(c[i]+1)%3][mn[i]];

            else nx[0][i]=n+1;

        }

    }

    ll dp[2][100010]={};

    dp[0][0]=1;

    ll ans=0;

    for(int i=0; i<n; i++){

        //cout<<nx[0][i]<<" "<<nx[1][i]<<endl;

        int x=(c[n]-c[i]+3)%3;

      if(x!=0) (ans+=dp[1][i])%=MOD;

      if(x!=0 && (i==n-1 || mn[i]<=n)) (ans+=dp[0][i])%=MOD;

      else if(mn[i]>n && i>0 && s[i]==s[i-1]) (ans+=(n-i-1)/2)%=MOD;

      //cerr<<mn[i]<<endl;

      //cerr<<dp[0][i]<<endl;

        if(nx[0][i]<n){

          if(nx[0][i]==i+1){

            (dp[0][nx[0][i]]+=dp[0][i])%=MOD;

            (dp[1][nx[0][i]]+=dp[1][i])%=MOD;

          }else{

            (dp[1][nx[0][i]]+=dp[0][i])%=MOD;

            (dp[1][nx[0][i]]+=dp[1][i])%=MOD;

          }

        }

        if(nx[1][i]<n){

          if(nx[1][i]==i+1){

            (dp[0][nx[1][i]]+=dp[0][i])%=MOD;

            (dp[1][nx[1][i]]+=dp[1][i])%=MOD;

          }else{

            (dp[1][nx[1][i]]+=dp[0][i])%=MOD;

            (dp[1][nx[1][i]]+=dp[1][i])%=MOD;

          }

        }

    }

    cout<<ans<<endl;

    return 0;

}