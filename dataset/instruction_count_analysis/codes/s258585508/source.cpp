#include"stdc++.h"

using namespace std;

#define ll long long int

#define vl vector<ll>

#define rep(i, n) for (int i = 0; i < (n); ++i)



int main() {

    ll N;

    cin >> N;



    vl A(N);

    vl E(1e6+5, 0);

    rep(i, N) {

        cin >> A[i];

    }



    sort(A.begin(), A.end());



    rep(i, N) {

        E[A[i]] = i+1;

    }



    int ans = 0;

    rep(i, N) {

        // cout << "i : " << i << "  A[i] : " << A[i] <<  endl;

        bool ok = true;

        if (i < N-1 && A[i] == A[i+1]) continue;

        if (i > 0 && A[i] == A[i-1]) continue;

        int max_j = floor(sqrt(A[i]));

        for (int j = 1; j <= min(max_j, 1000); ++j) {

            if (A[i] % j == 0) {

                // cout << "j : " << j << endl;

                // auto itr_1 = find(A.begin(), A.end(), j);

                // if (itr_1 != A.end() && itr_1 - A.begin() != i) {

                if (E[j] && E[j]-1 != i) {

                    ok = false;

                    break;

                }

                // auto itr_2 = find(A.begin(), A.end(), A[i]/j);

                // if (itr_2 != A.end() && itr_2 - A.begin() != i) {

                if (E[A[i]/j] && E[A[i]/j]-1 != i) {

                    ok = false;

                    break;

                }

            }

        }

        if (ok) {

            // cout << A[i] << endl;

            ans++;

        }

    }



    cout << ans << endl;



    return 0;

}
