#include "stdc++.h"

using namespace std;



#define dump(...) cout<<"# "<<#__VA_ARGS__<<'='<<(__VA_ARGS__)<<endl

#define repi(i,a,b) for(int i=int(a);i<int(b);i++)

#define peri(i,a,b) for(int i=int(b);i-->int(a);)

#define rep(i,n) repi(i,0,n)

#define per(i,n) peri(i,0,n)

#define all(c) begin(c),end(c)

#define mp make_pair

#define mt make_tuple



using uint=unsigned;

using ll=long long;

using ull=unsigned long long;

using vi=vector<int>;

using vvi=vector<vi>;

using vl=vector<ll>;

using vvl=vector<vl>;

using vd=vector<double>;

using vvd=vector<vd>;

using vs=vector<string>;



template<typename T1,typename T2>

ostream& operator<<(ostream& os,const pair<T1,T2>& p){

	return os<<'('<<p.first<<','<<p.second<<')';

}



template<typename Tuple>

void print_tuple(ostream&,const Tuple&){}

template<typename Car,typename... Cdr,typename Tuple>

void print_tuple(ostream& os,const Tuple& t){

	print_tuple<Cdr...>(os,t);

	os<<(sizeof...(Cdr)?",":"")<<get<sizeof...(Cdr)>(t);

}

template<typename... Args>

ostream& operator<<(ostream& os,const tuple<Args...>& t){

	print_tuple<Args...>(os<<'(',t);

	return os<<')';

}



template<typename Ch,typename Tr,typename C>

basic_ostream<Ch,Tr>& operator<<(basic_ostream<Ch,Tr>& os,const C& c){

	os<<'[';

	for(auto i=begin(c);i!=end(c);++i)

		os<<(i==begin(c)?"":" ")<<*i;

	return os<<']';

}



constexpr int INF=1e9;

constexpr int MOD=1e9+7;

constexpr double EPS=1e-9;



vi normalize(vi a)

{

	vi res=a;

	rep(i,3){

		rotate(all(a)-1,end(a));

		res=min(res,a);

	}

	return res;

}



ll count(const vvi& faces)

{

	ll res=1;

	for(vi face:faces)

		if(face[0]==face[2]&&face[1]==face[3]){

			res*=2;

			if(face[0]==face[1])

				res*=2;

		}

	return res;

}



ll npr(int n,int p)

{

	ll res=1;

	rep(i,p) res*=n-i;

	return res;

}



ll calc(const vvi& cs,map<vi,ll>& f,int ti,int bi)

{

	vvi faces={

		normalize(vi{cs[ti][1],cs[ti][0],cs[bi][1],cs[bi][0]}),

		normalize(vi{cs[ti][2],cs[ti][1],cs[bi][0],cs[bi][3]}),

		normalize(vi{cs[ti][3],cs[ti][2],cs[bi][3],cs[bi][2]}),

		normalize(vi{cs[ti][0],cs[ti][3],cs[bi][2],cs[bi][1]}),

	};

	map<vi,int> g;

	for(auto face:faces) g[face]++;

	ll res=count(faces);

	for(auto p:g){

		vi face=p.first;

		int n=f[face]-(face==cs[ti])-(face==normalize(cs[bi]));

		res*=npr(n,p.second);

	}

	return res;

}



int main()

{

	for(int n;cin>>n&&n;){

		vvi cs(n,vi(4));

		rep(i,n){

			rep(j,4) cin>>cs[i][j];

			cs[i]=normalize(cs[i]);

		}



		map<vi,ll> f;

		rep(i,n) f[cs[i]]++;



		ll res=0;

		rep(i,n) repi(j,i+1,n) rep(k,4){

			res+=calc(cs,f,i,j);

			rotate(all(cs[j])-1,end(cs[j]));

		}

		cout<<res/3<<endl;

	}

}
