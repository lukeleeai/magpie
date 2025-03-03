#ifndef __SEGMENT_TREE_H__

#define __SEGMENT_TREE_H__



#include <vector>

#include <functional>

#include <algorithm>

#include <limits>

#include <cassert>

#include <iostream>

#include <string>

#include <sstream>



/*-- てんぷれ --*/

struct HogeMonoid {

	using Type = int;

	static Type Identity() {

		return Type();

	}

	static Type Operate(const Type& left, const Type& right) {

		return Type();

	}

};



/*--------------*/



namespace Monoid {

	template <class T>

	struct Sum {

		using Type = T;

		static Type Identity() {

			return T();

		}

		static Type Operate(const Type& left, const Type& right) {

			return left + right;

		}

	};



	template <class T>

	struct Minimum {

		using Type = T;

		static Type Identity() {

			return std::numeric_limits<Type>::max();

		}

		static Type Operate(const Type& left, const Type& right) {

			return std::min(left, right);

		}

	};



	template <class T>

	struct Maximum {

		using Type = T;

		static Type Identity() {

			return std::numeric_limits<Type>::min();

		}

		static Type Operate(const Type& left, const Type& right) {

			return std::max(left, right);

		}

	};

}



/* 注意: コンストラクタの引数は size でない */

template <class Monoid>

class SegmentTree {

	using T = typename Monoid::Type;



	const int level_m;		// 段数 - 1

	const size_t size_m;	// 1 << level_m

	std::vector<T> arr_m;



	static T Identity();

	static T Operate(const T& left, const T& right);

	bool Is_valid_index(size_t pos) const;

	

	static const int DEFAULT = -1;

public:

	SegmentTree(int level);



	void Update(size_t pos, const T& value);

	T Query(size_t left, size_t right) const;

	T Get(size_t pos) const;

	void Debug(int level = DEFAULT, int cell_width = 4) const;

};



template<class Monoid>

typename SegmentTree<Monoid>::T SegmentTree<Monoid>::Identity() {

	return Monoid::Identity();

}



template<class Monoid>

typename SegmentTree<Monoid>::T SegmentTree<Monoid>::Operate(const T& left, const T& right) {

	return Monoid::Operate(left, right);

}



template<class Monoid>

inline bool SegmentTree<Monoid>::Is_valid_index(size_t pos) const {

	return pos >= 0 && pos < size_m;

}



/* 1 << level 要素の segment tree を作成 */

template<class Monoid>

SegmentTree<Monoid>::SegmentTree(int level)

	: level_m(level), size_m(1 << level) {

	assert(level < 32);

	if (0) {

		assert(0); // 引数が level になっていることを確認してから submit

	}

	arr_m.resize(size_m * 2, Identity());

}



/* pos 番目の要素を value に書き換える */

template<class Monoid>

void SegmentTree<Monoid>::Update(size_t pos, const T& value) {

	pos += size_m;

	arr_m[pos] = value;

	pos >>= 1;

	while (pos > 0) {

		arr_m[pos] = Operate(arr_m[pos * 2], arr_m[pos * 2 + 1]);

		pos >>= 1;

	}

}



/* [left, right) に存在する全要素の(指定した演算に関する)積をとる */

template<class Monoid>

typename SegmentTree<Monoid>::T SegmentTree<Monoid>::Query(size_t left, size_t right) const {

	assert(left <= right);



	T tmp_left = Identity();

	T tmp_right = Identity();

	left += size_m;

	right += size_m;

	while (left < right) {

		if (left & 1) tmp_left = Operate(tmp_left, arr_m[left++]);

		if (right & 1) tmp_right = Operate(arr_m[--right], tmp_right);

		left >>= 1;

		right >>= 1;

	}



	return Operate(tmp_left, tmp_right);

}



/* pos 番目の要素を直接取得 */

template<class Monoid>

typename SegmentTree<Monoid>::T SegmentTree<Monoid>::Get(size_t pos) const {

	return arr_m[size_m + pos];

}



/* デバッグ出力用; level = -1 とすると全要素出力 */

template<class Monoid>

void SegmentTree<Monoid>::Debug(int level, int cell_width) const {

	/* 値 value を幅 max_length になるように成形して文字列化 */

	auto to_str_fixed = [](const T& value, int max_length) -> std::string {

		std::ostringstream osst;

		osst << value;



		std::string str = osst.str();

		std::string output;

		if (str.size() > max_length) {

			for (int i = 0; i < max_length; ++i) {

				output += '#';

			}

		} else {

			const int remain_length = max_length - str.size();

			const int right_blank = remain_length / 2;

			const int left_blank = remain_length - right_blank;

			for (int i = 0; i < left_blank; ++i) {

				output += ' ';

			}

			output += str;

			for (int i = 0; i < right_blank; ++i) {

				output += ' ';

			}

		}

		return output;

	};



	if (level == DEFAULT) {			// デフォルト値への対処

		level = level_m;

	}



	if (level > level_m) {

		level = level_m;

	}



	std::vector<std::string> output_strs;



	for (int lev = 0; lev <= level; ++lev) {

		std::string output;

		const int front = size_m >> lev;



		output += '|';

		for (int i = 0; i < (1 << (level - lev)); ++i) {

			output += to_str_fixed(arr_m[front + i], cell_width);

			output += '|';

		}

		output_strs.push_back(output);



		cell_width = cell_width * 2 + 1;

	}



	reverse(output_strs.begin(), output_strs.end());

	for (const std::string& output : output_strs) {

		std::cout << output << std::endl;

	}

}



