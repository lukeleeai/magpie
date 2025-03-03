#include <iostream>

#include <set>



using namespace std;



const int L = 10;

struct dist {

	int s, N[L];

	dist() :s(100) {

		for (int i = 0; i < L; i++)

			N[i] = !i;

	}

	dist(const dist &p, int i) :s(p.s + i) {

		//if (*p.N < 0) {

		//	*N = -1;

		//	return;

		//}

		//int k = i;

		//for (int j = 0; j < L; j++) {

		//	N[j] = i ? p.N[j] + k : p.N[j] * 10 + k;

		//	k = N[j] / 100000000;

		//	N[j] %= 100000000;

		//}

		//if (k) *N = -1;

	}

	bool operator<(const dist &d) const {

		if (s != d.s)

			return s < d.s;

		//if (*N < 0)

		//	return false;

		//else if (*d.N < 0)

		//	return true;

		//for (int i = L; i--;)

		//	if (N[i] != d.N[i])

		//		return N[i] < d.N[i];

		return false;

	}

} d[114514];



struct vert {

	int r;

	vert(int r) :r(r) {}

	bool operator<(const vert &v) const {

		if (d[r] < d[v.r])

			return true;

		if (d[v.r] < d[r])

			return false;

		return r < v.r;

	}

};



int main()

{

	int k;

	cin >> k;

	d[1].s = 1;

	set<vert> q;

	q.insert(1);

	while (!q.empty()) {

		int u = q.begin()->r;

		q.erase(q.begin());

		for (int i = 0; i < 2; i++) {

			int v = (i ? u + 1 : u * 10) % k;

			dist l(d[u], i);

			if (!(l < d[v]))

				continue;

			auto it = q.find(v);

			if (it != q.end())

				q.erase(it);

			d[v] = l;

			q.insert(v);

		}

	}

	cout << d->s << endl;

	//if (*d->N < 0) {

	//	cout << "inf" << endl;

	//	return 0;

	//}

	//for (int i = L; i--;) {

	//	if (!k) {

	//		cout.fill('0');

	//		cout.width(8);

	//		cout << right << d->N[i];

	//	}

	//	else if (d->N[i]) {

	//		k = 0;

	//		cout << d->N[i];

	//	}

	//}

	//cout << endl;

	return 0;

}
