// Atcoder beginner round 174 C - Repsept



#include <iostream>

#include <cstdio>

#include <algorithm>

using namespace std;

typedef long long ll;





int main() {

    ios::sync_with_stdio(false);

    cin.tie(0);

    int K;

    ll a = 7;

    cin >> K;

    if (K % 2 == 0 || K % 10 == 5) 

        cout << "-1";

    for (ll x = 1; x <= K; x++) {

        if(a % K == 0) {

            cout << x;

            break; 

        }

        a = (a *10 + 7) % K;

    }

    return 0;

}