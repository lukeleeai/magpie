#include"stdc++.h"

using namespace std;

#define int  long long

#define tc(t)  int t; cin>>t; while(t--)

#define f(n)    for(int i=0;i<n;i++)

#define endl   "\n"















int32_t main()

{

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    int  a,b;

    cin>>a>>b;

    vector<int>dp(3,0);

    dp[a-1]=1;

    dp[b-1]=1;

    for(int i=0;i<3;i++)

    {

        if(dp[i]==0)

        {

            cout<<i+1<<endl;

            break;

        }

    }















}