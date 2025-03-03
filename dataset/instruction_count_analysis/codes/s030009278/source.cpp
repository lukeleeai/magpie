#include "stdc++.h"

using namespace std;



using LL = long long;



#define MOD (7 + (int)1e9)



vector<LL> f(100000);



LL factorial(LL k){

    f[1] = 1;

    for (int i = 1; i <= k; ++i)

    {

        f[i+1] = (f[i] * (i+1)) % MOD;

    }

    return f[k] % MOD;

}



int main(){

    cin.tie(0);

    ios::sync_with_stdio(false);



    LL N, M;



    cin >> N >> M;



    LL res;

    if(labs(N-M) >= 2){

        cout << 0 << endl;

        return 0;

    }else if(labs(N-M) == 1){

        res = ((factorial(N) % MOD) * (factorial(M) % MOD)) % MOD;

    }else{

        res = ((factorial(N) % MOD) * (factorial(M) % MOD) * 2) % MOD;

    }



    cout << res << endl;



    return 0;

}