#include"stdc++.h"

using namespace std;

const int N = 1e5 + 1;

int n , a[N] , dp[N] , k;

int calc(int i){

    if(i == n - 1)

        return 0;

    if(i >= n)

        return 1e9 + 10;

    int &ret = dp[i];

    if(ret != -1)return ret;

    ret = 1e9 + 10;

    for(int j = 1 ; j <= k ; j++)

        ret = min( calc(i + j) + abs(a[i] - a[i + j]) , ret ); 

    return ret;

}

int main(){

    scanf("%d%d", &n , &k);

    for(int i = 0 ; i < n ; i++){

        scanf("%d", &a[i]);

    }

    memset(dp , -1 , sizeof dp);

    cout<<calc(0);

    return 0;

}