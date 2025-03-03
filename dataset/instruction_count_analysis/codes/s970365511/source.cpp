#include"stdc++.h"

using namespace std;

 

#define fi first

#define se second

#define pb push_back

#define all(x) x.begin(), x.end()

#define mp make_pair

 

typedef long long ll;

typedef unsigned long long int ull;

typedef long double ld;

 

typedef pair<int, int> pii;

typedef pair<int, pii> piii;

 

typedef vector<ll> vll;

typedef vector<pii> vpii;

typedef vector<int> vi;

typedef vector<vi> vvi;

typedef vector<pair<int, pii>> vpiii;

 

typedef map<string, int> msi;

typedef map<int, int> mii;

typedef map<int, ll> mill;

typedef map<int, vi> mivi;

typedef map<int, vpii> mivpii;



const int MAXN = 1e5;

const int UNSET = -1;

const int MAXK = 3;



int d[MAXN + 1];

int dp[MAXN + 1][MAXK + 1][2];



string S;

int N, K;



void fast_io() {

	ios::sync_with_stdio(false);

	cin.tie(NULL);

}



int solve(int pos, int k, bool r) {

	if(pos == N) return k == K;

	if(dp[pos][k][r] != UNSET) return dp[pos][k][r];

	

	int lim = (r ? d[pos] : 9);

	int ans = 0;

	

	for(int i = 0; i <= lim; i++) {

		bool nr = (i == d[pos]) ? r : 0;

		int nk = (i) ? k + 1 : k;

		if(nk <= K) ans += solve(pos + 1, nk, nr);

	}

	return dp[pos][k][r] = ans;

}



void prepare() {

	memset(dp, UNSET, sizeof(dp));

	for(int i = 0; i < S.length(); i++)

		d[i] = S[i] - '0';

	N = S.length();

}



int main() {

	fast_io();

//	freopen("input/ABC154E.txt", "r", stdin);

	

	cin >> S >> K;

	prepare();

	cout << solve(0, 0, 1) << '\n';

	

	return 0;

}
