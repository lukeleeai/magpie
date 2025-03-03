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

	srand(time(NULL));

	int N;

	ll X[17],Y[17];

	ll P[17];

	scan(N);

	rep(i,N){

		scan(X[i]>>Y[i]>>P[i]);

	}

	ll oldans=INFl;

	rep(K,N){

		vint p(N);

		rep(i,N-K) p[i]=0;

		for(int i=N-K;i<N;i++) p[i]=1;

		ll ans=oldans;

		do{

			vint ps;

			rep(i,N) if(p[i]) ps.push_back(i);

			if(K<8){

				int bitall=(1<<K);

				rep(bit,bitall){

					vll xlist,ylist,mxlist,mylist;

					xlist.push_back(0);

					ylist.push_back(0);

					mxlist.push_back(0);

					mylist.push_back(0);

					rep(i,K){

						if(bit&(1<<i)){

							xlist.push_back(X[ps[i]]);

							mxlist.push_back(-X[ps[i]]);

						}

						else{

							ylist.push_back(Y[ps[i]]);

							mylist.push_back(-Y[ps[i]]);

						}

					}

					sort(ALL(xlist));

					sort(ALL(ylist));

					sort(ALL(mxlist));

					sort(ALL(mylist));

					ll sum=0;

					rep(i,N){

						if(p[i]==0){

							ll x1,x2,y1,y2;

							if(lower_bound(ALL(xlist),X[i])!=xlist.end()) x1=(*lower_bound(ALL(xlist),X[i]));

							else x1=INFl;

							if(lower_bound(ALL(mxlist),-X[i])!=mxlist.end()) x2=-(*lower_bound(ALL(mxlist),-X[i]));

							else x2=INFl;

							if(lower_bound(ALL(ylist),Y[i])!=ylist.end()) y1=(*lower_bound(ALL(ylist),Y[i]));

							else y1=INFl;

							if(lower_bound(ALL(mylist),-Y[i])!=mylist.end()) y2=-(*lower_bound(ALL(mylist),-Y[i]));

							else y2=INFl;

							sum+=P[i]*min({abs(x1-X[i]),abs(x2-X[i]),abs(y1-Y[i]),abs(y2-Y[i])});

						}

					}

					ans=min(ans,sum);

				}



			}

			else{

				int kaisu=110;

				rep(hoge,kaisu){

					int bit=0;

					rep(i,K){

						if(rand()%2) bit+=(1<<i);

					}

					vll xlist,ylist,mxlist,mylist;

					xlist.push_back(0);

					ylist.push_back(0);

					mxlist.push_back(0);

					mylist.push_back(0);

					rep(i,K){

						if(bit&(1<<i)){

							xlist.push_back(X[ps[i]]);

							mxlist.push_back(-X[ps[i]]);

						}

						else{

							ylist.push_back(Y[ps[i]]);

							mylist.push_back(-Y[ps[i]]);

						}

					}

					sort(ALL(xlist));

					sort(ALL(ylist));

					sort(ALL(mxlist));

					sort(ALL(mylist));

					ll sum=0;

					rep(i,N){

						if(p[i]==0){

							ll x1,x2,y1,y2;

							if(lower_bound(ALL(xlist),X[i])!=xlist.end()) x1=(*lower_bound(ALL(xlist),X[i]));

							else x1=INFl;

							if(lower_bound(ALL(mxlist),-X[i])!=mxlist.end()) x2=-(*lower_bound(ALL(mxlist),-X[i]));

							else x2=INFl;

							if(lower_bound(ALL(ylist),Y[i])!=ylist.end()) y1=(*lower_bound(ALL(ylist),Y[i]));

							else y1=INFl;

							if(lower_bound(ALL(mylist),-Y[i])!=mylist.end()) y2=-(*lower_bound(ALL(mylist),-Y[i]));

							else y2=INFl;

							sum+=P[i]*min({abs(x1-X[i]),abs(x2-X[i]),abs(y1-Y[i]),abs(y2-Y[i])});

						}

					}

					ans=min(ans,sum);

				}

			}

		}while(next_permutation(ALL(p)));

		prin(ans);

		oldans=ans;

	}

	prin(0);

	return 0;

}
