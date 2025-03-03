//#define __USE_MINGW_ANSI_STDIO 0

#include <iostream>

#include "stdc++.h"

#include <ext/pb_ds/assoc_container.hpp> // Common file

#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace __gnu_pbds;

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



typedef tree<

int,

null_type,

less<int>,

rb_tree_tag,

tree_order_statistics_node_update>

ordered_set;



int DP[N][N];

ordered_set S[N];

int W[N], B[N];



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

	}



	for(int i=n; i>=0; i--) {



		for(int j=i+1; j<=n; j++) {

			S[i].insert(B[j]);

		}



		for(int j=n; j>=0; j--) {



			if(j < n) S[i].insert(W[j+1]);



            if(i == n and j == n) continue;

            else if(i == n) DP[i][j] = S[i].order_of_key(W[j+1]) + DP[i][j+1];

            else if(j == n) DP[i][j] = S[i].order_of_key(B[i+1]) + DP[i+1][j];

            else DP[i][j] = min(S[i].order_of_key(B[i+1]) + DP[i+1][j], 

                                S[i].order_of_key(W[j+1]) + DP[i][j+1]);

		}

	}



	cout<<DP[0][0]<<"\n";

	return 0;

}