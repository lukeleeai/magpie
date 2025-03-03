#include "stdc++.h"

using namespace std;

#define endl '\n'

typedef long long ll;



const int maxn = 123;

int n , a[maxn] , dp[maxn][10009];





int calc(int x , int have)

{

	if(x == n)

	{

		if(have % 10 == 0) return 0;

		else return have;

	}

	if(dp[x][have] != -1) return dp[x][have];

	int ret = 0;

	ret = max(calc(x + 1 , have) , calc(x + 1 , have + a[x]));

	return dp[x][have] = ret;

}



int main()

{

	ios_base::sync_with_stdio(0); cin.tie(NULL);

	memset(dp,-1,sizeof(dp));

	cin >> n;

	for(int i=0;i<n;i++) cin >> a[i];		

	cout << calc(0 , 0) << endl;

}