// C - GCD on Blackboard

#include "stdc++.h"

using namespace std;



int gcd(int a, int b){

	if(a<b) swap(a,b);

	while(b){int r =a%b; a=b; b=r;}

	return a;

}



int main(){

	int N; cin>>N;

	vector<int> A(N), L(N), R(N), M(N);



	for(int n=0; n<N; ++n) cin>>A[n];

	for(int n=0; n<=N-1-1; ++n) L[n+1] = gcd(L[n], A[n]);

	for(int n=N-1-1; n>=0; --n) R[n] = gcd(R[n+1], A[n+1]);

	for(int n=0; n<N; ++n) M[n] = gcd(L[n], R[n]);



	int maxi = 0;

	for(int n=0; n<N; ++n) maxi = max(maxi,M[n]);

	cout<< maxi <<endl;

}