# include "stdc++.h"



# define pb push_back

# define fr first

# define sc second

# define mk make_pair



using namespace std;



const int inf = 1e9 + 7;

const int N = 2e5 + 5;



typedef long long ll;



int n, a[N], cnt;

pair <int, int> t[N * 4][2];

pair <int, int> v[N];

vector <int> g[N];

set < pair <int, int> > st;



void build(int v = 1, int tl = 1, int tr = n)

{

      if(tl == tr)

      {

            t[v][tl % 2] = mk(a[tl], tl);

            t[v][(tl % 2) ^ 1] = mk(inf, 0);

      }

      else

      {

            int tm = (tl + tr) >> 1;

            build(v << 1, tl, tm);

            build((v << 1) | 1, tm + 1, tr);

            t[v][0] = min(t[v << 1][0], t[(v << 1) | 1][0]);

            t[v][1] = min(t[v << 1][1], t[(v << 1) | 1][1]);

      }

}



pair <int, int> get(int l, int r, int type, int v = 1, int tl = 1, int tr = n)

{

      if(l > tr || tl > r) return mk(inf, 1);

      if(l <= tl && tr <= r) return t[v][type];

      int tm = (tl + tr) >> 1;

      return min(get(l, r, type, v << 1, tl, tm),

                        get(l, r, type, (v << 1) | 1, tm + 1, tr));

}



void dv(int l, int r, int p = 0)

{

      if(l >= r) return ;

      int c = ++ cnt;

      if(l + 1 == r)

      {

            if(p != 0) g[p].pb(c);

            else st.insert(mk(a[l], c));

            v[c] = mk(l, r);

            return ;

      }

      int aa = get(l, r - 1, l % 2).sc;

      int bb = get(aa + 1, r, (l % 2) ^ 1).sc;

      if(p != 0) g[p].pb(c);

      else st.insert(mk(a[aa], c));

      v[c] = mk(aa, bb);

      dv(l, aa - 1, p);

      dv(aa + 1, bb - 1, c);

      dv(bb + 1, r, p);

}



int main()

{

      cin >> n;



      for(int i = 1; i <= n; i ++)

            cin >> a[i];



      build();

      dv(1, n);



      while(!st.empty())

      {

            pair <int, int> vv = *st.begin();

            st.erase(st.begin());

            cout << vv.fr << " " << a[v[vv.sc].sc] << " ";

            for(int to : g[vv.sc])

                  st.insert(mk(a[v[to].fr], to));

      }

}
