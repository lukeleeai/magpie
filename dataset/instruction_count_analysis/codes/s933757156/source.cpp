#define _USE_MATH_DEFINES



#include <iostream>

#include <iomanip>

#include <stdio.h>



#include <sstream>

#include <algorithm>

#include <iterator>

#include <cmath>

#include <complex>



#include <string>

#include <cstring>

#include <vector>

#include <bitset>



#include <queue>

#include <set>

#include <map>

#include <stack>

#include <list>



#include <ctime>

////

//#include <random>//

/////////



typedef long long LL;

typedef long double LD;

typedef unsigned long long ULL;



////定数

const int INF = (int)1e9 + 10;

const LL MOD = (LL)1e9 + 7;

const LL LINF = (LL)4e18 + 20;

const LD PI = acos(-1.0);

const double EPS = 1e-9; 

/////////

using namespace::std;

void chmax(LL& a, LL b) {

	a = max(a, b);

}

//////////////



void solve() {

	int K;

	cin >> K;

	

	vector<LL> A = { 1,2,3,4,5,6,7,8,9 };

	int L = 0;

	int R = 8;

	

	while (R+1 < K) {

		

		for (int i = L; i <= R; ++i) {

			LL ter = A[i];

			LL base = ter % 10;

			if (base - 1 >= 0) {

				A.push_back(ter * 10 + (base - 1));

			}

			A.push_back(ter * 10 + base);

			if (base + 1 <= 9) {

				A.push_back(ter * 10 + (base + 1));

			}

		}

		L = R + 1;

		R = A.size() -1;

	}

	cout << A[K - 1] << endl;

}



signed main(void) {

	std::cin.tie(0);

	std::ios::sync_with_stdio(false);

	std::cout << std::fixed;//小数を10進数表示

	cout << setprecision(16);//小数点以下の桁数を指定//coutとcerrで別	



	solve();

}
