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

	int n;

	vector<ll> v(1000000);



	cin >> n;

	for (int i = 0; i < n; ++i) cin >> v[i];



	int ans{0};

	for (int i = 0; i < n; ++i) ans = GCD(ans, v[i]);

	

	std::cout << ans << std::endl;

}