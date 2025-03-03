#include "stdc++.h"



using namespace std;



#define PROBLEM "C"

#define TESTC ""



#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

typedef pair<int, int> P;

#define F first

#define S second

#define INF 0x3f3f3f3f

#define MP make_pair

#define PB push_back

#define MAXN 100005

#define LL long long



LL l[MAXN];

LL r[MAXN];

LL dp[MAXN];



int main()

{

	#ifdef DBG

	freopen(PROBLEM TESTC ".in", "r", stdin);

	freopen(PROBLEM ".out", "w", stdout);

	#endif



	int n;

	while(~scanf("%d",&n))

	{

		int tmp;

		memset(dp, 0, sizeof(dp));

		memset(r,0,sizeof(r));

		memset(l,0,sizeof(l));

		for (int i = 0; i < n; i++)

		{

			scanf("%d",&tmp);

			dp[i] = tmp;

		}

		//算前綴

		l[0] = dp[0];

		for(int i = 1; i < n; i++)

			l[i] = __gcd(l[i-1], dp[i]);

		

		//算後綴

		r[n-1] = dp[n-1];

		for(int i = n-2; i >= 0; i--)

			r[i] = __gcd(r[i+1], dp[i]);



		LL ans = 1;

		//嘗試砍每一個

		for(int i = 1; i < n-1; i++)

			ans = max(__gcd(r[i+1],l[i-1]), ans);

		

		//砍頭砍尾

		ans = max(ans, max(r[1],l[n-2]));





		cout << ans << '\n';



		

	}

	

	



	return 0;

}