// C - Guess The Number

#include "stdc++.h"

using namespace std;

#define rep(i,n) for(int i=0;i<(n);++i)

#define NG puts("-1")



int main(){

	int N,M; cin>>N>>M;

	string T(N,'-');

	while(M--){

		int s,c; cin>>s>>c; s--, c+='0';

		if(T[s] !='-' && T[s] != c){ NG; return 0; }

		if(N!=1 && s==0 && c=='0'){ NG; return 0; }

		T[s] = c;

	}



	int ans = 1000;

	rep(i,1000){

		string A = to_string(i);

		if(A.size() != N) continue;

		bool ok = true;

		rep(j,N) if(T[j]!='-' && T[j]!=A[j]){ ok = false; break; }

		if(ok) ans = min(ans, i);

	}

	cout<< ans <<endl;

}