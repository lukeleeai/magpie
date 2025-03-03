#include "stdc++.h"

using namespace std;



typedef long long vlong;

const int maxn = 55;



int a[maxn];

vlong dp[maxn][101*101], p, n;



vlong knap(int i, int tmp){

	if(i >= n){

		if(tmp % 2 == p)return 1;

		

		else{

			return 0;

		}

	}

	if(dp[i][tmp] == -1){

		vlong ret1 = 0, ret2 = 0;

		ret1 = knap(i+1, a[i]+tmp);

		ret2 = knap(i+1, tmp);

		dp[i][tmp] = ret1 + ret2;

	}

	return dp[i][tmp];

}



int main(int argc, char const *argv[])

{

	cin >> n >> p;

	for(int i = 0;i < n;i++)

		cin >> a[i];



	memset(dp, -1, sizeof dp);

	cout << knap(0, 0) << endl;

}
