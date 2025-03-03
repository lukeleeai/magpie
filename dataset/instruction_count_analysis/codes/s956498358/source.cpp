#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

typedef pair<int, int> pii;

typedef pair<ll, ll> pll;

#define INF 1<<30

#define LINF 1LL<<60



int main(void) {

    cin.tie(0); ios::sync_with_stdio(false);

    ll N; cin >> N;

    vector<ll> a(3*N);

    for(auto &in:a)cin >> in;

    sort(a.begin(),a.end());

    ll res = 0;

    for(int i = 0; i < N; i++){

        res += a[3*N - 2*(i+1)];

    }

    cout << res << endl;

    return 0;

}
