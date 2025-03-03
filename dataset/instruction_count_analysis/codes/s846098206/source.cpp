#include "stdc++.h"

using namespace std;



long long int N, p[364364], id[364364], dp[364364], x, i;



int main(){

    iota(p, p + 364364, 1);

    scanf("%lld", &N);

    for(; i < N; ++i){

        scanf("%lld", p + i);

        id[p[i]] = i;

    }

    dp[N] = 0;

    x = N;

    for(; --i;){

        if(dp[i + 1]){

            dp[i] = dp[i + 1];

            if((id[i] < id[i + 1]) ^ (id[i + 1] < id[x]) ^ (id[x] < id[i])){

                ++dp[i];

                x = i + 1;

            }

        }else{

            dp[i] = dp[i + 1] + ((id[i] > id[i + 1]) ? 1 : 0);

            if(id[i] < id[i + 1])--x;

        }

    }

    cout << dp[1] << endl;

    return 0;

}
