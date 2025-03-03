/*

How to lambda

  ex) sort(ALL(cont),[](dat a,dat b){return a.l<b.l;});

lower_bound/upper_bound

  1 2 2 2 3 3 

    ^lb   ^ub */

#include "stdc++.h"

#define BR "\n"

#define REP(i,n) for(int (i)=0;(i)<(n);++(i))

#define ALL(cont) begin(cont),end(cont)

#define AS_MOD(a,b) ((((a) % (b) ) + (b)) % (b))

#define FEACH(it,cont) for(auto (it) = begin(cont); it!=end(cont);++it)

#define FEACHR(it,cont) for(auto (it) = rbegin(cont); it!=rend(cont);++it)

#define pb push_back

#define pob pop_back

#define fi first

#define se second

#define getll() ([](){ll s;scanf("%lld", &s);return s;})()

#define getld() ([](){ld s;scanf("%Lf", &s);return s;})()

#define prl(P) printf("%lld", P)

#define prd(P) printf("%.10Lf", P)

#define pr(P) printf(P)

#define assign_if_greater(V, T) V=max(V,T)

using namespace std;

typedef long long ll;

typedef long double ld;

int A,B,Q;

vector<ll> As,Bs,Qs;

ll INF=(ll)1000*1000*1000*1000;

int main() {

  cout << fixed << setprecision(15);

  cin >> A >> B >> Q;

  As.resize(A);Bs.resize(B);Qs.resize(Q);

  REP(i,A)

    As[i]=getll();

  REP(i,B)

    Bs[i]=getll();

  REP(i,Q) {

    ll x=getll();

    auto ita=lower_bound(ALL(As),x);

    auto itb=lower_bound(ALL(Bs),x);

    // only go left

    ll ans=INF;

    vector<ll> alis,blis;

    if (ita!=As.end()) {

      alis.pb(*ita);

    }

    if (itb!=Bs.end()) {

      blis.pb(*itb);

    }

    if (ita!=As.begin()) {

      ita--;

      alis.pb(*ita);

    }

    if (itb!=Bs.begin()) {

      itb--;

      blis.pb(*itb);

    }

    for(ll a:alis)

      for(ll b:blis) {

        ans = min(ans,abs(a-x)+abs(b-a));

        ans = min(ans,abs(b-x)+abs(b-a));

      }

    cout << ans << endl;

  }





  return 0;

}
