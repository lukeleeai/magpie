#include "iostream"

#include "climits"

#include "list"

#include "queue"

#include "stack"

#include "set"

#include "functional"

#include "algorithm"

#include "string"

#include "map"

#include "unordered_map"

#include "unordered_set"

#include "iomanip"

#include "cmath"

#include "random"

#include "bitset"

#include "cstdio"

#include "numeric"

#include "cassert"

#include "ctime"



using namespace std;



//constexpr long long int MOD = 1000000007;

//constexpr int MOD = 1000000007;

//constexpr int MOD = 998244353;

constexpr long long int MOD = 998244353;

constexpr double EPS = 1e-12;



//int N, M, K, T, H, W, L, R;

long long int N, M, K, T, H, W, L, R;



class Segment_Tree {

public:

	vector<long long int>v;

	int num;

	long long int ret;

	long long int Update(int place) {

		if (place >= v.size() / 2) {

			return v[place];

		}

		v[place] = min(Update(place * 2), Update(place * 2 + 1));

		return v[place];

	}

	Segment_Tree(int n) {

		n++;

		num = 1;

		while (num < n * 2) {

			num *= 2;

		}

		v.resize(num, N-1);

	}

	int Get(int place) {

		ret = N - 1;

		place += v.size() / 2;

		while (place) {

			ret = min(ret, v[place]);

			place /= 2;

		}

		return ret;

	}

	void TopDown() {

		Update(1);

	}

	void Modify(int a, int b,long long int c) {

		b++;

		for (a += num / 2, b += num / 2; a < b; a >>= 1, b >>= 1) {

			if (a & 1) {

				v[a] = min(v[a], c);

				a++;

			}

			if (b & 1) {

				b--;

				v[b] = min(v[b], c);

			}

		}

	}

};



int main() {

	ios::sync_with_stdio(false);

	cin.tie(0);



	cin >> N >> K;

	Segment_Tree xsg(N);

	Segment_Tree ysg(N);

	long long int sum = (N - 2)*(N - 2);

	while (K--) {

		cin >> L;

		if (L == 1) {

			int x;

			cin >> x;

			x--;

			int box = xsg.Get(x);

			sum -= max(0, box - 1);

			ysg.Modify(1, box - 1, x);

		}

		else {

			int y;

			cin >> y;

			y--;

			int box = ysg.Get(y);

			sum -= max(0, box - 1);

			xsg.Modify(1, box - 1, y);

		}

	}

	cout << sum << endl;

}