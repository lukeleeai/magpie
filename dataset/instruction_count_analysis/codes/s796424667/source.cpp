#include "stdc++.h"

#define mod 1000000007

#define sp ' '

#define intmax 2147483647

#define llmax 9223372036854775807

#define nyan "(=^･ω･^=)"

#define mkp make_pair

#define mkt make_tuple

#define lP pair<ll, ll>

#define iP pair<int,int>

typedef long long ll;

using namespace std;



int N, a, cnt[100002], ans;



int main(){

	cin >> N;

	for (int i = 0; i != N; ++i) {

		cin >> a;

		a = min(N + 1, a);

		++cnt[a];

	}

	for (int i = 1; i != N + 2; ++i) {

		if (cnt[i] >= i)ans += cnt[i] - i;

		else ans += cnt[i];

	}

	cout << ans << endl;

	return 0;

}
