#include "stdc++.h"



using namespace std;



const int N = 1e5 + 9, OO = 0x3f3f3f3f;



int n, k, h[N], dp[N];



int solve(int i){

    if(i == n - 1)  return 0;

    if(i >= n)   return 1e9;



    int &ret = dp[i];

    if(~ret)    return ret;



    ret = OO;

    for(int j = 1;j <= k;j++)

        ret = min(ret, abs(h[i] - h[i + j]) + solve(i + j));



    return ret;

}



int main(){



    cin >> n >> k;

    for(int i = 0;i < n;i++)

        cin >> h[i];



    memset(dp, -1, sizeof dp);



    cout << solve(0);

}
