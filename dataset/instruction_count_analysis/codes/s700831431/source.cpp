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



	// int ans = 1000;

	// rep(i,1000){

	// 	string A = to_string(i);

	// 	if(A.size() != N) continue;

	// 	bool ok = true;

	// 	rep(j,N) if(T[j]!='-' && T[j]!=A[j]){ ok = false; break; }

	// 	if(ok) ans = min(ans, i);

	// }

	// cout<< ans <<endl;



	// char = '-';

	while(N--){

		if(T[N]=='-'){

			if(T.size()==1){

				T[N] = '0';

			}

			else if(T.size()==2){

				if(N==0){

					T[N] = '1';

				}

				else{// N==1

					T[N] = '0';

				}

			}

			else{// T.size()==3

				if(N==0){

					T[N] = '1';

				}

				else if(N==1){

					T[N] = '0';

				}

				else{// N==2

					T[N] = '0';

				}

			}



		}

		// else{

		// 	T[N] = '0';

		// }

	}

	cout<< stoi(T) <<endl;

}
