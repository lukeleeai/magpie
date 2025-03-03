#include"stdc++.h"

#define ll long long

#define ull unsigned long long

#define IO ios::sync_with_stdio(false), cin.tie(0)

#define endl '\n'

#define main() int main()

#define ff1(i,n) for(int i=1;i<=n;++i)

#define ff0(i,n) for(int i=0;i<n;++i)

#define pi acos(-1.0)

#define ms(a, x) memset(a, x, sizeof(a))

#define lowbit(x) ((x)&(-(x)))

#define pb push_back

#define binarycount __builtin_popcount(x)

#define tr t[root]

#define lson t[root << 1]

#define rson t[root << 1 | 1]

#define fir first

#define sec second

#define debug(x) cout<<x<<'\n'

#define sa(a) scanf("%d", &a)

#define sab(a, b) scanf("%d%d", &a, &b)

#define pa(a) printf("%d",a)

#define pab(a,b) printf("%d%d",a,b)

#define pii pair<string,int>

using namespace std;



#define maxn 1000010

const int inf = 0x3f3f3f3f;

const int mod = 9973;

const double eps = 1e-8;

ll gcd(ll a, ll b) {return b==0?a:gcd(b, a%b);}

ll lcm(ll a, ll b) {return a/gcd(a, b)*b;}

int max(int x,int y){if(x>y) return x;return y;}

ll powmod(ll a,ll b){

    ull ans = 1, pow = a%mod;

    while(b) { if(b&1) ans = (ans*pow)%mod; pow = (pow*pow)%mod; b >>= 1; }

    return ans%mod;

}

ll v[105],w[105];	

ll dp[maxn],n,W,ans;

main()

{

	IO;

	cin>>n>>W;

	for(ll i=1;i<=n;i++){

		cin>>w[i]>>v[i];

	}

	ans=0;

	ms(dp,0x3f);

	dp[0]=0;

	for(int i=1;i<=n;i++){

		for(int j=1e5;j>=v[i];j--){

			dp[j]=min(dp[j],dp[j-v[i]]+w[i]);

			if(dp[j]<=W) ans=max(ans,(ll)j);

		}

	}

	cout<<ans<<endl;

} 