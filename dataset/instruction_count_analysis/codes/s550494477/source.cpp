#include "stdc++.h"

using namespace std;



#define rep(i,x,y) for(int i=(x);i<(y);++i)

#define mp(a,b) make_pair((a),(b))

#define debug(x) #x << "=" << (x)

 

#ifdef DEBUG

#define _GLIBCXX_DEBUG

#define dump(x) std::cerr << debug(x) << " (L:" << __LINE__ << ")" << std::endl

#else

#define dump(x)

#endif



typedef long long int ll;

typedef unsigned long long ull;

typedef pair<int,int> pii;

//template<typename T> using vec=std::vector<T>;



const int INF=1<<30;

const long long int INF_=1LL<<58;

const double EPS=1e-9;

const int dx[]={1,0,-1,0},dy[]={0,1,0,-1};



template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec){

	os << "[";

	for (const auto &v : vec) {

		os << v << ",";

	}

	os << "]";

	return os;

}



const int mod=1e6+7;

bool slot[mod];



void Solve(){

	int n,m;

	string s;

	cin >> n >> m >> s;

	

	ull h[300001],pow[300001],b=1000000007;

	h[0]=0;

	pow[0]=1;

	rep(i,1,n+1){

		h[i]=h[i-1]*b+s[i-1];

		pow[i]=pow[i-1]*b;

	}



	//unordered_set<ull> slot;

	ull a[300001];

	int l=0,r=1,ans=0;

	rep(i,0,m){

		string q;

		cin >> q;

		

		int *d;

		if(q[0]=='L') d=&l;

		else d=&r;

		if(q[1]=='+') ++*d;

		else --*d;



		//slot.insert(h[r]-h[l]*pow[r-l]);

		a[i]=h[r]-h[l]*pow[r-l];

	}



	sort(a,a+m);

	cout << unique(a,a+m)-a << endl;

}



int main(){

	std::ios::sync_with_stdio(false);

	std::cin.tie(0);

	Solve();

	return 0;

}