#include "stdc++.h"

using namespace std;

#define endl '\n'

typedef long long ll;



const int maxn = 123;

int n , a[maxn];

bool dp[maxn][10009];



int main()

{

	ios_base::sync_with_stdio(0); cin.tie(NULL);

	cin >> n;

	for(int i=0;i<n;i++) cin >> a[i];

	for(int i=0;i<=n;i++) dp[i][0] = 1;

	for(int i=1;i<=n;i++)

	{

		for(int have=1;have<=10000;have++)

		{

			if(have - a[i-1] >= 0) dp[i][have] = dp[i-1][have] | dp[i-1][have - a[i-1]];

			else dp[i][have] = dp[i-1][have];

		}

	}

	

	for(int i=10000;i>0;i--)

	{

		if(dp[n][i] && i % 10 != 0)

		{

			cout << i << endl;

			return 0;

		}

	}

	cout << 0;

}