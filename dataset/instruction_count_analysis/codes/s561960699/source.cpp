#include "stdc++.h"

#define FOR(i,a,b) for(int i=(a);i<(b);i++)

#define REP(i,a) FOR(i,0,a)

	

using namespace std;



const int MAX_N=1e5;



int N,A[MAX_N];



int main(){

	cin>>N;

	int mx=0,mn=N;

	REP(i,N){

		cin>>A[i];

		mx=max(mx,A[i]);

		mn=min(mn,A[i]);

	}

	bool flg;

	if (mx-mn>1){

		flg=false;

	}else if (mx==mn){

		if (A[0]==N-1 || A[0]<=N/2){

			flg=true;

		}else{

			flg=false;

		}

	}else{

		int n1=0,n2=0;

		REP(i,N){

			if (A[i]==mx){

				n1++;

			}else{

				n2++;

			}

		}

		if (mx-n2>0 && mx-n2<=n1/2){

			flg=true;

		}else{

			flg=false;

		}

	}

	cout<<(flg ? "Yes"  : "No")<<endl;

	return 0;

}
