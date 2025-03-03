#include "stdc++.h"

#define f first

#define s second

#define fore(i,a,b) for(int i = (a), ThxMK = (b); i < ThxMK; ++i)

#define pb push_back

#define all(s) begin(s), end(s)

#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

#define sz(s) int(s.size())

#define ENDL '\n'

using namespace std;

typedef long double ld;

typedef long long lli;

typedef pair<int,int> ii;

typedef vector<int> vi;

typedef vector<lli> vl;

typedef vector<ii> vii;

typedef vector<vi> vvi;

typedef vector<vl> vvl;

#define deb(x) cout << #x": " << (x) << endl;



const int N = 1e3;

const lli INF = 1e18;

const lli MOD = 1e9+7;



vi primes(1,2);

vector<vector<ld>>nk;

void sieve(){

	vi m(N+1,0);

	for(int i = 4; i<N; i+=2)m[i]=1;

	for(int i = 3; i*i<=N; i+=2)if(!m[i])for(int j = i*i; j<N; j+=i)m[j]=1;

	for(int i = 3; i<N; i+=2)if(!m[i])primes.pb(i);

}



void pascal(){

	nk =vector<vector<ld>>(N,vector<ld>(N,0.0));

	fore(i,0,N)nk[i][0]=nk[i][i]=1.0;

	fore(i,1,N)fore(j,1,i)nk[i][j]=nk[i-1][j-1]+nk[i-1][j];

}



lli gcd(lli a, lli b){return (b?gcd(b,a%b):a);}



lli lcm(lli a, lli b){

	if(a<b)swap(a,b);

	lli c = gcd(a,b);

	a/=c;

	return a*b;

}



int popcount(lli x) { return __builtin_popcountll(x); }



lli poww(lli a, lli b){

	lli res =1;

	while(b){

		if(b&1) res = res * a;

		a = a*a;

		b/=2;

	}

	return res;

}



lli powm(lli a, lli b){

	lli res =1;

	while(b){

		if(b&1) res = (res * a)%MOD;

		a = (a*a)%MOD;

		b/=2;

	}

	return res;

}



bool isPrime(lli x){

	if(x==1)return 0;

	for(auto i:primes){

		if(i*i>x)return 1;

		if(x%i==0)return 0;

	}

	return 1;

}





lli SUM(lli a, lli b, lli mod=MOD){

	return (a+b+mod)%mod;

}



lli PROD(lli a, lli b, lli mod=MOD){

	a%=mod; b%=mod;

	return a*b % mod;

}



int dx[4]={0,0,1,-1}, dy[4]={1,-1,0,0};



vvi graph(int n, int m){

	vvi v(n+1);

	fore(i,0,m){

		int a,b; cin>>a>>b;

		v[a].pb(b);

		v[b].pb(a);

	}

	return v;

}



// ---- コーディングはここから！ ('-')7



void solve(){

	int n,mod; cin>>n>>mod;

	vvi v=graph(n,n-1);

	vl dp(n+1,1);

	auto f=[&](auto f, int u, int pr)->void{

		for(auto i:v[u])if(i!=pr)f(f,i,u);

		for(auto i:v[u])if(i!=pr)dp[u] = PROD(dp[u],dp[i]+1,mod);

	};

	f(f,1,1);

	auto g=[&](auto g, int u, int pr, lli up)->void{

		vl pre(1,1),post(1,1);

		for(auto i:v[u])if(i!=pr)pre.pb(PROD(pre.back(),dp[i]+1,mod));

		for(int j = sz(v[u])-1;j>=0; j--){

			int i = v[u][j];

			if(i!=pr)post.pb(PROD(post.back(),dp[i]+1,mod));

		}

		reverse(all(post));

		dp[u]= PROD(dp[u],up,mod);

		int j = 0;

		for(auto i:v[u])

			if(i!=pr){

				g(g,i,u,SUM(PROD(PROD(pre[j],post[j+1],mod),up,mod),1,mod));

				j++;

		}

	};

	g(g,1,1,1);

	fore(i,1,n+1)cout<<dp[i]<<ENDL;



}



int main(){_

	//int t; cin>>t; while(t--)

	solve();

}
