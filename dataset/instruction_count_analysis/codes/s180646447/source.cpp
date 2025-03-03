#include<iostream>

#include<algorithm>

#include<vector>

#include<string>

#include<cmath>

#include<functional>

#include<limits>

#include<queue>

#include<tuple>

#include<map>

using namespace std;



// ------ RMQ Class ------ //

template<typename Type>

class RMQ {

private:

	int size_; std::vector<Type> dat;

public:

	RMQ() : size_(0), dat(std::vector<Type>()) {};

	RMQ(int size__) {

		for (size_ = 1; size_ < size__; ) size_ <<= 1;

		dat.resize(size_ << 1, std::numeric_limits<Type>::max());

	}

	template<class T>

	RMQ(T begin_, T end_) {

		int n = end_ - begin_;

		for (size_ = 1; size_ < n; size_ <<= 1); dat.resize(size_ << 1, std::numeric_limits<Type>::max());

		for (int i = 0; i < n; i++) dat[i + size_] = *(begin_ + i);

		for (int i = size_ - 1; i > 0; i--) dat[i] = std::min(dat[i << 1], dat[(i << 1) + 1]);

	}

	inline unsigned size() { return size_; }

	inline void update(unsigned i, Type x) {

		i += size_; dat[i] = x;

		while (i > 1) {

			i >>= 1;

			dat[i] = std::min(dat[i << 1], dat[i << 1 | 1]);

		}

	}

	inline Type query(unsigned l, unsigned r) {

		Type ret = std::numeric_limits<Type>::max();

		l += size_; r += size_;

		while (l != r) {

			if (l & 1) ret = std::min(ret, dat[l++]); l >>= 1;

			if (r & 1) ret = std::min(ret, dat[--r]); r >>= 1;

		}

		return ret;

	}

	pair<int, int> query_index(unsigned l, unsigned r) {

		Type ret = query(l, r);

		return make_pair(ret / 1000000, ret % 1000000);

	}

};



long long n, p[220000]; vector<int>T;

map<pair<int, int>, vector<pair<int, int>>>M; pair<int, int>J;

RMQ<long long>R1(200000), R2(200000);



pair<int, int>dfs(int L, int R) {

	if (L == R)return make_pair(-1, -1);

	if (L % 2 == 0) {

		pair<int, int>V1 = R1.query_index(L / 2, R / 2); V1.second *= 2;

		pair<int, int>V2 = R2.query_index(V1.second / 2, R / 2); V2.second *= 2; V2.second += 1;

		pair<int, int>I1 = dfs(L, V1.second); M[make_pair(V1.first, V2.first)].push_back(I1);

		pair<int, int>I2 = dfs(V1.second + 1, V2.second); M[make_pair(V1.first, V2.first)].push_back(I2);

		pair<int, int>I3 = dfs(V2.second + 1, R); M[make_pair(V1.first, V2.first)].push_back(I3);

		if (L == 0 && R == n)J = make_pair(V1.first, V2.first);

		return make_pair(V1.first, V2.first);

	}

	else {

		pair<int, int>V1 = R2.query_index(L / 2, R / 2); V1.second *= 2; V1.second += 1;

		pair<int, int>V2 = R1.query_index((V1.second / 2) + 1, (R + 1) / 2); V2.second *= 2;

		pair<int, int>I1 = dfs(L, V1.second); M[make_pair(V1.first, V2.first)].push_back(I1);

		pair<int, int>I2 = dfs(V1.second + 1, V2.second); M[make_pair(V1.first, V2.first)].push_back(I2);

		pair<int, int>I3 = dfs(V2.second + 1, R); M[make_pair(V1.first, V2.first)].push_back(I3);

		return make_pair(V1.first, V2.first);

	}

}

int main() {

	cin >> n;

	for (int i = 0; i < n; i++)cin >> p[i];

	

	for (int i = 0; i < n; i++) {

		if (i % 2 == 0)R1.update(i / 2, p[i] * 1000000 + (i / 2));

		else R2.update(i / 2, p[i] * 1000000 + (i / 2));

	}

	dfs(0, n);

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>Q;

	Q.push(J);

	while (!Q.empty()) {

		pair<int, int>U = Q.top(); Q.pop();

		if (U.first == -1)continue;

		T.push_back(U.first); T.push_back(U.second);

		for (int i = 0; i < M[U].size(); i++) {

			Q.push(M[U][i]);

		}

	}

	for (int i = 0; i < T.size(); i++) {

		if (i)cout << ' ';

		cout << T[i];

	}

	cout << endl;

	return 0;

}