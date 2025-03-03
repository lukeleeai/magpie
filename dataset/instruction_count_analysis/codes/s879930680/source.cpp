#include "stdc++.h"

using namespace std;



template<typename T, typename U>

using pv=vector<pair<T,U>>;

template<typename T>

using pque=priority_queue<T>;

template<typename T>

using lpque=priority_queue<T,vector<T>,greater<T>>;



using ll=long long;

using intpair=pair<int,int>;

using llpair=pair<ll,ll>;

using ilpair=pair<int,ll>;

using lipair=pair<ll,int>;

using intvec=vector<int>;

using llvec=vector<ll>;

using intq=queue<int>;

using llq=queue<ll>;

using intmat=vector<intvec>;

using llmat=vector<llvec>;



#define PI 3.141592653589793

#define INTINF ((1<<30)-1)

#define LLINF ((1LL<<62)-1)

#define MPRIME 1000000007

#define MPRIME9 998244353

#define MMPRIME ((1ll<<61)-1)



#define len length()

#define pushb push_back

#define fi first

#define se second



#define all(name) name.begin(),name.end()

#define rall(name) name.rbegin(),name.rend()

#define gsort(vbeg,vend) sort(vbeg,vend,greater<>())



template<class T>

inline bool chmin(T& a, T b) {

	if (a > b) {

		a = b;

		return true;

	}

	return false;

}



template<class T>

inline bool chmax(T& a, T b) {

	if (a < b) {

		a = b;

		return true;

	}

	return false;

}



template<class T>

inline void init(T& v) {

	for(auto &a: v) cin>>a;

}

template<class T, class U>

inline void init(vector<pair<T,U>>& v) {

	for(auto &a: v) cin>>a.first>>a.second;

}

template<class T, class N>

inline void init(T& v, N n) {

	v.resize(n);

	for(auto &a: v) cin>>a;

}

template<class T, class U, class N>

inline void init(vector<pair<T,U>>& v, N n) {

	v.resize(n);

	for(auto &a: v) cin>>a.first>>a.second;

}



template<class T>

inline void out(T a) {

	cout<<a<<endl;

}

template<class T, class... U>

inline void out(T a, U... alist) {

	cout<<a<<" ";

	out(forward<U>(alist)...);

}



template<class N>

void resiz(N n) {

	//empty

}

template<class N, class T, class... U>

void resiz(N n, T&& hd, U&&... tl) {

	hd.resize(n);

	resiz(n,forward<U>(tl)...);

}



ll binpow(ll a, ll ex, ll p) {

	ll result=1;

	while(ex>0) {

		if(ex&1) result=result*a%p;

		ex>>=1;

		a=a*a%p;

	}

	return result;

}





ll A,B,C;



void input() {

	cin>>A;

}



void solve() {

	cout<<abs(A-1)<<endl;

}



int main() {

	cin.tie(nullptr);

	ios_base::sync_with_stdio(false);

	cout<<fixed<<setprecision(15);

	int t=1;

	while(t) {

		input();

		solve();

		t--;

	}

}
