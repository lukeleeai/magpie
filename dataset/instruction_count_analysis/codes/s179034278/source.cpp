#pragma GCC optimize ("O3")

#include "stdc++.h"

#define DEBUG true

#ifdef ONLINE_JUDGE

#undef DEBUG

#define DEBUG false

#endif 



using namespace std;



#define MAXN ((int)2e5+5)

#define MOD ((int)1e9 + 7)

#define INF ((ll)1e9)

#define ll long long

#define _ << " " <<

#define CLEAR(a, b) memset(a, b, sizeof(a))

#define TRACE(x) if(DEBUG) cerr << #x << " = " << x << endl;

#define TRACE2(x,y) if(DEBUG) cerr << #x << " = " << x << " | " << #y << " = " << y << endl;

#define pb push_back

#define all(x) x.begin(), x.end()

#define endl "\n"

#define pii pair<int,int>

#define mid ((l+r)/2)

#define y1 asdasdas



ll s;

ll x1=0,y1=0;

ll x2,x3,y2,y3;



int main()

{

	ios_base::sync_with_stdio(false);cin.tie(0);

	

	cin >> s;



	if(s == (ll)(1e18))

	{

		cout << 0 _ 0 _ 0 _ INF _ INF _ 0 << endl;

		return 0;

	}





	ll sq = sqrt(s) + 1;



	sq = min(sq,INF);



	x2 = sq;

	y2 = 1LL;



	x3 = (sq - (s%sq));

	y3 = (s+x3) / sq;







	assert(x1 <= INF);

	assert(x2 <= INF);

	assert(x3 <= INF);

	assert(y1 <= INF);

	assert(y2 <= INF);

	assert(y3 <= INF);



	cout << x1 _ y1 _ x2 _ y2 _ x3 _ y3 << endl;

}