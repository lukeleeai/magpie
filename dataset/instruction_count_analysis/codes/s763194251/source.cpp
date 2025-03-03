#include <cstdio>

#include <cstring>

#include <iostream>

#include <string>

#include <cmath>

#include <bitset>

#include <vector>

#include <map>

#include <set>

#include <queue>

#include <deque>

#include <algorithm>

#include <complex>

#include <unordered_map>

#include <unordered_set>

#include <random>

#include <cassert>

#define bitcount __builtin_popcount

#define bitctz __builtin_ctz

using namespace std;

typedef long long int ll;

typedef pair<int, int> P;



int main()

{

	int n, m; double p;

	cin>>n>>m>>p; p/=100;

	int a[100], b[100];

	for(int i=0; i<m; i++){

		cin>>a[i]>>b[i]; a[i]--; b[i]--;

	}

	int ct[1<<14]={};

	for(int i=0; i<(1<<n); i++){

		for(int j=0; j<m; j++){

			if((i&(1<<a[j])) && (i&(1<<b[j]))) ct[i]++;

		}

	}

	double dp[15][1<<14]={};

	for(int i=0; i<n; i++) dp[1][1<<i]=1;

	for(int i=1; i<(1<<n); i++){

		if(bitcount(i)==1) continue;

		int t=bitctz(i);

		for(int j=i; j>0; j=(j-1)&i){

			if((j&(1<<t))==0) continue;

			if(j==i) continue;

			for(int k=1; k<n; k++){

				dp[k+1][i]+=(dp[k][i-j]*dp[1][j]*pow(p, (double)(ct[i]-ct[j]-ct[i-j])));

			}

		}

		dp[1][i]=1;

		for(int k=2; k<=n; k++){

			dp[1][i]-=dp[k][i];

		}

	}

	printf("%.10lf\n", dp[1][(1<<n)-1]);

	return 0;

}
