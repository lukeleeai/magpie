/* 

/*-----------------------------------------------*/

#include <cstdio>

#include <cstring>

#include <string>

#include <vector>

#include <cmath>

#include <algorithm>

#include <queue>

#include <map>

using namespace std;

typedef vector<int> vi;

typedef pair<int, int> ii;

typedef vector<ii> vii;

typedef long long int ll;

typedef vector<ll> vll;

/*-----------------------------------------------*/

// #define DBGMODE

#ifdef DBGMODE

	#define debug(...) fprintf(stderr, __VA_ARGS__)

#else

	#define debug(...)

#endif

/*-----------------------------------------------*/

const int MOD = 1e9 + 7;

int N;

vector<string> perms;

map<string, ll> M[110];

string ch [] = { "A", "C", "G", "T" };



void generate_perms () {

	for (int a = 0; a < 4; a++)

		for (int b = 0; b < 4; b++)

			for (int c = 0; c < 4; c++)

				perms.push_back(ch[a] + ch[b] + ch[c]);

}



bool can_add_c (string p) {

	bool b1 = p[0] == 'A' && (p[1] == 'G' || p[2] == 'G');

	bool b2 = p[1] == 'A' && p[2] == 'G';

	bool b3 = p[2] == 'A' && p[1] == 'G';

	return !(b1 || b2 || b3);

}



bool can_add_g (string p) {

	return !(p[1] == 'A' && p[2] == 'C');

}



bool valid (string p) {

	if (p == "AGC" || p == "ACG" || p == "GAC") return false;

	return true;

}

/*-----------------------------------------------*/

int main() {

	#ifdef DBGMODE

		freopen("input.txt", "r", stdin);

		freopen("output.txt", "w", stdout);

	#endif

	generate_perms();

	for (string s : perms) debug("%s\n", s.c_str());

	scanf("%d", &N);

	for (int i = 0; i < perms.size(); i++) 	{

		if (valid(perms[i])) M[3][perms[i]] = 1;

	}



	for (int i = 4; i <= N; i++) {

		for (int j = 0; j < perms.size(); j++) {

			string p = perms[j];

			string q = p.substr(1);

			ll cnt = M[i - 1][p];

			vi can = { 0, 3 };

			if (can_add_c(p)) can.push_back(1);

			if (can_add_g(p)) can.push_back(2);

			for (int z : can) {

				string tmp = q + ch[z];

				// ll& tmp = M[i][q + ch[z]]

				M[i][q + ch[z]] = ( M[i][q + ch[z]] + cnt ) % MOD;

			}

		}

	}

	ll ans = 0;

	for (auto it = M[N].begin(); it != M[N].end(); it++) ans = (ans + it->second) % MOD;

	printf("%lld\n", ans);

}