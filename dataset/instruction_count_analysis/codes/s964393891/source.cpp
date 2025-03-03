#include <iostream>

#include <algorithm>



typedef long long ll;



using namespace std;



int main() {

    ll n, x, cnt = 0, prev = 0, now;

    cin >> n >> x;

    for (ll i = 0; i < n; ++i) {

        cin >> now;

        prev = now - max(prev + now - x, 0LL);

        cnt += now - prev;

    }

    cout << cnt << endl;

    return 0;

}
