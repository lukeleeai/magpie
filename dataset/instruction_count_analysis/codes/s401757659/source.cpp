#include "stdc++.h"

#include <math.h>

using namespace std;

int main(){

    int N,T;

    cin >>N>>T;

    int C[N];

    int Q[N];

    vector<int> memo(123456,12345678);

    int a = 0,b = 12345678;

    vector< tuple<int,int,int>>  A(N);

    for(int i = 0;i < N;i++){

        cin >> C[i] >> Q[i];

        if(Q[i] <= T){

            memo[i] = C[i];

            a++;

        }

        b = min(b,Q[i]);

    }

    int ans = 12345678;

    for(int i = 0;i < N;i++){

        ans = min(ans,memo[i]);

    }

    if(b > T) cout << "TLE" << endl;

    else cout << ans << endl;

 

}