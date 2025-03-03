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

const int N = 1e5 + 1;

int sz[N] , p[N] , cc;



void init(){

   iota(p , p + N , 0); // 0 1 2 3 .. N

   fill(sz , sz + N , 1);

}



int f(int u){

   return p[u] = (p[u] == u ? u : f(p[u]));

}



bool unite(int u , int v){

   u = f(u);

   v = f(v);



   if(u == v)return false;

   cc--;

   if(sz[v] < sz[u])swap(u , v);



   p[u] = v;

   sz[v] += sz[u];

   return true;

}



int main() {

   ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

   int n , q;

   long long m;

   cin >> n >> m >> q;

   cc = n;

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

   init();

   for(auto e : zero){

      int u = e.first , v = e.second;

      if(unite(u , v))m--;

   }

   vector<int> pr(n , -1);

   for(int i = 0 ; i < n ; ++i)

      pr[i] = f(i);

   bool need = false;

   for(auto e : one){

      int u = pr[e.first] , v = pr[e.second];

      if(u == v || cc <= 2){

         cout << "No\n";

         return 0;

      }

      need = true;

   }

   if(!need){     // bug is here you have to check there is no extra edges

      long long canAdd = 1ll * cc * (cc - 1) / 2;

      cout << ((m >= (cc - 1) && m <= canAdd) ? "Yes" : "No") << "\n";

      return 0;

   }

   set<pair<int , int> > s;

   for(int i = 0 ; i < n ; ++i){

      int theone = pr[i];

      s.insert({theone , sz[theone]});

   }

   m -= ((int)s.size());

   long long rem = 1ll * cc * (cc - 1) / 2;

   rem -= (int)s.size();

   cout << ((m < 0 || m > rem) ? "No\n" : "Yes\n");

}