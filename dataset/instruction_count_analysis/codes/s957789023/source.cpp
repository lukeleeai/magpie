#include "stdc++.h"

using namespace std;

const int sz=1e5+9;

int dp[11][sz];

int n,m;

int a[11];

int cost[]={0,2,5,5,4,5,6,3,7,6};

int have[11];

int ans[11];



int solve(int idx,int rem){

    int &ret=dp[idx][rem];

    if(~ret) return ret;

    if(!rem) return ret=0;

    if(!idx) return ret=-1e5;

    ret=solve(idx-1,rem);

    if(rem>=cost[a[idx]]) ret=max(ret,1+solve(idx,rem-cost[a[idx]]));

    return ret;

}



void print_sol(int idx,int rem){

    if(!rem) return;

    if(!idx) return;

    if(rem>=cost[a[idx]]&&dp[idx][rem]==1+dp[idx][rem-cost[a[idx]]]){

        printf("%d",a[idx]);

        print_sol(idx,rem-cost[a[idx]]);

    }else print_sol(idx-1,rem);

}



int main()

{

    //freopen("in.txt","r",stdin);

    //freopen("out.txt","w",stdout);

    scanf("%d %d",&n,&m);

    for(int i=1;i<=m;i++){

        scanf("%d",&a[i]);

    }

    memset(dp,-1,sizeof(dp));

    sort(a+1,a+m+1);

    solve(m,n);

    print_sol(m,n);

    return 0;

}

// 1 2 3 4 5 6 7 8 9

// 2 5 5 4 5 6 3 7 6
