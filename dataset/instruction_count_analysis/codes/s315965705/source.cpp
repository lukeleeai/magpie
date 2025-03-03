#define _DEBUG

#include "bits/stdc++.h"

#define CHOOSE(a) CHOOSE2 a

#define CHOOSE2(a0,a1,a2,a3,a4,x,...) x

#define debug_1(x1) cout<<#x1<<": "<<x1<<endl

#define debug_2(x1,x2) cout<<#x1<<": "<<x1<<", "#x2<<": "<<x2<<endl

#define debug_3(x1,x2,x3) cout<<#x1<<": "<<x1<<", "#x2<<": "<<x2<<", "#x3<<": "<<x3<<endl

#define debug_4(x1,x2,x3,x4) cout<<#x1<<": "<<x1<<", "#x2<<": "<<x2<<", "#x3<<": "<<x3<<", "#x4<<": "<<x4<<endl

#define debug_5(x1,x2,x3,x4,x5) cout<<#x1<<": "<<x1<<", "#x2<<": "<<x2<<", "#x3<<": "<<x3<<", "#x4<<": "<<x4<<", "#x5<<": "<<x5<<endl

#ifdef _DEBUG

#define debug(...) CHOOSE((__VA_ARGS__,debug_5,debug_4,debug_3,debug_2,debug_1,~))(__VA_ARGS__)

#else

#define debug(...)

#endif

#define rep(index,num) for(int index=0;index<(int)num;index++)

#define rep1(index,num) for(int index=1;index<=(int)num;index++)

#define brep(index,num) for(int index=(int)num-1;index>=0;index--)

#define brep1(index,num) for(int index=(int)num;index>0;index--)

#define scan(argument) cin>>argument

#define prin(argument) cout<<argument<<endl

#define kaigyo cout<<endl

#define eps 1e-7

#define mp(a1,a2) make_pair(a1,a2)

#define ALL(a) (a).begin(),(a).end()

#define rALL(a) (a).rbegin(),(a).rend()

typedef long long ll;

typedef long double ld;

using namespace std;

typedef pair<ll,ll> pll;

typedef pair<int,int> pint;

typedef vector<int> vint;

typedef vector<ll> vll;

typedef vector<pint> vpint;

typedef vector<pll> vpll;

ll INFl=(ll)1e+18+1;

int INF=1e+9+1;

int main(){

	int N;

	ll X[17],Y[17];

	ll P[17];

	scan(N);

	rep(i,N){

		scan(X[i]>>Y[i]>>P[i]);

	}

	ll tate[1<<N][N],yoko[1<<N][N];

	int bitall=(1<<N);

	rep(bit,bitall){

		bool line[N]={};

		rep(i,N){

			if(bit&(1<<i)) line[i]=1;

		}

		rep(i,N){

			ll absxmin=P[i]*abs(X[i]),absymin=P[i]*abs(Y[i]);

			rep(j,N){

				if(line[j]){

					absxmin=min(absxmin,P[i]*abs(X[i]-X[j]));

					absymin=min(absymin,P[i]*abs(Y[i]-Y[j]));

				}

			}

			tate[bit][i]=absxmin,yoko[bit][i]=absymin;

		}

	}

	int pow3=(int)(pow(3,N)+0.5);

	ll ans[N+1];

	fill(ans,ans+N+1,INFl);

	rep(bit,pow3){

		ll sum=0;

		int retu[N];

		int tmp=bit;

		int linenum=0;

		rep(i,N){

			retu[i]=tmp%3;

			linenum+=(tmp%3>0);

			tmp/=3;

		}

		int tatebit=0,yokobit=0;

		rep(i,N){

			if(retu[i]==1) tatebit+=(1<<i);

			if(retu[i]==2) yokobit+=(1<<i);

		}

		rep(i,N){

			sum+=min(tate[tatebit][i],yoko[yokobit][i]);

		}

		ans[linenum]=min(ans[linenum],sum);

	}

	rep(i,N+1){

		prin(ans[i]);

	}

	return 0;

}
