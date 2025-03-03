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

PP ans;



priority_queue<LL> F;

priority_queue<LL, vector<LL>, greater<LL>> G;

LL X;

LL Y;

void sub(int a) {

	if (a <= F.top()) {

		F.push(a);

		X += a;



		if (F.size() >= G.size() + 2) {

			LL k = F.top(); F.pop();

			G.push(k);

			X -= k;

			Y += k;

		}

	} else {

		G.push(a);

		Y += a;



		if (G.size() >= F.size() + 1) {

			LL k = G.top(); G.pop();

			F.push(k);

			Y -= k;

			X += k;

		}

	}



	LL pos = F.top();

	LL val = (Y - X) - pos * ((int)G.size() - (int)F.size());

	ans = PP(pos, val);

}



int main() {

	F.push(-INF);

	G.push(INF);



	cin >> Q;

	LL sum = 0;

	REP(i, 0, Q) {

		int t;

		cin >> t;

		if (t == 1) {

			int a, b;

			cin >> a >> b;

			sum += b;

			sub(a);

		} else {

			cout << ans.first << ' ' << ans.second + sum << endl;

		}

	}

	return 0;

}