#include "stdc++.h"

#define rep(i,n) for(int i=0;i<(n);++i)

#define ALL(A) A.begin(), A.end()



using namespace std;



typedef long long ll;

typedef pair<int, int> P;



const int MAX_N = (int)1e5 + 5;



bool used[MAX_N];	// この数字を使ったかどうか

bool cand[MAX_N];	// この桁が１引く事によって変化するかどうか



int main()

{

	memset(used, false, sizeof(used));

	

	ios_base::sync_with_stdio(0);

	cin.tie(0);

	int N; cin >> N;

	vector<int> a(N, 0);

	rep (i, N) cin >> a[i];



	int res = 0;

	for(int digit = 31; digit >= 0; --digit){

		memset(cand, false, sizeof(cand));

		int cnt = 0;

		rep (i, N){

			if (a[i] & (1<<digit)){

				++cnt;

				if (!used[i] && !((a[i] - 1) & (1<<digit))) cand[i] |= true;

			} // end if

		} // end rep



		if (cnt % 2 == 0){ 

			rep (i, N) used[i] |= cand[i]; // 1 引いて変化するものはもう使えない。よって"使った"にフラグ。

		}else{

			bool one = false;

			rep (i, N){

				if (!used[i] && cand[i]){

					if (!one){

						--a[i];

						++res;

						one |= true;

					} // end if

					used[i] |= true;

				} // end if

			} // end rep

			if (!one){ // 一個もない

				res = -1;

				break;

			} // end if

		} // end if

	} // end for

	cout << res << endl;



	return 0;

}