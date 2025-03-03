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



const ll INF = 1e9+7;







template <typename T>

class RMQ {

	T query(int l, int r, int a, int b, int k){

		if( l <= a && b <= r ){

			return seg[k];

		}else if( l < b && a < r ){

			int m = (b+a)/2;

			T vl = query(l,r, a, m, k*2);

			T vr = query(l,r, m, b, k*2+1);

			return min(vl, vr);	// merge

		}

		return INF;	// default value

	}

public:

	vector<T> seg;	// セグメントツリー (親:k/2  子:k*2,k*2+1)

	int N;

	RMQ(int size){

		N = 1;

		while( N < size ) N<<=1;

		seg.assign(N*2, INF);		// default value

	}

	void update(int pos, T v){

		for(int k=N+pos; k>0; k/=2){

			seg[k] = v;

			v = min(seg[k], seg[k^1]);	// merge

		}

	}

	// [l,r)

	T get(int l, int r){

		return query(l, r, 0, N, 1);

	}

	T get(int pos){		// =get(pos, pos+1)

		return seg[N+pos];

	}

};



int main(){

	//ios_base::sync_with_stdio(false);

	ll N, ans=0;

	ll x[200005], s[200005];



	cin >> N;

	rep(i,N) cin >> x[i] >> s[i];

	x[N] = x[N-1];



	rep(i,N) chmax(ans, s[i]);



//	set<ll> st;

//	map<ll,ll> mp;

//	rep(i,N) st.insert(x[i]);

//	for(auto t: st) mp[t] = mp.size();



	RMQ<ll> sg(200005);

	ll sum = 0;

	sg.update(0,0);

	rep(i,N){

		sum += s[i];

		ll mn  = sg.get(0,i+1);

		chmax(ans, sum - mn);

		ll d = x[i+1] - x[i];

		sum -= d;

		sg.update(i+1, sum);

	}



	cout << ans << endl;



	return 0;

}