#endif



#define _CRT_SECURE_NO_WARNINGS

#define _SCL_SECURE_NO_WARNINGS

#include <cstdio>

#include <cstdlib>

#include <cstring>

#include <cassert>

#include <iostream>

#include <string>

#include <vector>

#include <list>

#include <utility>

#include <algorithm>

#include <functional>

#include <cmath>

#include <stack>

#include <queue>

#include <set>

#include <map>

#include <iomanip>

#include <sstream>

#include <bitset>

#include <limits>

#include <numeric>

#include <valarray>

#include <fstream>



using namespace std;

typedef unsigned int uint;

typedef long long LL;

typedef unsigned long long ULL;

typedef pair<LL, LL> PP;

#define REP(i, a, n) for(LL i = (a), i##_max = (n); i < i##_max; ++i)

#define REM(i, a, n) for(LL i = (LL)(n) - 1, i##min = (a); i >= i##min; --i)

#define ALL(arr) (arr).begin(), (arr).end()

#define FLOAT fixed << setprecision(16)

#define SPEEDUP {cin.tie(NULL); ios::sync_with_stdio(false);}

const int INF = 0x3FFFFFFF;

const LL INFLL = 0x3FFFFFFF3FFFFFFF;

const double INFD = 1.0e+308;

const double EPS = 1.0e-9;



void YesNo(bool b) { cout << (b ? "Yes" : "No") << endl; }

void YESNO(bool b) { cout << (b ? "YES" : "NO") << endl; }

template <class T, class U>

istream& operator>>(istream& ist, pair<T, U>& right) { return ist >> right.first >> right.second; }

template <class T, class U>

ostream& operator<<(ostream& ost, const pair<T, U>& right) { return ost << right.first << ' ' << right.second; }

template <class T, class TCompatible, size_t N>

void Fill(T(&dest)[N], const TCompatible& val) { fill(dest, dest + N, val); }

template <class T, class TCompatible, size_t M, size_t N>

void Fill(T(&dest)[M][N], const TCompatible& val) { for (int i = 0; i < M; ++i) Fill(dest[i], val); }

template<class T>

T Compare(T left, T right) { return left > right ? 1 : (left < right ? -1 : 0); }

istream& Ignore(istream& ist) { string s; ist >> s; return ist; }

bool Inside(int i, int j, int h, int w) { return i >= 0 && i < h && j >= 0 && j < w; }

template <class T>

T Next() { T buf; cin >> buf; return buf; }



#ifdef ONLY_MY_ENVIR

#include "IntMod.h"

#include "BinaryMatrix.h"

#include "BIT.h"

#include "Factorization.h"

#include "FlowSolver.h"

#include "Graph.h"

#include "LazySegmentTree.h"

#include "Math.h"

#include "Matrix.h"

#include "MinMax.h"

#include "Position.h"

#include "Range.h"

#include "Rational.h"

#include "SegmentTree.h"

#include "SegmentTree2D.h"

#include "SuffixArray.h"

#include "Tree.h"

#include "UnionFind.h"

#endif



#ifdef __GNUC__

typedef __int128 LLL;

istream& operator>> (istream& ist, __int128& val) { LL tmp;  ist >> tmp; val = tmp; return ist; }

ostream& operator<< (ostream& ost, __int128 val) { LL tmp = val; ost << tmp; return ost; }

#endif



#if 1234567891

#include <array>

#include <random>

#include <unordered_set>

#include <unordered_map>

template<typename T>

using PriorityQ = priority_queue<T, vector<T>, greater<T> >;

// template <class T>

// auto Is(const T& value) { return [value](const auto& comparand) -> bool { return comparand == value; }; }

#endif



int Q;

int T[200000];

int A[200000];

int B[200000];

map<int, int> mp;

SegmentTree<Monoid::Sum<int>> par(18);

SegmentTree<Monoid::Sum<LL>> seg(18);



int arr[200000];

int cnt = 0;

LL sum_b = 0;



PP ans;

const int MAX = 1 << 18;

void Upd(int a, int b) {

	++cnt;

	sum_b += b;

	int idx = mp[a];

	arr[idx] = a;

	par.Update(idx, par.Get(idx) + 1);

	seg.Update(idx, seg.Get(idx) + a);

	

	int lo = -1;

	int hi = MAX;

	const int thres = (cnt + 1) / 2;

	while (hi - lo > 1) {

		int mid = (lo + hi) / 2;

		if (par.Query(0, mid) >= thres) {

			hi = mid;

		} else {

			lo = mid;

		}

	}



	LL sum = 0;

	int opt_x = arr[lo];

	int l = thres;

	int r = cnt - thres;

	sum += seg.Query(hi, MAX);

	sum -= seg.Query(0, lo);

	sum -= LL(opt_x) * par.Query(hi, MAX);

	sum += LL(opt_x) * par.Query(0, lo);

	ans = PP(arr[lo], sum + sum_b);

}



int main() {

	cin >> Q;

	REP(i, 0, Q) {

		cin >> T[i];

		if (T[i] == 1) {

			cin >> A[i] >> B[i];

			mp[A[i]];

		}

	}



	{

		int cnt = 0;

		for (auto&& p : mp) {

			p.second = cnt;

			++cnt;

		}

	}



	REP(i, 0, Q) {

		if (T[i] == 1) {

			Upd(A[i], B[i]);

		} else {

			PP p = ans;

			cout << p.first << ' ' << p.second << endl;

		}

	}

	return 0;

}