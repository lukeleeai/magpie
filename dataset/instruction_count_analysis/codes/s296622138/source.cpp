#include "stdc++.h"

#define rep(i, a) for (int i = (int)0; i < (int)a; ++i)

#define rrep(i, a) for (int i = (int)a - 1; i >= 0; --i)

#define REP(i, a, b) for (int i = (int)a; i < (int)b; ++i)

#define RREP(i, a, b) for (int i = (int)a - 1; i >= b; --i)

#define pb push_back

#define eb emplace_back

#define all(x) x.begin(), x.end()

#define rall(x) x.rbegin(), x.rend()

using ll = long long;

constexpr ll mod = 1e9 + 7;

constexpr ll INF = 1LL << 60;



template <class T>

inline bool chmin(T &a, T b)

{

	if (a > b)

	{

		a = b;

		return true;

	}

	return false;

}

template <class T>

inline bool chmax(T &a, T b)

{

	if (a < b)

	{

		a = b;

		return true;

	}

	return false;

}



ll gcd(ll n, ll m)

{

	ll tmp;

	while (m != 0)

	{

		tmp = n % m;

		n = m;

		m = tmp;

	}

	return n;

}



ll lcm(ll n, ll m)

{

	return abs(n) / gcd(n, m) * abs(m); //gl=xy

}



using namespace std;



template<typename T>

vector<T> sieve(T n){//n以下の整数について最小の素因数を調べる

    vector<T>prime(n+1);

		for(int i=0;i<=n;++i)prime[i]=i;

    for(int i=2;i*i<=n;i++){

        if(prime[i]<i)continue;

				for(int j=i*i;j<=n;j+=i){

					if(prime[j]>=i)prime[j]=i;

				}

    }

    return prime;

}



template<typename T>

map< T, int > osa_k(T n,const vector<T>& min_factor){//min_factorはsieveで求めた配列を使う

  map< T, int > ret;

  while(n>1){

		ret[min_factor[n]]++;

		n/=min_factor[n];

	}

  if(n != 1) ret[n] = 1;

  return ret;

}





void solve()

{

	ll n;

	cin>>n;

	vector<ll>v=sieve(n);

	// for(auto x:v){

	// 	cout<<x<<"\n";

	// }

	ll ans=1;

	REP(i,2,n+1){

		ll cul=1;

		for(auto x:osa_k((ll)i,v)){

			cul*=x.second+1;

		}

		ans+=cul*i;

	}

	cout<<ans<<"\n";

}



int main()

{

	ios::sync_with_stdio(false);

	cin.tie(0);

	cout << fixed << setprecision(15);

	solve();

	return 0;

}
