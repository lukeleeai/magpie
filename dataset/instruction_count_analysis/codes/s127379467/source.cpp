#include"stdc++.h"

#define pb push_back

#define all(v) (v).begin() , (v).end()

#define popcnt(x) __builtin_popcount(x)

#define inf 0x3f3f3f3f

#define watch(x) cout << (#x) << " is " << (x) << endl

#define rand() (rand() << 15 | rand())

using namespace std;

typedef long long  ll;

#define EPS 1e-9

#define PI acos(-1.0)

class dsu {

public:

   vector<int> p;

   vector<int> sz;

   int n , cc;



   dsu(int _n) : n(_n) , cc(_n) {

      p.resize(n);

      sz.resize(n);

      fill(sz.begin() , sz.end() , 1);

      iota(p.begin(), p.end(), 0);

   }



   inline int get(int u) {

      return (u == p[u] ? u : (p[u] = get(p[u])));

   }



   inline bool unite(int u, int v) {

      u = get(u);

      v = get(v);



      if(u == v)return false;



      if(sz[v] < sz[u])swap(u , v);

      p[u] = v;

      sz[v] += sz[u];

      cc--;

      return true;

   }

};





int main() {

   ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

   int n , q;

   long long m;

   cin >> n >> m >> q;

   vector<pair<int , int> > zero , one;

   for(int i = 0 ; i < q  ; ++i){

      int u , v , c;

      cin >> u >> v >> c;

      if(c){

         one.emplace_back(u , v);

      }

      else{

         zero.emplace_back(u , v);

      }

   }

   dsu d(n);

   for(auto e : zero){

      int u = e.first , v = e.second;

      if(d.unite(u , v))m--;

   }

   vector<int> pr(n , -1);

   for(int i = 0 ; i < n ; ++i)

      pr[i] = d.get(i);

   bool need = false;

   for(auto e : one){

      int u = pr[e.first] , v = pr[e.second];

      if(u == v || d.cc <= 2){

         cout << "No\n";

         return 0;

      }

      need = true;

   }

   if(!need){     // bug is here you have to check there is no extra edges

      long long canAdd = 1ll * d.cc * (d.cc - 1) / 2;

      cout << ((m >= (d.cc - 1) && m <= canAdd) ? "Yes" : "No") << "\n";

      return 0;

   }

   m -= d.cc;

   long long rem = 1ll * d.cc * (d.cc - 1) / 2;

   rem -= d.cc;

   cout << ((m < 0 || m > rem) ? "No\n" : "Yes\n");

}