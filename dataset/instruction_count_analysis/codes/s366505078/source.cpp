#include"stdc++.h"

using namespace std;

#define ll long long int

#define vl vector<ll>

#define rep(i, n) for (int i = 0; i < (n); ++i)



int main() {

    int N;

    cin >> N;



    vector<int> A(N);

    rep(i, N) {

        cin >> A[i];

    }

    sort(A.begin(), A.end());



    vector<bool> dp(A[N-1]+1, true);

    int itr = 0;

    for (int i = 0; i < N; ++i) {

        if (!dp[A[i]]) continue;

        for (int j = 2; j*A[i] <= A[N-1]; ++j) {

            dp[j*A[i]] = false;

        }

    }



    int ans = 0;

    rep(i, N) {

        if (i < N-1 && A[i] == A[i+1]) {

            dp[A[i]] = false;

        }

        if (dp[A[i]]) ans++;

    }



    // rep(i, A[N-1]+1) {

    //     if (dp[i]) cout << i << " " << 1 << endl;

    //     else cout << i << " " << 0 << endl;

    // }



    cout << ans << endl;



    return 0;

}
