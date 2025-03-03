#include "stdc++.h"

using namespace std;



using ll = long long;

using ull = unsigned long long;



#define MOD 1000000007



int main(void) {

    ll N, K;

    ll count = 0;

    vector<ll> A;

    cin >> N >> K;

    A.resize(N);

    for(ll i = 0;i < K;i++) {

        ll d;

        cin >> d;

        for(ll j = 0;j < d;j++) {

            ll temp;

            cin >> temp;

            A[temp - 1]++;

        }

    }

    for(ll i = 0;i < A.size();i++) {

        if(A[i] == 0) count++;

    }

    cout << count << endl;

    return 0;

}
