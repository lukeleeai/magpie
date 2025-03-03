// D - Not Divisible

#include "stdc++.h"

using namespace std;

using vi = vector<int>;

#define rep(i,n) for(int i=0;i<(int)(n);++i)



int main(){

	int N; cin>>N;

	vi A(N);

	vi l(1000000+1, 0);

	vi c(1000000+1, 0);

	// int mn = 0;

	int mx = 0;

	rep(i, N){

		int a; cin>>a;

		A[i] = a;

		// mn = min(mn, a);

		mx = max(mx, a);

		c[a]++;

	}



	for(int a:A){

		for(int i=a*2; i<=mx; i+=a) l[i] = 1;

	}



	int ans = 0;

	for(int a:A){

		if(!l[a] && c[a] <= 1) ans++;

	}

	cout<< ans <<endl;

}
