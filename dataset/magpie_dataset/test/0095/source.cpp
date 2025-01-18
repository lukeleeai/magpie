#include <iostream>

#include <algorithm>

#include <string>

#include <cmath>

#include <cstring>

#include <iomanip>



using namespace std;

typedef long long ll;

const int maxn=1e5+1111;



int arr[maxn];

int dp[maxn];

int main(){

    int n,k;

    scanf("%d%d",&n,&k);

    dp[0]=dp[1]=0;

    for(int i=1;i<=n;++i){

        scanf("%d",arr+i);

        if(i>1) dp[i]=dp[i-1]+abs(arr[i]-arr[i-1]);

        for(int j=2;j<=k&&i-j>0;++j){

            dp[i]=min(dp[i-j]+abs(arr[i]-arr[i-j]),dp[i]);

        }

    }

    printf("%d\n",dp[n]);

    return 0;

}