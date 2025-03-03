#include "stdc++.h"



using namespace std;



typedef unsigned long long ll;

typedef vector<int> vi;

typedef vector<ll> vl;

typedef pair<int,int> pii;

typedef pair<ll,ll> pll;



typedef int _loop_int;

#define REP(i,n) for(_loop_int i=0;i<(_loop_int)(n);++i)

#define FOR(i,a,b) for(_loop_int i=(_loop_int)(a);i<(_loop_int)(b);++i)

#define FORR(i,a,b) for(_loop_int i=(_loop_int)(b)-1;i>=(_loop_int)(a);--i)



#define DEBUG(x) cout<<#x<<": "<<x<<endl

#define DEBUG_VEC(v) cout<<#v<<":";REP(i,v.size())cout<<" "<<v[i];cout<<endl

#define ALL(a) (a).begin(),(a).end()



#define CHMIN(a,b) a=min((a),(b))

#define CHMAX(a,b) a=max((a),(b))



int n;

pair<pii,pii> cubes[525];



int main(){

  scanf("%d",&n);

  REP(i,n){

    int a,b,c,d;

    scanf("%d%d%d%d",&a,&b,&c,&d);

    cubes[i] = make_pair(pii(a,b),pii(c,d));

  }

  typedef pii E;

  typedef pair<pii,pii> S;

  // one edge, another edge, [count, multiple]

  map<E, map<E,pii> > edges;

  // surface, [count, multiple]

  map<S, pii> surfaces;



  // surface to edges

  map<S,set<pair<E,E> > > s2e;

  // surface to surfaces

  map<S,set<S> > s2s;



  {

    int a[4];

    REP(i,n){

      map<pii,map<pii,int> > ae;

      map<pair<pii,pii>,int> as;

      a[0] = cubes[i].first.first;

      a[1] = cubes[i].first.second;

      a[2] = cubes[i].second.first;

      a[3] = cubes[i].second.second;

      REP(_,4){

        E e = pii(a[0],a[1]);

        E oe = pii(a[2],a[3]);

        S s = make_pair(pii(a[0],a[1]),pii(a[2],a[3]));

        ae[e][oe]+=1;

        as[s]+=1;

        swap(a[0],a[1]);

        swap(a[1],a[2]);

        swap(a[2],a[3]);

      }

      REP(_,4){

        E e = pii(a[0],a[1]);

        E oe = pii(a[2],a[3]);

        S s = make_pair(pii(a[0],a[1]),pii(a[2],a[3]));

        if(ae[e][oe]>0){

          edges[e][oe].first += 1;

          edges[e][oe].second = ae[e][oe];

          ae[e][oe] = 0;

        }

        if(as[s]>0){

          surfaces[s].first += 1;

          surfaces[s].second = as[s];

          as[s] = 0;

        }

        for(auto _s:as){

          S s = _s.first;

          s2e[s].insert(make_pair(e,oe));

        }

        swap(a[0],a[1]);

        swap(a[1],a[2]);

        swap(a[2],a[3]);

      }

      for(auto _s:as){

        S s = _s.first;

        for(auto _t:as){

          S t = _t.first;

          s2s[s].insert(t);

        }

      }

    }

  }

  ll ans = 0;

  // 1. determine first surface(a,b,c,d)

  for(auto _s1:surfaces){

    S s1 = _s1.first;

    ll u1 = _s1.second.first * _s1.second.second;

    int a = s1.first.first;

    int b = s1.first.second;

    int c = s1.second.first;

    int d = s1.second.second;

    // decrement

    for(S s:s2s[s1])surfaces[s].first--;

    for(pair<E,E> e:s2e[s1])edges[e.first][e.second].first--;

    // 2. determine second surface(e,f)

    E e1 = pii(b,a);

    for(auto _e2:edges[e1]){

      E e2 = _e2.first;

      ll u2 = u1 * _e2.second.first * _e2.second.second;

      if(u2==0)continue;

      int e = e2.first;

      int f = e2.second;

      // decrement

      S s2 = make_pair(e1,e2);

      for(S s:s2s[s2])surfaces[s].first--;

      for(pair<E,E> e:s2e[s2])edges[e.first][e.second].first--;

      // 3. determine third surface(g,h)

      E e3 = pii(d,c);

      for(auto _e4:edges[e3]){

        E e4 = _e4.first;

        ll u3 = u2 * _e4.second.first * _e4.second.second;

        if(u3==0)continue;

        int g = e4.first;

        int h = e4.second;

        // decrement

        S s3 = make_pair(e3,e4);

        for(S s:s2s[s3])surfaces[s].first--;

        for(pair<E,E> e:s2e[s3])edges[e.first][e.second].first--;

        // 4,5,6 the other 3 surfaces

        S s4 = make_pair(pii(a,d),pii(h,e));

        S s5 = make_pair(pii(e,h),pii(g,f));

        S s6 = make_pair(pii(c,b),pii(f,g));

        // s4

        ll u4 = u3 * surfaces[s4].first * surfaces[s4].second;

        for(S s:s2s[s4])surfaces[s].first--;

        for(pair<E,E> e:s2e[s4])edges[e.first][e.second].first--;

        // s5

        ll u5 = u4 * surfaces[s5].first * surfaces[s5].second;

        for(S s:s2s[s5])surfaces[s].first--;

        for(pair<E,E> e:s2e[s5])edges[e.first][e.second].first--;

        // s4

        ll u6 = u5 * surfaces[s6].first * surfaces[s6].second;

        for(S s:s2s[s6])surfaces[s].first--;

        for(pair<E,E> e:s2e[s6])edges[e.first][e.second].first--;

        // add

        ans += u6;

        // s4

        for(S s:s2s[s4])surfaces[s].first++;

        for(pair<E,E> e:s2e[s4])edges[e.first][e.second].first++;

        // s5

        for(S s:s2s[s5])surfaces[s].first++;

        for(pair<E,E> e:s2e[s5])edges[e.first][e.second].first++;

        // s4

        for(S s:s2s[s6])surfaces[s].first++;

        for(pair<E,E> e:s2e[s6])edges[e.first][e.second].first++;

        // s3

        for(S s:s2s[s3])surfaces[s].first++;

        for(pair<E,E> e:s2e[s3])edges[e.first][e.second].first++;

      }

      for(S s:s2s[s2])surfaces[s].first++;

      for(pair<E,E> e:s2e[s2])edges[e.first][e.second].first++;

    }

    for(S s:s2s[s1])surfaces[s].first++;

    for(pair<E,E> e:s2e[s1])edges[e.first][e.second].first++;

  }

  printf("%llu\n",ans/24);

  return 0;

}
