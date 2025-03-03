#include<iostream>

#include <cstdio>

#include <algorithm>

#include <queue>

#include <cstring>

using namespace std;

typedef long long LL;

const int MAXN = 100005;

const LL inf = 0x3f3f3f3f;

int main(void){

    int k,v,u;

    cin>>k;

    vector<int> dp(k,46);

    dp[1] = 1;

    queue<int> deq;

    deq.push(1);

    while(!deq.empty()){

        v=deq.front();

        deq.pop();

        u = (v*10)%k;

        if(dp[u] > dp[v]){

            dp[u] = dp[v];

            deq.push(u);

        }

        u = (v+1)%k;

        if(dp[u] > dp[v]+1){

            dp[u] = dp[v]+1;

            deq.push(u);

        }

    }

    cout<<dp[0]<<endl;

}