#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

typedef pair<int,int> pii;

#define rep(i,n) for(ll i=0;i<(ll)(n);i++)

#define all(a)  (a).begin(),(a).end()

#define pb push_back

#define INF 999999999



int main(){

    double g[110][110];

    rep(i,110)rep(j,110)g[i][j]=-1;

    int n,m;

    while(cin>>n>>m){

        if(n==0&&m==0)break;

        rep(i,n){

            rep(j,n){

                cin>>g[i][j];

            }

        }

    

    

        double dp[110][110];

        rep(i,110)rep(j,110)dp[i][j] = -1;

        rep(i,n)dp[1][i]=1.0;

    

        for(int i=2;i<=m;i++){

            for(int j=0;j<n;j++){

                for(int k=0;k<n;k++){

                    dp[i][j] = max(dp[i][j],dp[i-1][k]*g[k][j]);

                }

            }

        }

        double ans = -1;

        rep(i,n){

            ans = max(ans,dp[m][i]);

        }

        printf("%.2lf\n",ans);

    }

}