// D - Not Divisible

#include "stdc++.h"

using namespace std;

using vi = vector<int>;

#define rep(i,n) for(int i=0;i<(int)(n);++i)



int main(){

	int N; cin>>N;

	vi A(N);

	int mx = 0;

	rep(i, N){

		cin>>A[i];

		mx = max(mx, A[i]);

	}



	vi c(mx+1, 0);

	vi l(mx+1, 0);

	for(int a:A){

		c[a]++;

		for(int i=a*2; i<=mx; i+=a) l[i] = 1;

	}



	int ans = 0;

	for(int a:A) if(!l[a] && c[a] <= 1) ans++;

	cout<< ans <<endl;

}
