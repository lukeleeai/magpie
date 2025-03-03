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



template<class t, class u> void chmax(t&a,u b){if(a<b)a=b;};

template<class t, class u> void chmin(t&a,u b){if(a>b)a=b;};

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



  ll H, W, h, w;

  IN(H,W,h,w);



  if(H%h==0 && W%w==0){

    OUT("No");

    return 0;

  }



  ll P =   99999999;

  ll N = -100000000;





  printf("Yes\n");

  REP(i,H){

    REP(j,W){

      if(i%h==h-1 && j%w==w-1){

        printf("%lld ", N);

      }else if(i%h==0 && j%w==0){

        printf("%lld ", P);

      }else{

        printf("0 ");

      }

    }

    printf("\n");

  }

  return 0;

}