

//y09-6 ビンゴ(2回目)

#include <iostream>

#include <fstream>

#include <stdio.h>

#include <math.h>

#include <time.h>

#include <string>

#include <vector>

#include <map>

#include <list>

#include <set>

#include <stack>

#include <queue>

#include <cstdlib>

#include <algorithm>

#include <random>

#include <cassert>

using namespace std;

#define LL long long

#undef INT_MIN

#undef INT_MAX

#define INT_MIN -2147483648

#define INT_MAX 2147483647

#define LL_MIN -9223372036854775808

#define LL_MAX 9223372036854775807

#define segment_size 65536

#define ROOP() while (true)



int main(){

    ROOP(){

        int N,M,S;

        cin >> N >> M >> S;

        if(N==0) return 0;

        M = min(M,S);



        int dp[50][3001];

        for(int i=0; i<50; i++){

            for(int j=0; j<3001; j++){

                dp[i][j] = 0;

            }

        }

        dp[0][0] = 1;



        for(int i=1; i<=N*N; i++){

            for(int j=1; j<=S; j++){

                if(j>=i) dp[i][j] = dp[i-1][j-i] + dp[i][j-i];

                if(j>M) dp[i][j] -= dp[i-1][j-M-1];

                dp[i][j] %= 100000;

                if(dp[i][j]<0) dp[i][j]+=100000;

            }

        }

        cout << dp[N*N][S] << endl;



    }

    return 0;

}




