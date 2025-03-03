#include "stdc++.h"



using namespace std;



#define int long long



const int mod = 1e9+7;

int n,a,b,c,d;

int f[1001][1001];

int fact[1001];

int re_fact[1001];



int p(int a,int b)

{

	if (b == 0)

		return 1;

	int tmp = p(a,b/2);

	if (b%2 == 0) return (tmp * tmp)%mod;

	return ((tmp * tmp)%mod * a)%mod;	

}



int comb(int n,int k)

{

	int tmp = ((fact[n] * re_fact[k])%mod * re_fact[n-k])%mod;

	return tmp;

}



int dp(int rem,int cur)

{

	if (rem == 0)

		return 1;

	if (cur > b)

		return 0;

	if (f[rem][cur] != -1)

		return f[rem][cur];

	int ans = dp(rem,cur + 1);

	for (int j=c;j<=d;j++)

	{

		if (rem - j*cur < 0)

			break;

		ans = (((((dp(rem - j*cur,cur + 1)*fact[j*cur])%mod*p(p(fact[cur],j),mod-2))%mod*re_fact[j])%mod*comb(rem,j*cur))%mod + ans)%mod;						

	}

	return f[rem][cur] = ans;

}



int32_t main()

{

	ios::sync_with_stdio(false);

	cin.tie(0);

	cout.tie(0);

	                 

	fact[0] = 1;

	for (int i=1;i<=1000;i++)

		fact[i] = (fact[i-1] * i)%mod;

	re_fact[1000] = p(fact[1000],mod-2);

	for (int i=1000;i>=1;i--)

		re_fact[i-1] = (re_fact[i] * i)%mod;	

	cin >> n >> a >> b >> c >> d;

	for (int i=0;i<=1000;i++)

		for (int j=0;j<=1000;j++)

			f[i][j] = -1;

	cout << dp(n,a);

}