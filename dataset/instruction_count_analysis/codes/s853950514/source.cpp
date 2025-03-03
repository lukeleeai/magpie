#include "stdc++.h"

using namespace std;



#define pb		push_back

#define eb		emplace_back

#define mk		make_pair

#define fi		first

#define se		second

#define cc(x)	cout << #x << " = " << x << endl

#define ok		cout << "ok" << endl

#define endl	'\n'



typedef long long ll;

typedef pair<int,int> ii;

const int INF = 0x3f3f3f3f;

const double PI = acos(-1.0);

 

const ll N = 1e5 + 10;

ll dp[N], p[N], v[N];

ll n, w;



int main() {

    	ios_base::sync_with_stdio(false);



	memset(dp, -INF, sizeof dp);    

	cin >>n >>w;



	for(int i = 0; i < n; i++){

		cin >>p[i] >>v[i];

	}



	dp[0] = 0;

	for(int i = 0; i < n; i++){

		for(int j = N-1; j-p[i] >= 0; j--){

			dp[j] = max(dp[j], dp[j-p[i]] + v[i]);

		}

	}



	ll ans = 0;

	for(int i = 0; i <= w; i++) ans = max(ans, dp[i]);



	cout <<ans <<endl;

    	return 0;

}
