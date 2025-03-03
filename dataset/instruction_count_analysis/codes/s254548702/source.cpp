#include <iostream>

#include <vector>



using namespace std;



constexpr int64_t MOD = 1'000'000'007;



int main(void) {

    int N, M;

    cin >> N >> M;

    if(N > M) swap(N, M);



    if(N+1 < M) {

        cout << 0 << endl;

    } else {

        vector<int64_t> factrial(M+1);

        factrial[0] = 1;

        for(int i=1; i<=M; i++) {

            factrial[i] = (factrial[i-1] * i) % MOD;

        }

        int64_t ans = (factrial[N] * factrial[M]) % MOD;

        if(N == M) ans = (ans * 2) % MOD;

        cout << ans << endl;

    }

    return 0;

}
