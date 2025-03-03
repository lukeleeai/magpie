// Code By H~S~C

#ifdef ONLINE_JUDGE

#pragma GCC optimize(1)

#pragma GCC optimize(2)

#pragma GCC optimize(3)

#pragma GCC optimize(4)

#pragma comment(linker, "/STACK:1024000000,1024000000")

#pragma GCC optimize("Os")

#pragma GCC optimize("Og")

#pragma GCC optimize("Ofast")

#pragma GCC target("avx,sse,sse2,sse3,ssse3,sse4")

#endif

#include <initializer_list>

#include <unordered_set>

#include <unordered_map>

#include <algorithm>

#include <iostream>

#include <utility>

#include <cstdlib>

#include <cstring>

#include <vector>

#include <cstdio>

#include <queue>

#include <stack>

#include <cmath>

#include <map>

#include <set>

#define pb push_back

#define rep(i,n) for (int i=0;i<(n);++i)

#define rep1(i,n) for (int i=1;i<=(n);++i)

#define Rep(i,a,b) for (int i=(a);i<=(b);++i)

#define All(a) a.begin(),a.end()

#define SZ(a) ((int)a.size())

#define sqr(s) ((s)*(s))

#define MP make_pair

#define fillset(a,val) memset(a,val,sizeof(a))

#define X first

#define Y second

#define endl '\n'

using namespace std;

typedef long long ll;

typedef unsigned long long ull;

typedef long double ld;

typedef pair <int,int> pii;

const int inf=0x3f3f3f3f;

const ll lnf=0x3f3f3f3f3f3f3f3f;

const double EPS=1e-9,PI=acos(-1.0);

const int mod1=1000000007,mod2=998244353;

//....................密..........封..........线..........下..........禁..........止..........hack...............................................

const int Maxn=200005;

ll n,d,a[Maxn],dpl[Maxn],dpr[Maxn],ans;

signed main()

{

	ios_base::sync_with_stdio(0);

	cin.tie(nullptr);cout.tie(nullptr);

	cin>>n>>d;rep(i,n) cin>>a[i],ans+=a[i];

	ans+=(n-1)*d;dpl[0]=a[0];dpr[n-1]=a[n-1];

	rep1(i,n-1) dpl[i]=min(a[i],dpl[i-1]+d);

	for (int i=n-2;~i;--i) dpr[i]=min(a[i],dpr[i+1]+d);

	rep1(i,n-2) ans+=min(dpl[i],dpr[i]);

	cout<<ans<<endl;

	return 0;

}