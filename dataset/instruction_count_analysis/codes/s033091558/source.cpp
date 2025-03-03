//#define __USE_MINGW_ANSI_STDIO 0

#include <iostream>

#include "stdc++.h"

using namespace std;



#define debug(x) cout<<#x<<" :: "<<x<<endl;

#define debug2(x,y) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<endl;

#define debug3(x,y,z) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\t"<<#z<<" :: "<<z<<endl;



#define boost ios::sync_with_stdio(0); cin.tie(0)



#define fi first

#define se second

#define pb(x) push_back(x)

#define mp(x,y) make_pair(x,y)



typedef long long ll;

typedef double ld;

typedef pair<int, int> pii;



const int N = 2000 + 5;



/***************************************************************************/



pii A[2*N];

int DP[N][N];

int W[N], B[N];

int BC[N][N], WC[N][N];



int main() {



	boost;



	int n; cin>>n;

	for(int i=1; i<=2*n; i++) {

		char ch; int a; cin>>ch>>a;

		if(ch == 'B') {

			B[a] = i;

		}

		else {

			W[a] = i;

		}

		A[i] = pii(a, (ch == 'B'));

	}



	for(int i=1; i<=2*n; i++) {

		if(A[i].se == 0) continue;

		for(int j=1; j<i; j++) {

			if(A[j].se == 0) continue;

			if(A[j].fi > A[i].fi) BC[A[i].fi][n] += 1;

		}

	}



	for(int i=1; i<=2*n; i++) {

		if(A[i].se == 1) continue;

		for(int j=1; j<i; j++) {

			if(A[j].se == 1) continue;

			if(A[j].fi > A[i].fi) WC[n][A[i].fi] += 1;

		}

	}



	for(int j=0; j<n; j++) {

		int cnt = 0;

		for(int i=1; i<=2*n; i++) {

			if(A[i].se == 0) {

				if(A[i].fi > j) cnt++;

			}

			else {

				BC[A[i].fi][j] = BC[A[i].fi][n] + cnt;

			}

		}

	}



	for(int j=0; j<n; j++) {

		int cnt = 0;

		for(int i=1; i<=2*n; i++) {

			if(A[i].se == 1) {

				if(A[i].fi > j) cnt++;

			}

			else {

				WC[j][A[i].fi] = WC[n][A[i].fi] + cnt;

			}

		}

	}



	for(int i=n; i>=0; i--) {



		for(int j=n; j>=0; j--) {



            if(i == n and j == n) continue;

            else if(i == n) DP[i][j] = WC[i][j+1] + DP[i][j+1];

            else if(j == n) DP[i][j] = BC[i+1][j] + DP[i+1][j];

            else DP[i][j] = min(BC[i+1][j]+ DP[i+1][j], 

                                WC[i][j+1] + DP[i][j+1]);

		}

	}



	cout<<DP[0][0]<<"\n";

	return 0;

}