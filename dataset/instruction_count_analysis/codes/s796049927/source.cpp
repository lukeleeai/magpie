#include<iostream>

#include<algorithm>

#include<string>

using namespace std;

typedef long long ll;

int n;

ll ans, b;

ll a[200005];

ll f(ll x) { return x > 0 ? x : -x; }

int main()

{

	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++)cin >> a[i], a[i] -= i;

	sort(a + 1, a + n + 1);

	b = a[(n + 1) / 2];

	for (int i = 1; i <= n; i++)ans += f(a[i] - b);

	cout << ans;

	return 0;

}