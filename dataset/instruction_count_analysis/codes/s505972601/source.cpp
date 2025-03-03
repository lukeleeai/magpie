// C - GCD on Blackboard

#include "stdc++.h"

using namespace std;

using vi = vector<int>;

#define MAX 100000



int N;

vi A(MAX+1), L(MAX+1), R(MAX+1), M(MAX+1);



int gcd(int a, int b){

	if(a<b) swap(a,b);

	while(b){ int r = a%b; a = b; b = r; }

	return a;

}



int main(){

	cin>>N;

	for(int n=1; n<=N; ++n) cin>>A[n];

	for(int n=0; n<N; ++n) L[n+1] = gcd(L[n], A[n]);

	for(int n=N; n>=0; --n) R[n] = gcd(R[n+1], A[n]);

	for(int n=1; n<=N; ++n) M[n] = gcd(L[n], R[n+1]);

	int maxi = 0;

	for(int n=1; n<=N; ++n) maxi = max(maxi,M[n]);

	cout<< maxi <<endl;

}