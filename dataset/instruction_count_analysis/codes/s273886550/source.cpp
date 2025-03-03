#include <iostream>

#include <queue>

#include <functional>

#include <vector>

#include <tuple>

using namespace std;



template<typename Type> class RangeMin {

private:

	int size_;

	std::vector<Type> dat;

public:

	RangeMin() : size_(0), dat(std::vector<Type>()) {};

	RangeMin(int size__) {

		for (size_ = 1; size_ < size__; ) size_ <<= 1;

		dat.resize(size_ << 1, make_pair(1000000, 1000000));

	}

	template<class T>

	RangeMin(T begin_, T end_) {

		int n = end_ - begin_;

		for (size_ = 1; size_ < n; size_ <<= 1); dat.resize(size_ << 1, make_pair(1000000, 1000000));

		for (int i = 0; i < n; i++) dat[i + size_] = *(begin_ + i);

		for (int i = size_ - 1; i > 0; i--) dat[i] = std::min(dat[i << 1], dat[(i << 1) + 1]);

	}

	inline unsigned size() { return size_; }

	inline void update(int i, Type x) {

		i += size_; dat[i] = x;

		while (i > 1) {

			i >>= 1;

			dat[i] = std::min(dat[i << 1], dat[i << 1 | 1]);

		}

	}

	inline Type query(int l, int r) {

		Type ret = make_pair(1000000, 1000000);

		l += size_; r += size_;

		while (l != r) {

			if (l & 1) ret = std::min(ret, dat[l++]); l >>= 1;

			if (r & 1) ret = std::min(ret, dat[--r]); r >>= 1;

		}

		return ret;

	}

};



int n, a[200009];

RangeMin<pair<int, int>> X1, X2;

priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>>Q;



pair<int, int> Min1(int l, int r) {

	if (l % 2 == 0) return X2.query(l, r + 1);

	return X1.query(l, r + 1);

}



int main() {

	cin >> n; X1 = RangeMin<pair<int, int>>(n + 2); X2 = RangeMin<pair<int, int>>(n + 2);

	for (int i = 1; i <= n; i++) {

		cin >> a[i];

		if (i % 2 == 1) X1.update(i, make_pair(a[i], i));

		else X2.update(i, make_pair(a[i], i));

	}

	Q.push(make_tuple(Min1(1, n).first, 1, n)); vector<int>ans;

	for (int i = 1; i <= n / 2; i++) {

		tuple<int, int, int>G = Q.top(); Q.pop();

		int LL = get<1>(G), RR = get<2>(G);

		pair<int, int>G1 = Min1(LL, RR); ans.push_back(G1.first);

		pair<int, int>G2 = Min1(G1.second + 1, RR); ans.push_back(G2.first);

		if (LL != G1.second) Q.push(make_tuple(Min1(LL, G1.second - 1).first, LL, G1.second - 1));

		if (G1.second + 1 != G2.second) Q.push(make_tuple(Min1(G1.second + 1, G2.second - 1).first, G1.second + 1, G2.second - 1));

		if (G2.second != RR) Q.push(make_tuple(Min1(G2.second + 1, RR).first, G2.second + 1, RR));

	}

	for (int i = 0; i < ans.size(); i++) {

		if (i)cout << " "; cout << ans[i];

	}

	cout << endl;

	return 0;

}