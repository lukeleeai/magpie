#include "stdc++.h"



using namespace std;



#define int long long



const int N = 2e5 + 100;



int a[N], b[N];

int n, ind;



int32_t main() {

    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {

	cin >> a[i];

	b[i] = a[i];

    }

    sort(b, b + n);

    ind = n / 2 - 1;

    for (int i = 0; i < n; i++)

	cout << (a[i] <= b[ind] ? b[ind + 1] : b[ind]) << '\n';

}