#include <iostream>

#include <cstdio>

#include <cmath>

#include <ctime>

#include <cstdlib>

#include <cassert>

#include <vector>

#include <list>

#include <stack>

#include <queue>

#include <deque>

#include <map>

#include <set>

#include <bitset>

#include <string>

#include <algorithm>

#include <utility>

#define llint long long

#define inf 1e18

#define rep(x, s, t) for(llint (x) = (s); (x) < (t); (x)++)

#define Rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)

#define chmin(x, y) (x) = min((x), (y))

#define chmax(x, y) (x) = max((x), (y))

#define mod 998244353

using namespace std;

typedef pair<llint, llint> P;

typedef pair<P, llint> E;



const int FACT_MAX = 10005;

llint fact[FACT_MAX], fact_inv[FACT_MAX];



llint modpow(llint a, llint n)

{

	if(n == 0) return 1;

	if(n % 2){

		return ((a%mod) * (modpow(a, n-1)%mod)) % mod;

	}

	else{

		return modpow((a*a)%mod, n/2) % mod;

	}

}



void make_fact()

{

	llint val = 1;

	fact[0] = 1;

	for(int i = 1; i < FACT_MAX; i++){

		val *= i;

		val %= mod;

		fact[i] = val;

	}

	fact_inv[FACT_MAX-1] = modpow(fact[FACT_MAX-1], mod-2);

	for(int i = FACT_MAX-2; i >= 0; i--){

		fact_inv[i] = fact_inv[i+1] * (i+1) % mod;

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



llint divide(llint n, llint k)

{

	return comb(n+k-1, n);

}



llint k, n;



llint calc(llint n, llint k, llint cnt)

{

	llint ret = 0;

	for(int i = 0; i <= cnt; i++){

		if(n-2*i < 0) break;

		llint tmp = divide(n-2*i, k) * comb(cnt, i) % mod;

		if(i % 2) ret += mod - tmp, ret %= mod;

		else ret += tmp, ret %= mod;

	}

	return ret;

}



int main(void)

{

	make_fact();

	cin >> k >> n;

	if(k == 1){

		cout << 0 << endl;

		return 0;

	}

	

	for(int i = 2; i <= 2*k; i++){

		llint cnt = 0;

		for(int j = 1; j <= k; j++){

			llint cj = i-j;

			if(cj <= j || cj < 1 || cj > k) continue;

			cnt++;

		}

		llint ans = 0;

		if(i % 2) ans = calc(n, k, cnt), ans %= mod;

		else ans = calc(n, k-1, cnt) + calc(n-1, k-1, cnt), ans %= mod;

		cout << ans << endl;

	}

	

	return 0;

}
