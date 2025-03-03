#include "stdc++.h"

// #include <atcoder/all>

#define ll long long int

#define ld long double

#define yorn(f) std::cout<<((f)?"Yes":"No")<<endl;

#define YORN(f) std::cout<<((f)?"YES":"NO")<<endl;

#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

#define repi(i, n) for (ll i = 1; i < (ll)(n); i++)

#define all(x) (x).begin(), (x).end()

#define put(x) std::cout << x << endl;

#define println(x) std::cout << x << endl;

template<typename T>bool mins(T& x,const T&y){if(x>y){x=y;return true;}else return false;}

template<typename T>bool maxs(T& x,const T&y){if(x<y){x=y;return true;}else return false;}

using namespace std;

// using namespace atcoder;



ll A[301];



void Main()

{

    ll n;

    cin >> n;

    rep(i, n) cin >> A[i];



    ll X = 0; // target xor

    for (ll i = 2; i < n; i++) X ^= A[i];



	// vector<int> cand;

	// rep(i,1<<20) if(i<A[0]) {

	// 	ll v=(A[0]-i)^(A[1]+i)^X;

	// 	if((v&((1<<20)-1))==0) cand.push_back(i);

	// }

	

	// ll mi=1LL<<50;

	// for(auto c : cand) {

	// 	for(ll a=c;a<min(mi,A[0]);a+=1<<20) {

	// 		ll v=(A[0]-a)^(A[1]+a)^X;

	// 		if(v==0) mi=min(mi,a);

	// 	}

	// }



	// if(mi==1LL<<50) mi=-1;

	// cout<<mi<<endl;



    vector<ll> cand;

    ll mask = (1LL << 20) - 1;

    rep(a, 1LL << 20) {

        if (a > A[0]) {

            break;

        }

        ll v = (A[0]-a)^(A[1]+a)^X;

        if ((v & mask) == 0) {

            cand.push_back(a);

        }

    }



    ll ma = -1;

    for (ll a1: cand) {

        for (ll a = a1; a < A[0]; a += 1LL << 20) {

            ll v = (A[0]-a)^(A[1]+a)^X;

            if (v == 0) {

                ma = max(ma, A[0]-a);

                break;

            }

        }

    }



    if (ma < 0) {

        put(-1);

        return;        

    }



    ll res = A[0] - ma;

    put(res);

}

signed main(){ Main();return 0;}