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



ll BIT[200200], BIT2[200200];

void add(int A, int B) {

	while (A < 200200) {

		BIT[A] += B;

		A += A & -A;

	}

}



ll query(int A) {

	ll kotae = 0;

	while (A > 0) {

		kotae += BIT[A];

		A -= A & -A;

	}

	return kotae;

}



void add2(int A) {

	while (A < 200200) {

		BIT2[A]++;

		A += A & -A;

	}

}



ll query2(int A) {

	ll kotae = 0;

	while (A > 0) {

		kotae += BIT2[A];

		A -= A & -A;

	}

	return kotae;

}



int main() {

	cin.tie(0);

	ios::sync_with_stdio(false);





	int Q;

	cin >> Q;



	int QL[200000];

	pair<int, int> Q1[200000];

	vector<int> Q1N;

	vector<int>za;

	rep(q, Q) {

		cin >> QL[q];

		if (QL[q] == 1) {

			int a, b;

			cin >> a >> b;

			Q1[q] = mp(a, b);

			za.pb(a);

			Q1N.pb(q);

		}

	}



	vector<int> za2;

	sort(za.begin(), za.end());

	int mae = -1e9 - 1;

	for (int i : za) {

		if (mae != i) za2.pb(i);

		mae = i;

	}



	ll B = 0;

	int SIZE = 0;

	rep(q, Q) {

		if (QL[q] == 1) {

			SIZE++;

			B += Q1[q].second;

			int QK = lower_bound(za2.begin(), za2.end(), Q1[q].first) - za2.begin() + 1;

			add(QK, Q1[q].first);

			add2(QK);

		}

		else {

			int s = SIZE;

			s = (s + 1) / 2;

			

			int L = 0;

			int R = 200199;

			while (L + 1 < R) {

				int H = (L + R) / 2;

				if (query2(H) >= s) R = H;

				else L = H;

			}

			int kari = za2[R - 1];

			cosp(kari);

			ll kotae = B;

			kotae += 1ll * query2(R) * kari - query(R);

			kotae += (query(200199) - query(R)) - 1ll * (SIZE - query2(R)) * kari;

			co(kotae);

		}

	}



	Would you please return 0;

}