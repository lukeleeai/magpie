#include"stdc++.h"

using namespace std;



typedef long long ll;

typedef vector<ll> vll;

typedef vector<vector<ll>> vvll;

typedef vector<vector<vector<ll>>> vvvll;

typedef vector<bool> vb;

typedef vector<vector<bool>> vvb;

typedef vector<vector<vector<bool>>> vvvb;

typedef pair<ll, ll> pll;

typedef vector<pll> vpll;

typedef vector<vpll> vvpll;

typedef vector<double> vd;

typedef vector<vd> vdd;



typedef pair<double, double> pd;

typedef vector<pd> vpd;





#define FOR(i,x,y) for(ll i=(ll)x; i<(ll)y; ++i)

#define REP(i,y) FOR(i, 0, y)

#define RFOR(i,x,y) for(ll i=(ll)x; i>=(ll)y; --i)

#define RREP(i,x) RFOR(i, x, 0)

#define ALL(a) a.begin(), a.end()

#define pb push_back

#define debug_print(x...) cerr << "line " << __LINE__ << " : "; debug_print_in(x);



template <typename First>

void debug_print_in(First first){

  cerr << first << endl;

  return;

}



template <typename First, typename... Rest>

void debug_print_in(First first, Rest... rest){

  cerr << first << " ";

  debug_print_in(rest...);

  return;

}



void IN(void){

  return;

}



template <typename First, typename... Rest>

void IN(First& first, Rest&... rest){

  cin >> first;

  IN(rest...);

  return;

}



template <typename First>

void OUT(First first){

  cout << first << endl;

  return;

}



template <typename First, typename... Rest>

void OUT(First first, Rest... rest){

  cout << first << " ";

  OUT(rest...);

  return;

}



template<class t, class u> t chmax(t&a,u b){if(a<b)a=b; return a;};

template<class t, class u> t chmin(t&a,u b){if(a>b)a=b; return a;};

int popcount(int t){return __builtin_popcount(t);} //GCC

int popcount(ll t){return __builtin_popcountll(t);} //GCC



template <typename T>

void vec_print(vector<T> VEC){

  REP(i, VEC.size()){

    cerr << VEC[i] << " ";

  }

  cerr << endl;

};



template <typename T>

void mat_print(vector<vector<T> > MAT){

  REP(i,MAT.size()){

    REP(j,MAT[i].size()){

      cerr << MAT[i][j] << " ";

    }

    cerr << endl;

  }

};



constexpr int INF = (1<<30);

constexpr ll INFLL = 1LL<<62;

constexpr long double EPS = 1e-12;

constexpr ll MOD = (ll)((1E+9)+7);



int main(){

  cin.tie(0); // cut the cin and cout (default, std::flush is performed after std::cin)

  ios::sync_with_stdio(false); // cut the iostream and stdio (DON'T endl; BUT "\n";)



  ll N;

  IN(N);

  vpll V(N);

  vll P(N);

  REP(i,N){

    IN(P[i]);

    V[i].first = P[i];

    V[i].second = i;

  }



  sort(ALL(V));

  reverse(ALL(V));



  vll F1(N, -1), F2(N, -1), B1(N, N), B2(N, N);



  set<ll> st;



  REP(i,N){

    ll index = V[i].second;

    st.emplace(index);

    auto itr1 = st.find(index);

    auto itr2 = itr1;



    itr1++;

    if(itr1!=st.end()){

      B1[index]=*itr1;

      itr1++;

      if(itr1!=st.end()){

        B2[index]=*itr1;

      }

    }



    if(itr2!=st.begin()){

      itr2--;

      F1[index]=*itr2;

      if(itr2!=st.begin()){

        itr2--;

        F2[index]=*itr2;

      }

    }



    debug_print(V[i].first, V[i].second, F2[index], F1[index], B1[index], B2[index]);

  }



  ll ans = 0;



  REP(i,N){

    ll C = 0;

    C = (F1[i]-F2[i])*(B1[i]-i) + (B2[i]-B1[i])*(i-F1[i]);

    debug_print(i, F2[i], F1[i], B1[i], B2[i], C);

    ans += P[i] * C;

  }



  OUT(ans);



  return 0;

}