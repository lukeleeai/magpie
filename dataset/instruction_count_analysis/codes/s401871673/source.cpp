#include<iostream>

#include<string>

#include<string.h>

#include<algorithm>

#include<stdio.h>

#include<cmath>

#include<vector>

#include<utility>

#include<stack>

#include<queue>

#include<list>

#include<bitset>

#include<functional>



#define FOR(i, a, b) for(int i=(a);i<=(b);i++)

#define RFOR(i, a, b) for(int i=(a);i>=(b);i--)

#define MOD 1000000007

#define INF 1000000000



using namespace std;





int main(void) {

	int n;

	int a, dp[100001] = {};

	int count = 0;



	cin >> n;

	FOR(i, 1, n) {

		cin >> a;

		dp[a]++;

	}

	FOR(i, 1, 100000) {

		if (dp[i] != 0) {

			count++;

		}

	}



	if (count % 2 == 0) {

		cout << count - 1 << endl;

	}

	else {

		cout << count << endl;

	}

	return 0;

}