#define _USE_MATH_DEFINES

#pragma region include



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

#pragma endregion //#include

/////////



#pragma region typedef

typedef long long LL;

typedef long double LD;

typedef unsigned long long ULL;

#pragma endregion //typedef

////定数

const int INF = (int)1e9 + 10;

const LL MOD = (LL)1e9 + 7;

const LL LINF = (LL)4e18 + 20;

const LD PI = acos(-1.0);

const double EPS = 1e-9; 

/////////

using namespace::std;

//////////////

bool runrun(int X) {

	vector<int> A;

	while (X) {

		A.push_back(X % 10);

		X /= 10;

	}

	int len = A.size();

	if (len == 1) {

		return true;

	}



	bool ans = true;

	for (int i = 0; i < len - 1; ++i) {

		if (abs(A[i] - A[i + 1]) > 1) {

			return false;

		}

	}

	

	return ans;

}

void solve() {

	int K;

	cin >> K;

	vector<LL> A(1001000, 0);

	for (int i = 1; i < 10; ++i) {

		A[i-1] = i;

	}

	int L, R;

	L = 0;//例外

	R = 8;

	int cnt = 9;

	K;

	if (K <= 9) {

		cout << A[K-1] << endl;

		return;

	}

	while (cnt < K) {

		int nextL = R + 1;

		int nextR;

		for (int i = L; i <= R; ++i) {

			LL ter = A[i];

			int base = ter % 10;



			if (base > 0) {

				A[cnt] = ter * 10 + base - 1; ++cnt;

			}

			A[cnt] = ter * 10 + base + 0; ++cnt;

			if (base < 9) {

				A[cnt] = ter * 10 + base + 1; ++cnt;

			}

		}

		nextR = cnt - 1;

		L = nextL;

		R = nextR;

	}

	//sort(A.begin(), A.begin()+K);

	cout << A[K - 1] << endl;

	/*

	int cnt = 0;

	int no = 1;

	while (cnt < 100010) {

		if (runrun(no)) {

			++cnt;

			cout << cnt << " " << no << endl;

		}

		++no;

	}

	*/

}



#pragma region main

signed main(void) {

	std::cin.tie(0);

	std::ios::sync_with_stdio(false);

	std::cout << std::fixed;//小数を10進数表示

	cout << setprecision(16);//小数点以下の桁数を指定//coutとcerrで別	



	solve();

}

#pragma endregion //main()
