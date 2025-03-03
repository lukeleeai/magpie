#include"stdc++.h"

using namespace std;

typedef pair<int, int> P;



int main(){

	int N, M;

	cin >> N >> M;

	int d[10] = {0, 2, 5, 5, 4, 5, 6, 3, 7, 6};

	int A[M];

	for(int i=0; i<M; i++){

		cin >> A[i];

	}

//dp[i]・・・i本のマッチ棒をちょうど使って作れる最大桁数，作れないなら-2

	int dp[N+1];

	dp[0] = 0;

	for(int i=1; i<N+1; i++){

		int max = -2;

		for(int j=0; j<M; j++){

			if(i >= d[A[j]]){

				if(max < dp[i - d[A[j]]]){

					max = dp[i - d[A[j]]];

				}

			}

		}

		if(max < 0){

			dp[i] = -2;

		}else{

			dp[i] = max + 1; 

		}

	}

	sort(A, A+M);

	int ans[dp[N]];

	int p = N;

	for(int i=0; i<dp[N]; i++){

		for(int j=M-1; j>=0; j--){

		  if(p >= d[A[j]]){

				if(dp[p] == dp[p-d[A[j]]] + 1){

					ans[i] = A[j];

					p -= d[A[j]];

					break;

				}

			}

		}

	} 

	for(int i=0; i<dp[N]; i++){

		cout << ans[i];

	}

    cout << endl;

	return 0;

}
