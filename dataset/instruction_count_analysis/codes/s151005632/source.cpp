#include "stdc++.h"

using namespace std;

using ll = long long;



ll GCD(ll a, ll b)

{

	if (b == 0) return a;

	else return GCD(b, a%b);

}



int main(int argc, char **argv)

{

	ll n; cin >> n;

	vector<ll> v(n); for (int i = 0; i < n; ++i) cin >> v[i];

	ll res{0};

	for (int i = 0; i < n; ++i)

	{

		res = GCD(v[i], res);

	}

	std::cout << res<< std::endl;

}