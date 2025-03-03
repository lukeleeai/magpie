#include "stdc++.h"



using namespace std;



#define ll long long



const int N = 1e6+3,M=55;



const ll oo=1e18;



int n,m,ans,tc,a[N],b[N],k;



#define f first



#define s second



const int dx[]={0,0,1,-1},

          dy[]={1,-1,0,0};



char s[N];



ll dp[105][105][105];



ll solve(int l,int r,int rem){

    if (rem<0)

        return -1e9;

    if (l>r)

        return 0;

    ll &ret = dp[l][r][rem];

    if (ret!=-oo)

        return ret;

    ret=0;

    ret=max(ret,max(a[l]+solve(l+1,r,rem-1),solve(l+1,r,rem-2)));

    return ret=max(ret,max(a[r]+solve(l,r-1,rem-1),solve(l,r-1,rem-2)));

}



int main(){

    for(int i=0;i<105;i++)

        for(int j=0;j<105;j++)

            for(int k=0;k<105;k++)

                dp[i][j][k]=-oo;

    scanf("%d %d",&n,&k);

    for(int i=0;i<n;i++)

        scanf("%d",&a[i]);

    printf("%lld",solve(0,n-1,k));

}




