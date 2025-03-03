#include "stdc++.h"

#define rep(i, n) for (int i = 0; i < (n); i++)

#define all(x) (x).begin(), (x).end()

using ll = long long;

using namespace std;



vector<ll> AB;

vector<ll> ans;



int main() {

    int X, Y, Z, K;

    cin >> X >> Y >> Z >> K;

    vector<ll> A(X);

    vector<ll> B(Y);

    vector<ll> C(Z);

    rep(i, X) cin >> A[i];

    rep(i, Y) cin >> B[i];

    rep(i, Z) cin >> C[i];

    sort(all(C));

    reverse(all(C));



    rep(x, X) rep(y, Y) {

        AB.push_back(A[x] + B[y]);

    }

    sort(all(AB));

    reverse(all(AB));



    rep(i, min(X*Y, K)) rep(z, min(K, Z)) {

        ans.push_back(AB[i] + C[z]);

    }

    sort(all(ans));

    reverse(all(ans));



    rep(i, K) cout << ans[i] << endl;

}
