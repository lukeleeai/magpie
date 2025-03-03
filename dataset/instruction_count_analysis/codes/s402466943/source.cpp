#include<iostream>

#include<cstdio>

#include<cmath>

#include<cstring>

#include<string>

#include<stack>

#include<queue>

#include<vector>

#include<algorithm>

#include<iomanip>

#include<utility>

#include<set>

#include<unordered_set>

typedef long long int ll;

#define REP(i,n) for(int i=0;i<signed(n);i++)

using std::cout;

using std::vector;

using std::endl;

using std::cin;

using std::string;

using std::min;

using std::max;

const ll MOD = 1000000007;

const ll INF = 9e9;

ll N, M, ans = INF;

ll A[300010], S[301000];



using namespace std;

int main() {

	//fill(begin(A), end(A), 0);

	fill(begin(S), end(S), 0);

	N = M = 0;

	std::ios_base::sync_with_stdio(false);

	cin >> N;

	REP(i, N) {

		cin >> A[i];

		S[i] += A[i];

		S[i + 1] = S[i];

	}

	//a:右半分の区切り i:真ん中 b:左半分

	//s:右の和 t:左の和

	ll a = 0, b = 2, s, t;

	REP(i, N - 1) {

		if (i == b)b++;

		s = (S[i] - S[a]) - S[a];

		t = (S[N - 1] - S[b]) - (S[b] - S[i]);

		bool f = true;

		if (i == 0)continue;

		while (f) {

			f = false;

			if (a + 1 == i)continue;

			if (abs(s)>abs(s - A[a + 1] * 2)) {

				s -= A[a + 1] * 2;

				a++; f = true;

			}

		}

		f = true;

		while (f) {

			f = false;

			if (b + 1 == N - 1 || b == N - 1)continue;

			if (abs(t)>abs(t - A[b + 1] * 2)) {

				t -= A[b + 1] * 2;

				b++; f = true;

			}

		}

		ans = min(ans, (max({ S[a],S[i] - S[a],S[b] - S[i],S[N - 1] - S[b] })

			- min({ S[a],S[i] - S[a],S[b] - S[i],S[N - 1] - S[b] })));

	}

	cout << ans << endl;

	return 0;

}
