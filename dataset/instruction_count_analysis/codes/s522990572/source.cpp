#pragma GCC optimize ("O3")

#pragma GCC target ("avx")

//#include"stdc++.h"

#include<cstdio>

#include<algorithm>

#include<cstring>

using namespace std;

typedef long long ll;

#define rep(i, n) for(int i = 0; i < (n); i++)

#define rep1(i, n) for(int i = 1; i <= (n); i++)

#define co(x) cout << (x) << "\n"

#define cosp(x) cout << (x) << " "

#define ce(x) cerr << (x) << "\n"

#define cesp(x) cerr << (x) << " "

#define pb push_back

#define mp make_pair

#define chmin(x, y) x = min(x, y)

#define chmax(x, y) x = max(x, y)

#define Would

#define you

#define please



int main() {

	//cin.tie(0);

	//ios::sync_with_stdio(false);





	ll kotae = 0;

	char c = '<';

	int kazu1 = -1, kazu2 = 0;

	while (c >= '<') {

		kazu1++;

		while ((c = getchar_unlocked()) == '<') kazu1++;

		if (c == '>') kazu2++;

		while ((c = getchar_unlocked()) == '>') kazu2++;

		if (kazu1 > kazu2) swap(kazu1, kazu2);

		kazu1--;

		kotae += ((ll)kazu1 * (kazu1 + 1) + (ll)kazu2 * (kazu2 + 1)) >> 1;

		kazu1 = 0;

		kazu2 = 0;

	}



	printf("%lld", kotae);



	Would you please return 0;

}