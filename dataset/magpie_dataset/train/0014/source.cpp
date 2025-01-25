#include <iostream>

#include <cstdio>

#include <cmath>

#include <cstdlib>

#include <map>

#include <set>

#include <queue>

#include <algorithm>

#include <cstring>

#include <cmath>

#include <sstream>

#include <vector>

#include <string>

#include <iomanip>

#include <bitset>

#define INF	100000000

#define pb	push_back

#define fi first

#define sec second

#define SS stringstream

using namespace std;

typedef pair<int, int> P;

typedef long long int	ll;



int w, n;

int t = 0;

int dp[1001][1001];

vector<P> vec;



int rec(int i, int j){

	if(dp[i][j] >= 0) return dp[i][j];

	int res;

	if(i == n) res = 0;

	else if(j < vec[i].sec) res = rec(i+1, j);

	else res = max(rec(i+1, j), rec(i+1, j-vec[i].sec)+vec[i].fi);

	return dp[i][j] = res;

}



int main(){

	while(scanf("%d", &w)){

		t++;

		if(w == 0) break;

		memset(dp, -1, sizeof(dp));

		scanf("%d", &n);

		for(int i = 0; i < n; i++){

			int temp1, temp2;

			char trash;

			scanf("%d%c%d", &temp1, &trash, &temp2);

			vec.pb(P(temp1, temp2));

		}

		printf("Case %d:\n", t);

		printf("%d\n", rec(0, w));

		for(int i = 1; i <= w; i++){

			if(rec(0, w-i) != rec(0,w)){

				printf("%d\n", w-i+1);

				break;

			}

		}

		vec.clear();

	}

}