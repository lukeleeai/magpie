#include"stdc++.h"

using namespace std;

typedef long long ll;

typedef long double ld;

typedef pair<ll,ll> P;

typedef pair<int,int> Pi;

#define rep(i, n) for (ll i = 0; i < n; i++)

#define FOR(i, a, b) for (ll i = a; i < b; i++)

#define fi first

#define se second

#define endl "\n"



template<typename T> inline bool chmax(T &a, T b){if(a<b){a=b;return true;}return false;}

template<typename T> inline bool chmin(T &a, T b){if(a>b){a=b;return true;}return false;}

template<typename T> ostream& operator<<(ostream& s,const complex<T>& d) {return s<<"("<<d.real()<<", "<<d.imag()<< ")";}

template<typename T1, typename T2> ostream& operator<<(ostream& s,const pair<T1,T2>& d) {return s<<"("<<d.first<<", "<<d.second<<")";}

template<typename T> ostream& operator<<(ostream& s, const vector<T>& d){

	int len=d.size();

	rep(i,len){

		s<<d[i];if(i<len-1) s<<" ";

	}

	return s;

}

template<typename T> ostream& operator<<(ostream& s,const vector<vector<T>>& d){

	int len=d.size();

	rep(i,len){

		s<<d[i]<<endl;

	}

	return s;

}

template<typename T> ostream& operator<<(ostream& s,const set<T>& v){

	s<<"{ ";

	for(auto itr=v.begin();itr!=v.end();++itr) {

		if (itr!=v.begin()) {s<< ", ";}

		s<<(*itr);

	}

	s<<" }";

	return s;

}

template<typename T1, typename T2> ostream& operator<<(ostream& s,const map<T1,T2>& m){

	s<<"{"<<endl;

	for(auto itr=m.begin();itr!=m.end();++itr){

		s<<" "<<(*itr).first<<" : "<<(*itr).second<<endl;

	}

	s<<"}"<<endl;

	return s;

}



const ll mod=1e9+7;

const ll inf=1e17;

const int INF=1e9;

const double PI=acos(-1);

const double EPS=1e-10;



const int V=100010;

int n;

vector<vector<int>> g(2*V+10);

vector<bool> used(2*V+10,false);

P cnt;



void dfs(int v){

	if(used[v]) return ;

	used[v]=true;

	if(v>=V) cnt.se++;

	else cnt.fi++;

	for(auto itr:g[v]){

		dfs(itr);

	}

}



int main(){

	cin.tie(0);

	ios::sync_with_stdio(false);

	cin>>n;

	vector<int> a(n),b(n);

	rep(i,n){

		int x,y;

		cin>>x>>y;

		y+=V;

		a[i]=x,b[i]=y;

		g[x].push_back(y);

		g[y].push_back(x);

	}

	ll ans=0;

	rep(i,n){

		cnt.fi=cnt.se=0;

		dfs(a[i]);

		ans+=cnt.fi*cnt.se;

	}

	cout<<ans-n<<endl;

}