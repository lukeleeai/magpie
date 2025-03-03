#include "stdc++.h"



#define rep(i,n) for(int i=0; i<(n); i++)

#define reps(i,x,n) for(int i=x; i<(n); i++)

#define rrep(i,n) for(int i=(n)-1; i>=0; i--)

#define all(X) (X).begin(),(X).end()

#define X first

#define Y second

#define pb push_back

#define eb emplace_back



using namespace std;

typedef long long int ll;

typedef pair<int,int> pii;

typedef pair<ll,ll> pll;



template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }

template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }



template<class A, size_t N, class T> void Fill(A (&a)[N], const T &v){ fill( (T*)a, (T*)(a+N), v ); }



const ll INF = 1e18+7;





int main(){

	//ios_base::sync_with_stdio(false);

	ll N, ans=0;

	ll x[200005], s[200005];



	cin >> N;

	rep(i,N) cin >> x[i] >> s[i];



	ll sum = 0, mn = 0;

	rep(i,N){

		sum += s[i];

		chmax(ans, sum - mn);

		ll d = x[i+1] - x[i];

		sum -= d;

		chmin(mn, sum);

	}



	cout << ans << endl;



	return 0;

}
