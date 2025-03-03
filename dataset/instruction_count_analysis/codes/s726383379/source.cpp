/*

 * ARC097_C.cpp

 *

 *  Created on: May 14, 2018

 *      Author: 13743

 */



#include<cstring>

#include<iostream>

#include<algorithm>

#include<vector>

#include<stack>

#include<queue>

#include<string>

using namespace std;

typedef long long llong;



#define PB push_back

#define SZ(a) int((a).size())

#define ALL(a) (a).begin(), (a).end

#define FOR(i, a, b) for(int i=(a); i<(b); ++i)

#define REP(i, n) FOR(i,0,n)

#define UNIQUE(a) a.erase(unique(ALL(a)), a.end())



int code[25000];

bool used[25000];



int powI(int x, int n) {

	int ans = 1;

	while(n--) {

		ans *= x;

	}

	return ans;

}



int main() {

	cin.tie(0);

	ios::sync_with_stdio(false);



	char str[5010];

	int K;

	cin >> str;

	cin >> K;



	int sLen = strlen(str);

	REP(i, sLen) {

		REP(j, 5) {

			REP(k, j+1) {

				if(i+k < sLen) {

					code[5*i+j] += (str[i+k]-'a'+1)*powI(50, 4-k);

				}

			}

		}

	}

	int minI = -1;

	while(K--) {

		int minS = 1<<30;

		REP(i, 5*sLen) {

			if(!used[i] && code[i]<minS) {

				minS = code[i];

				minI = i;

			}

		}

		REP(i, 5*sLen) {

			if(code[i] == minS) {

				used[i] = true;

			}

		}

	}

	int s = minI / 5;

	int t = minI % 5;

	REP(i, t+1) {

		cout << str[s+i];

	}

	cout << endl;

}






