#include "stdc++.h"

// #include <atcoder/all>

#define ll long long int

#define ld long double

#define yorn(f) std::cout<<((f)?"Yes":"No")<<endl;

#define YORN(f) std::cout<<((f)?"YES":"NO")<<endl;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

#define repi(i, n) for (int i = 1; i < (int)(n); i++)

#define all(x) (x).begin(), (x).end()

#define put(x) std::cout << x << endl;

#define println(x) std::cout << x << endl;

template<typename T>bool mins(T& x,const T&y){if(x>y){x=y;return true;}else return false;}

template<typename T>bool maxs(T& x,const T&y){if(x<y){x=y;return true;}else return false;}

using namespace std;

// using namespace atcoder;

int N;

ll A[303];



void Main()

{

	int i,j,k,l,r,x,y; string s;

	

	cin>>N;

	rep(i,N) cin>>A[i];

	ll xo=0;

	for(i=2;i<N;i++) xo^=A[i];

	

	vector<int> cand;

	rep(i,1<<20) if(i<A[0]) {

		ll v=(A[0]-i)^(A[1]+i)^xo;

		if((v&((1<<20)-1))==0) cand.push_back(i);

	}

	

	ll mi=1LL<<50;

	for(auto c : cand) {

		for(ll a=c;a<min(mi,A[0]);a+=1<<20) {

			ll v=(A[0]-a)^(A[1]+a)^xo;

			if(v==0) mi=min(mi,a);

		}

	}

	

	if(mi==1LL<<50) mi=-1;

	cout<<mi<<endl;

}

signed main(){ Main();return 0;}