#define _CRT_SECURE_NO_WARNINGS

#include <iostream>	

#include <time.h>

#include <vector>

#include <stdio.h>

#include <memory.h>

#include <string>

#include <string.h>

#include <map>

#include <algorithm>

#include <bitset>

#include <queue>

#include <set>

#include <time.h>

#include <assert.h>

#include <sstream>

//#include <unordered_map>

#include <bitset>

#include <utility>

#include <iomanip>

#include <climits>

#include <cstdio>

#include <cstdlib>

#include <ctime>

#include <numeric>

#include <math.h>

#include <cmath>

#include <complex>

using namespace std;

typedef long long ll;



int n, a, b;

int dp[110][110][2];

int calc(int a, int b, int t) {

	int &ret = dp[a][b][t];

	if(~ret)

		return ret;

	ret = 0;

	if(!t) {

		vector<int>can;

		if(b > 1 && b - 1 != a)

			can.push_back(b - 1);

		if(b + 1 < n && b + 1 != a)

			can.push_back(b + 1);

		if(!can.size())

			ret = 1;

		for(int i = 0; i < can.size() && !ret; ++i)

			ret |= calc(a, can[i], !t);

	}

	else {

		vector<int>can;

		if(a > 1 && a - 1 != b)

			can.push_back(a - 1);

		if(a + 1 < n && a + 1 != b)

			can.push_back(a + 1);

		for(int i = 0; i < can.size() && !ret; ++i)

			ret |= calc(can[i], b, !t);

	}

	return ret;

}



int main() {





	scanf("%d%d%d", &n, &a, &b);

	memset(dp, -1, sizeof dp);

	puts(calc(a, b, 1) ? "Alice" : "Borys");

	



	return 0;

}