#include"stdc++.h"

using namespace std;

#define  ll long long int

#define mx 1000007

ll dp[mx];

ll a[mx];



int main()

{

    ll n,k;

    cin>>n>>k;

    for(int i=1;i<=n;i++) cin>>a[i];



    memset(dp,0,sizeof(dp));

    for(int i=1;i<=k;i++){

        for(int j=1;j<=n;j++){

            if(i-a[j]>=0){

                if(dp[i-a[j]]==0){

                    dp[i]=1;

                    break;

                }

            }

        }

    }

    if(dp[k]==1) cout<<"First"<<endl;

    else cout<<"Second"<<endl;

}