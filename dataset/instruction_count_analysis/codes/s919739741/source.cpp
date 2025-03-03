#include "stdc++.h"



using namespace std;



typedef long long ll;



ll power(ll a, ll b){

    ll ans = 1;

    for (int i = 0; i < b; i++){

        ans *= a;

    }

    return ans;

}



int main() {

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    ll n, k;

    cin >> n >> k;

    if (k % 2 == 1)

        cout << power(n / k, 3) << endl;

    else

        cout << power(n / k, 3) + power((n + k / 2) / k, 3) << endl;

}