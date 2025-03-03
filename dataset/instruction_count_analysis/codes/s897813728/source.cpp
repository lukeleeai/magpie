#include <iostream>

#include <vector>

using namespace std;



typedef struct P {

	int p, d;

	bool operator<(const P &r) {

		return d < r.d;

	}

} P;

int n, d[10001];

vector<P> v;



int main(){

	int p, d1, d2;

	while (cin >> n && n != 0) {

		v = vector<P>();

		for (int i = 0; i < n; i++) {

			cin >> p >> d1 >> d2;

			v.push_back({ p,d1 + d2 });

		}

		P m = v[0];

		for (int i = 1; i < v.size(); i++) {

			if (m < v[i]) {

				m = v[i];

			}

		}

		cout << m.p << " " << m.d << endl;

	}



	return 0;

}