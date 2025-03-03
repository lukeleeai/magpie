#include "stdc++.h"

using namespace std;



const int MAXN = 100005;



int A[MAXN];



int N, Ans;



int main() {

	ios::sync_with_stdio(false);



	cin >> N;

	for(int i = 1; i <= N; i++)

		cin >> A[i];



	{

		int i = 0;



		for(; i <= N;) {

			bool isu = true, isd = true;

			for(i += 2; i <= N; i++) {

				if(A[i-1] == A[i]) continue;

				if(A[i-1] < A[i]) {

					isd = false;

				} else {

					isu = false;

				}

				if(!isd && !isu) { i--; break; }

			}

			if(N < i) break;

			Ans++;

		}

	}



	cout << (Ans+1) << endl;

	return 0;

}