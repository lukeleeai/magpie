#include<cstdio>

#include<cstdlib>

#include<cstring>

#include<cmath>

#include<cassert>

#include<iostream>

#include<sstream>

#include<string>

#include<vector>

#include<queue>

#include<set>

#include<map>

#include<utility>

#include<numeric>

#include<algorithm>

#include<bitset>

#include<complex>

#include<stack>



using namespace std;



typedef long long Int;

typedef vector<int> vint;

typedef pair<int,int> pint;

typedef vector<string> vstring;

typedef vector<pint> vpint;

typedef stringstream SS;



struct Edge{int to,from,cost;};



#ifdef DEBUG

#define debug cout

#else

SS ss;

#define debug ss

#endif



template<class T> void chmin(T &t, T f) { if (t > f) t = f; }

template<class T> void chmax(T &t, T f) { if (t < f) t = f; }

int in() { int x; scanf("%d", &x); return x; }



#define rep(i,n) for(int i=0;i<(n);++i)

#define repn(i,m,n) for(int i=(m);i<=(n);++i)

#define repd(i,n) for(int i=(n)-1;i>=0;--i)

#define repnd(i,m,n) for(int i=(n);i>=(m);--i)

#define rep0(i,n) for(i=0;i<(n);++i)

#define repn0(i,m,n) for(i=(m);i<=(n);++i)

#define repd0(i,n) for(i=(n)-1;i>=0;--i)

#define repnd0(i,m,n) for(i=(n);i>=(m);--i)

#define all(n) n.begin(),n.end()

#define sz(n) ((int)(n).size())

#define IL for(;;)

#define MP make_pair

#define PB push_back

#define X second

#define Y first

#define PUTLINE debug<<"LINE:"<<__LINE__<<endl;



const int INF = 2147483647/3;

const double EPS = 1e-10;

const double PI = acos(-1.0);



const int dx[]={1,-1,0,0,1,-1,1,-1,0};

const int dy[]={0,0,1,-1,1,-1,-1,1,0};



vstring h(vstring s,int n){

	if(n==0)return s;

	vstring ss;

	ss.PB(s[0]);

	ss.PB(s[3]);

	ss.PB(s[1]);

	ss.PB(s[4]);

	ss.PB(s[2]);

	ss.PB(s[5]);

	return h(ss,n-1);

}



vstring g(vstring s,int n){

	int pos[6][6]={

		{0,1,2,3,4,5},

		{1,5,2,3,0,4},

		{2,1,5,0,4,3},

		{3,1,0,5,4,2},

		{4,0,2,3,5,1},

		{5,4,2,3,1,0},

	};

	vstring res;

	rep(i,6)res.PB(s[pos[n][i]]);

	return res;

}



int main() {

	IL{

		int n;

		cin>>n;

		if(n==0)break;

		vector<vstring> dice;

		vstring rotdice[40][24];

		rep(i,n){

			string s;

			vstring v;

			rep(i,6){

				cin>>s;

				v.PB(s);

			}

			dice.PB(v);

		}

		rep(k,n){

			rep(i,6){

				vstring v=g(dice[k],i);

				rep(j,4){

					rotdice[k][i*4+j]=h(v,j);

				}

			}

		}

		int ng[40]={};

		rep(i,n)repn(j,i+1,n-1){

			rep(k,24){

				if(rotdice[j][k]==dice[i])ng[j]=1;

			}

		}

		int res=0;

		rep(i,n)res+=ng[i];

		cout<<res<<endl;

	}

	return 0;

}