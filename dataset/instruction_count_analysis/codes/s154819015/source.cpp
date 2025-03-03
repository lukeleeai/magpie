#include "stdc++.h"

#define int long long int

#define mod(x) ((x % MOD) + MOD) % MOD

#define FOR(i,a,b) for(int i=(a);i<(b);++i)

#define FORE(i,a,b) for(int i=(a);i<=(b);++i)

#define RFOR(i,a,b) for(int i=(b)-1;i>=(a);--i)

#define RFORE(i,a,b) for(int i=(b);i>=(a);--i)

#define REP(i,n) FOR(i,0,n)

#define ALL(c) (c).begin(),(c).end()

#define RALL(c) (c).rbegin(),(c).rend()

#define SORT(c) sort(ALL(c))

#define RSORT(c) sort(RALL(c))

#define SZ(c) (int)((c).size())

#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)

#define LB(c,x) (int)(lower_bound(ALL(c),x)-(c).begin())

#define UB(c,x) (int)(upper_bound(ALL(c),x)-(c).begin())

#define COUNT(c,x) (UB(c,x)-LB(c,x))

#define UNIQUE(c) SORT(c); (c).erase(unique(ALL(c)),(c).end());

#define COPY(c1,c2) copy(ALL(c1),(c2).begin())

#define EXIST(s,e) (bool)((s).find(e)!=(s).end())

#define PB push_back

#define MP make_pair

#define DUMP(x)  cerr << #x << " = " << (x) << endl;

using namespace std;

template<typename T1, typename T2> using P = pair<T1,T2>;

template<typename T> using V = vector<T>;

struct edge { int from, to; int cost; };

bool operator< (const edge &edge1, const edge &edge2) { return edge1.cost < edge2.cost; };

const int INF = 1e18;

const int MOD = 1e9+7;



template<typename T> ostream& operator << (ostream& s, const V<T>& v) {

   s << "[";

   for (int i = 0; i < v.size(); i++) { s << v[i]; if (i < v.size() - 1) s << " "; }

   s << "]";

   return s;

}



class UnionFind

{

   private:

      vector<int> par, myrank;

   public:

      UnionFind(int n) {

         par.resize(n);

         myrank.resize(n, 0);

         for (int i = 0; i < n; i++) {

            par[i] = i;

         }

      }

      int find(int x) {

         if (par[x] == x) return x;

         return par[x] = find(par[x]);

      }

      void unite(int x, int y) {

         x = find(x);

         y = find(y);

         if (x == y) return;

         if (myrank[x] < myrank[y]) {

            par[x] = y;

         } else {

            par[y] = x;

            if(myrank[x] == myrank[y]) myrank[x]++;

         }

      }

      bool same(int x, int y)

      {

         return find(x) == find(y);

      }

};



signed main()

{

   int N, M; cin >> N >> M;

   V<int> p(N);

   REP(i, N) {

      cin >> p[i];

      p[i]--;

   }

   V<int> x(M), y(M);

   REP(i, M) {

      cin >> x[i] >> y[i];

      x[i]--; y[i]--;

   }



   UnionFind uni(N);

   REP(i, M) {

      uni.unite(x[i], y[i]);

   }



   int ans = 0;

   REP(i, N) {

      if (uni.same(i, p[i])) {

         ans++;

      }

   }

   cout << ans << endl;



   return 0;

}
