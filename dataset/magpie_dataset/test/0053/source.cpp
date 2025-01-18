#include <iostream>

#include <vector>

#include <algorithm>

#include <string.h>

using namespace std;

vector <int> x ;

int n , dp[100003] , k ;

int SAAD ( int idx ) {

	if ( idx == n-1 ) return 0 ;

	if ( dp[idx] != -1 ) return dp[idx] ;

	int res = 1e9 ;

	for ( int i = 1 ; i <= k ; i++ ) {

		if (idx+i<n) res = min(res,SAAD(idx+i)+abs(x[idx]-x[idx+i]));

	}

	return dp[idx] = res ;

}

int main() {

	memset(dp,-1,sizeof(dp));

	int p ;

	cin >> n >> k ;

	for (int i = 0 ; i < n ; i++ ) {

		cin >> p; 

		x.push_back(p);

	}

	cout << SAAD(0) ;

	return 0;

}