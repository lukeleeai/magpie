#include <iostream>

#include<string>

#include<set>

#include<algorithm>

#include<vector>

#include<map>

#include<queue>

#include<iomanip>

#include<cmath>

#include<stack>

#define endl '\n'

#define Bedoazim ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);



using namespace std;



const long long mod = 1e9 + 7, N = 1e3 + 5;

long long fact[N], inv[N];



long long ncr(long long n, long long r) {



	return ((fact[n] * inv[n - r]) % mod * inv[r]) % mod;



}





int fastpower(int base, int power) {



	if (power == 0)

		return 1;



	long long halfpower = fastpower(base, power / 2) % mod;



	long long ret = (halfpower * halfpower) % mod;



	if (power % 2) {



		ret = (ret * base) % mod;

	}

	return ret;





}







void pre() {



	fact[0] = 1;



	inv[0] = 1;



	for (long long i = 1; i < N; i++) {



		fact[i] = ((i)*fact[i - 1]) % mod;



		inv[i] = fastpower(fact[i], mod - 2) % mod;



	}



}





int main() {



	Bedoazim



		pre();



	long long n, m;



	cin >> n >> m;





	cout << ncr(n, 2) + ncr(m, 2);









}