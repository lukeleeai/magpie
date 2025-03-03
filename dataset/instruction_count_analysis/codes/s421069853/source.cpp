#include <iostream>

#define llint long long

#define mod 998244353



using namespace std;



llint fact[4005], fact_inv[4005];



llint pow(llint a, llint n)

{

	if(n == 0) return 1;

	if(n % 2){

		return ((a%mod) * (pow(a, n-1)%mod)) % mod;

	}

	else{

		return pow((a*a)%mod, n/2) % mod;

	}

}



void make_fact()

{

	llint val = 1;

	fact[0] = 1;

	for(int i = 1; i < 4005; i++){

		val *= i;

		val %= mod;

		fact[i] = val;

	}

	for(int i = 0; i < 4005; i++){

		fact_inv[i] = pow(fact[i], mod-2);

	}

}



llint comb(llint n, llint k)

{

	llint ret = 1;

	ret *= fact[n];

	ret *= fact_inv[k], ret %= mod;

	ret *= fact_inv[n-k], ret %= mod;

	return ret;

}



llint K, N;

llint beki[4005];



llint divide(llint n, llint k)

{

	return comb(n+k-1, n);

}



llint calc(llint n, llint x, llint y)

{

	llint ret = 0;

	for(int i = 0; i <= min(x, n); i++){

		llint tmp = divide(n-i, i+y) * beki[i] % mod;

		tmp *= comb(x, i), tmp %= mod;

		ret += tmp, ret %= mod;

	}

	return ret;

}



int main(void)

{

	cin >> K >> N;

	for(llint i = 0, mul = 1; i <= 2*K; i++, mul *= 2, mul %= mod) beki[i] = mul;

	make_fact();

	

	for(int i = 2; i <= 2*K; i++){

		llint g = (i-1)/2, ans = 0;

		if(i > K+1) g = (2*K+1-i)/2;

		if(i % 2) ans += calc(N, g, K-2*g), ans %= mod;

		else{

			ans += calc(N, g, K-2*g-1), ans %= mod;

			ans += calc(N-1, g, K-2*g-1), ans %= mod;

		}

		cout << ans << endl;

	}

	return 0;

}