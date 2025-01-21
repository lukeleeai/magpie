#include"stdc++.h"

using namespace std;

typedef long long int ll;

const int MAX=1e5+10;

int N,k,A[MAX],dp[MAX];

int solve(int idx)

{

    if(idx==N)return 0;

    if(idx>N)return 1e9;

    if(dp[idx]!=-1)return dp[idx];

    int res=1e9;

    for(int i=1;i<=k;i++){

        res = min(res,solve(idx+i)+abs(A[idx+i]-A[idx]));

    }

    return dp[idx]=res;

}

int  main ()

{

    memset(dp,-1,sizeof dp);

    cin >> N >> k;

    for(int i=1;i<=N;i++){

        cin >> A[i];

    }

    cout<<solve(1)<<endl;

    return 0;

}


