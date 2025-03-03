#include <stdio.h>

#include <string>

#include <cstring>

#include <stdlib.h>

#include <math.h>

#include <algorithm>

#include <vector>

#include <set>

#include <map>

#include <queue>

#include <iterator>

#pragma warning(disable:4996)

 

typedef long long ll;

#define MIN(a, b) ((a)>(b)? (b): (a))

#define MAX(a, b) ((a)<(b)? (b): (a))

#define LINF 9223300000000000000

#define INF 2140000000

#define MOD 1000000007

using namespace std;



// 方針

//   nが与えられて、それより小さい数を列挙するときには、

//   nを2進数表記して、任意の1のbitを0に変えてそれより下は自由に選択可能になる。

//   今回はn以下という問題だったので、最初に1を足しておいて、その方針を使う。



ll dp[62][2];     // dp[i][0] = 2進数でi桁(最上位は0もOK)のvに対してのuの選び方の合計 (ただし和が上位に繰り上がらない）

                  // dp[i][1] = 2進数でi桁(最上位は0もOK)のvに対してのuの選び方の合計 (ただし和が上位に繰り上がる）



void prepare()

{

    dp[0][0]=1;

    dp[0][1]=0;



    long i;

    for(i=1; i<60; i++) {

         dp[i][0] = (dp[i][0] + 2 * dp[i-1][0]) %MOD;

         dp[i][0] = (dp[i][0] + dp[i-1][1]) %MOD;

         dp[i][1] = (dp[i][1] + dp[i-1][0]) %MOD;

         dp[i][1] = (dp[i][1] + 2 * dp[i-1][1]) %MOD;

    }

}



ll calc( ll n, long i )    // 桁i(下からi+1番目)が1なのを0に変えて、それより下位は自由に選ぶ

{

    ll val[2]= {dp[i][0], dp[i][1]};



    long p;

    for(p=i; p<60; p++) {

        ll valnew[2] = {0, 0};



        bool curr = (p==i? 0: ((n & ((ll)1<<p)) != 0));

        if ( curr ) {

            valnew[0] = (valnew[0] + val[0]) %MOD;

            valnew[0] = (valnew[0] + val[1]) %MOD;

            valnew[1] = (valnew[1] + val[1]) %MOD;

        }

        else {

            valnew[0] = (valnew[0] + val[0]) %MOD;

            valnew[1] = (valnew[1] + val[0]) %MOD;

            valnew[1] = (valnew[1] + val[1]) %MOD;

        }



        val[0] = valnew[0];

        val[1] = valnew[1];

    }



    return val[0];

}



long solve( ll n )

{

    n ++;    // nより小さい数だけを考えればよい形にするため

    

    ll ans=0;

    long i;

    for(i=60; i>=0; i--) {

        if(n & ((ll)1<<i)) {   // 桁i(下からi+1番目)が1のとき、0に変えた場合を計算

            ans = (ans + calc(n, i)) %MOD;

        }

    }

    printf("%lld\n", ans);



    return 0;

}



int main(int argc, char* argv[])

{

    ll n;

    scanf("%lld", &n);



    prepare();



    return solve( n );

}