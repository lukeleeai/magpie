#include "stdc++.h"



using namespace std;



#define REP(i,n) for(ll (i) = (0);(i) < (n);++i)

#define REV(i,n) for(ll (i) = (n) - 1;(i) >= 0;--i)

#define PB push_back

#define EB emplace_back

#define MP make_pair

#define FI first

#define SE second

#define SHOW1d(v,n) {REP(WW,n)cerr << v[WW] << ' ';cerr << endl << endl;}

#define SHOW2d(v,WW,HH) {REP(W_,WW){REP(H_,HH)cerr << v[W_][H_] << ' ';cerr << endl;}cerr << endl;}

#define ALL(v) v.begin(),v.end()

#define Decimal fixed<<setprecision(20)

#define INF 1000000000

#define LLINF 1000000000000000000LL

#define MOD 998244353



#define BIT_N 333

typedef long long ll;

typedef pair<ll,ll> P;

typedef bitset<BIT_N> Bit;

vector<int> baseNum;



ll pow_two[BIT_N];



vector<Bit> gauss(vector<Bit> &v, ll &ran){

	ran = 0;

	REP(i,BIT_N) {

		int pla = -1;

		for(int j = ran;j < v.size();j++){

			if(v[j][i] == 1){

				pla = j;

				break;

			}

		}

		

		if(pla != -1){

			swap(v[ran], v[pla]);

			for(int j = 0;j < v.size();j++){

				if(j != ran && v[j][i] == 1)v[j] ^= v[ran];

			}

			ran++;

		}

	}

	return v;

}



int main(){

	

	pow_two[0] = 1;

	REP(i,BIT_N - 1)pow_two[i+1] = pow_two[i] * 2 % MOD;

	

	vector<Bit> v;

	ll n, m;cin >> n >> m;

	REP(i,n){

		Bit now;

		REP(j,m){

			int a;cin >> a;

			if(a)now[j] = 1;

		}

		v.PB(now);

	}

	

	ll ran = 0;

	ll ans = 0;

	gauss(v, ran);

	

	cout << ((pow_two[n] - pow_two[n - ran] + MOD) % MOD) * pow_two[m-1] % MOD << endl;

	

	return 0;

}
