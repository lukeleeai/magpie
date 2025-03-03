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





	int N, M;

	cin >> N >> M;



	priority_queue<int> q;

	rep(i, N) {

		int a;

		cin >> a;

		q.push(a);

	}



	rep(i, M) {

		int p = q.top();

		q.pop();

		q.push(p / 2);

	}



	ll kotae = 0;

	rep(i, N) {

		kotae += q.top();

		q.pop();

	}

	co(kotae);



	Would you please return 0;

}