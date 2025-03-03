#include"stdc++.h"

#include<iostream>

using namespace std;

#define mn 100005

#define FLN "code"

#define endl "\n"

#define int long long

#define fi first

#define se second

#define inf 4444444444444444444

#define mod 1000000009

#define FOR(i, a, b) for (int i=a; i<(b); i++)

#define FOR0(i, a) for (int i=0; i<(a); i++)

#define FOR1(i, a) for (int i=1; i<=(a); i++)

#define codenhanh(); ios_base::sync_with_stdio(0) ,cin.tie(0),cout.tie(0);



int n,m,a[mn];

int dem=0;

vector<int> sum;

signed main()

{

	#ifdef komandocode

	freopen("code.inp", "r", stdin);

	freopen("code.out", "w", stdout);

	#endif

	codenhanh();

	cin>>n;

	cin>>m;

	int dp[60][3000];

	memset(dp, 0, sizeof(dp));

	dp[0][0]=1;

	for(int i=1;i<=n;i++){

		cin>>a[i];

			for(int j=i-1;j>=0;j--)

			{

				for(int p=0;p<=55*j;p++){

					dp[j+1][a[i]+p]+=dp[j][p];

				}	

			}

			}

            



	int ans=0;

	for(int i=1;i<=n;i++)

	{

		ans+=dp[i][i*m];

	}

	cout<<ans;

return 0;

}


