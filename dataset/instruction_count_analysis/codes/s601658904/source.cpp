#include"stdc++.h"

using namespace std;

//Optimisations

#pragma GCC target ("avx2")

#pragma GCC optimization ("unroll-loops")

#pragma GCC optimize("O2")

//shortcuts for functions

#define pb push_back

#define mp make_pair

#define ff first 

#define ss second

#define all(v) v.begin(),v.end()

#define prec(n) fixed<<setprecision(n)

#define n_l '\n'

// make it python 

#define gcd __gcd

#define append push_back

#define str to_string

// utility functions shortcuts

#define max3(a,b,c) max(a,max(b,c))

#define min3(a,b,c) min(a,min(b,c))

#define sswap(a,b) {a=a^b;b=a^b;a=a^b;}

#define swap(a,b) {auto temp=a; a=b; b=temp;}

#define init(dp) memset(dp,-1,sizeof(dp));

#define set0(dp) memset(dp,0,sizeof(dp));

#define bits(x) __builtin_popcount(x)

#define SORT(v) sort(all(v))

#define endl "\n"

#define forr(i,n) for(ll i=0;i<n;i++)

// declaration shortcuts

typedef long long int ll;

#define int ll

// Constants

constexpr int dx[] = {-1, 0, 1, 0, 1, 1, -1, -1};

constexpr int dy[] = {0, -1, 0, 1, 1, -1, 1, -1};

constexpr ll INF = 1999999999999999997; 

constexpr int inf= INT_MAX;

constexpr int MAXSIZE = int(1e6)+5;

constexpr auto PI  = 3.14159265358979323846L;

constexpr auto oo  = numeric_limits<int>::max() / 2 - 2;

constexpr auto eps = 1e-6;

constexpr auto mod = 1000000007;

constexpr auto MOD = 1000000007;

constexpr auto MOD9 = 1000000009;

constexpr auto maxn = 100006;

//void IOfile(){

//freopen(file_name, reade_mode, stdin);

//freopen(file_name, write_mode, stdout);

//}

void fastio(){

ios_base::sync_with_stdio(false);

cin.tie(NULL);

}



int fac[2*maxn+4];



int ifac[2*maxn+4];





ll mod_pow(ll a,ll b,ll p){ //(a^b)%p

	ll res=1;

	a%=p;



	while(b>0){

		if(b&1==1) res=((res%p)*(a%p))%p;

		a=(a%p*a%p)%p;

		b>>=1;

	}

	return res;

}



//mod_inv=mod_pow(denominator,MOD-2,MOD);



void pre(){

	fac[0] = 1;

	for(int i=1;i<=2*maxn;i++){

		fac[i] = i * fac[i-1];

		fac[i]%=mod;

	}

	ifac[2*maxn] = mod_pow(fac[2*maxn],mod-2,mod);

	for(int i=2*maxn-1;i>=0;i--){

		ifac[i] = (i+1) * ifac[i+1];

		ifac[i]%=mod;

	}

}



int nCr(int n, int r){

	if(r>n) return 0;

	if(r==n) return 1;

	int ans = fac[n];

	ans%=mod;

	ans = ans * ifac[r];

	ans%=mod;

	ans = ans * ifac[n-r];

	ans%=mod;

	return ans;

}



int32_t main(){

	fastio();

	int n,k;

	cin>>n>>k;

	pre();

	int ans = 0;

	int pre = 0, suff = 0;

	for(int i=1;i<=n+1;i++){	

		pre+=i-1;

		suff+=(n+1-i);

		pre%=mod;

		suff%=mod;

		if(i>=k) ans = (ans + suff-pre+1+mod)%mod;

	}

	cout<<ans;

}