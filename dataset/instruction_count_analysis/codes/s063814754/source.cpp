#include"stdc++.h"

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

#define Would

#define you

#define please





int main() {

	cin.tie(0);

	ios::sync_with_stdio(false);





	int N;

	cin >> N;

	int A[100000];

	rep(i, N) cin >> A[i];



	deque<int> D;

	D.push_front(-1);



	rep(i, N) {

		auto itr = lower_bound(D.begin(), D.end(), A[i]) - 1;

		*itr = A[i];

		if (itr == D.begin()) D.push_front(-1);

	}



	co(D.size() - 1);



	Would you please return 0;

}