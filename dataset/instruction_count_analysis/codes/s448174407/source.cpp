#include"stdc++.h"

using namespace std;



typedef long long ll;

typedef unsigned long long ull;

typedef pair<int,int> pii;

typedef pair<ll, ll> pll;

typedef pair<ull, ull> pullull;

typedef pair<ll, int> plli;

typedef pair<int, pii> pipii;

typedef vector<vector<int> > mati;

typedef vector<vector<double> > matd;

typedef vector<ll> vll;

typedef vector<vector<ll>> vvll;

typedef vector<vector<vector<ll>>> vvvll;

typedef vector<bool> vb;

typedef vector<vector<bool>> vvb;

typedef vector<vector<vector<bool>>> vvvb;

typedef vector<pll> vpll;



#define FOR(i,x,y) for(ll i=(ll)x; i<(ll)y; ++i)

#define REP(i,y) FOR(i, 0, y)

#define RFOR(i,x,y) for(ll i=(ll)x; i>=(ll)y; --i)

#define RREP(i,x) RFOR(i, x, 0)

#define ALL(a) a.begin(), a.end()

#define pb push_back



inline void IN(void){

  return;

}



template <typename First, typename... Rest>

void IN(First& first, Rest&... rest){

  cin >> first;

  IN(rest...);

  return;

}



inline void OUT(void){

  cout << "\n";

  return;

}



template <typename First, typename... Rest>

void OUT(First first, Rest... rest){

  cout << first << " ";

  OUT(rest...);

  return;

}



template <typename T>

void vec_print(vector<T> VEC){

  REP(i, VEC.size()){

    cout << VEC[i] << " ";

  }

  cout << "\n";

};



template <typename T>

void mat_print(vector<vector<T> > MAT){

  REP(i, MAT.size()){

    REP(j, MAT[i].size()){

      cout << MAT[i][j] << " ";

    }

    cout << "\n";

  }

};



template <typename CLASS1, typename CLASS2>

class HOGE{

  public:

    CLASS1 key;

    CLASS2 value;

    HOGE(void){

      return;

    };

    HOGE(CLASS1 key, CLASS2 value){

      this->key = key;

      this->value = value;

    };

    ~HOGE(void){

      return;

    };



    void print(void){

      cout << "key : " << key << ", value : " << value << "\n";

      return;

    };

    

    bool operator==(const HOGE &obj){

      return (this->value == obj.value);

    };

    bool operator<(const HOGE &obj){

      return (this->value < obj.value);

    };

    bool operator>(const HOGE &obj){

      return (this->value > obj.value);

    };

};



template <typename CLASS1, typename CLASS2>

bool operator==(const HOGE<CLASS1, CLASS2> &hoge1, const HOGE<CLASS1, CLASS2> &hoge2){

  return hoge1.value == hoge2.value;

};



template <typename CLASS1, typename CLASS2>

bool operator<(const HOGE<CLASS1, CLASS2> &hoge1, const HOGE<CLASS1, CLASS2> &hoge2){

  return hoge1.value < hoge2.value;

};



template <typename CLASS1, typename CLASS2>

bool operator>(const HOGE<CLASS1, CLASS2> &hoge1, const HOGE<CLASS1, CLASS2> &hoge2){

  return hoge1.value > hoge2.value;

};



constexpr int INF = (1<<30);

constexpr ll INFLL = 1LL<<62;

constexpr long double EPS = 1e-12;

constexpr ll MOD = (ll)((1E+9)+7);



class Segment_Tree{

  private:

    ll n;

    ll n_;

    ll query_type;



  public:

    vector<ll> dat;

    vector<ll> lazy1; //遅延評価 - http://tsutaj.hatenablog.com/entry/2017/03/30/224339

    vector<ll> lazy2; //遅延評価 - http://tsutaj.hatenablog.com/entry/2017/03/30/224339

    vector<bool> lazy1_flag;

    vector<bool> lazy2_flag;

    Segment_Tree(ll n__, ll query_type_=0){

      // For simply, the number of component is set to be power of 2

      // query_type = 0 : min

      // query_type = 1 : max

      // query_type = 2 : sum

      n = 1;

      n_ = n__;

      while(n < n_) n*=2;



      query_type = query_type_;



      lazy1.resize(2*n-1, 0);

      lazy1_flag.resize(2*n-1, false);

      if(query_type==0){

        dat.resize(2*n-1, INFLL);

        lazy2.resize(2*n-1, INFLL);

      }else if(query_type==1){

        dat.resize(2*n-1, -(INFLL-1));

        lazy2.resize(2*n-1, -(INFLL-1));

      }else if(query_type==2){

        dat.resize(2*n-1, 0);

        lazy2.resize(2*n-1, 0);

      }

      lazy2_flag.resize(2*n-1, false);

      return;

    };



    ~Segment_Tree(void){

      return;

    };



    void eval1(ll k, ll l, ll r){

      if(lazy1_flag[k]){

        dat[k] = lazy1[k];



        if(r-l>1){

          if(query_type==0){

            lazy1[2*k+1] = lazy1[k];

            lazy1[2*k+2] = lazy1[k];

          }else if(query_type==1){

            lazy1[2*k+1] = lazy1[k];

            lazy1[2*k+2] = lazy1[k];

          }else if(query_type==2){

            lazy1[2*k+1] = lazy1[k]/2;

            lazy1[2*k+2] = lazy1[k]/2;

          }

        }

        lazy1_flag[2*k+1] = true;

        lazy1_flag[2*k+2] = true;



        lazy1_flag[k] = false;

        if(query_type==0)

          lazy1[k] = INFLL;

        else if(query_type==1)

          lazy1[k] = -(INFLL-1);

        else if(query_type==2)

          lazy1[k] = 0;

      }

    }



    void eval2(ll k, ll l, ll r){

      if(lazy2_flag[k]){

        if(query_type==0)

          dat[k] = min(dat[k], lazy2[k]);

        else if(query_type==1)

          dat[k] = max(dat[k], lazy2[k]);

        else if(query_type==2)

          dat[k] = dat[k]+lazy2[k];



        if(r-l>1){

          if(query_type==0){

            lazy2[2*k+1] = min(lazy2[2*k+1], lazy2[k]);

            lazy2[2*k+2] = min(lazy2[2*k+2], lazy2[k]);

          }else if(query_type==1){

            lazy2[2*k+1] = max(lazy2[2*k+1], lazy2[k]);

            lazy2[2*k+2] = max(lazy2[2*k+2], lazy2[k]);

          }else if(query_type==2){

            lazy2[2*k+1] += lazy2[k] / 2;

            lazy2[2*k+2] += lazy2[k] / 2;

          }

          lazy2_flag[2*k+1] = true;

          lazy2_flag[2*k+2] = true;

        }



        lazy2_flag[k] = false;

        if(query_type==0)

          lazy2[k] = INFLL;

        else if(query_type==1)

          lazy2[k] = -(INFLL-1);

        else if(query_type==2)

          lazy2[k] = 0;

      }

    }



    //k-th value is changed to a

    void update1(ll k, ll a){

      k += n-1;

      dat[k] = a;

      while(k>0){

        k = (k-1)/2;

        if(query_type==0)

          dat[k] = min(dat[k*2+1], dat[k*2+2]);

        else if(query_type==1)

          dat[k] = max(dat[k*2+1], dat[k*2+2]);

        else if(query_type==2)

          dat[k] = dat[k*2+1]+dat[k*2+2];

      }

      return;

    };



    //k-th value is operated of a

    void update2(ll k, ll a){

      k += n-1;

      if(query_type==0)

        dat[k] = min(dat[k], a);

      else if(query_type==1)

        dat[k] = max(dat[k], a);

      else if(query_type==2)

        dat[k] = dat[k]+a;

      while(k>0){

        k = (k-1)/2;

        if(query_type==0)

          dat[k] = min(dat[k*2+1], dat[k*2+2]);

        else if(query_type==1)

          dat[k] = max(dat[k*2+1], dat[k*2+2]);

        else if(query_type==2)

          dat[k] = dat[k*2+1]+dat[k*2+2];

      }

      return;

    };



    //[a,b)の範囲の値をxに変える

    void rangeupdate1(ll a, ll b, ll x, ll k=0, ll l=0, ll r=-1){

      if(r<0) r=n;



      eval1(k,l,r);



      if(r<=a || b<=l){

        return;

      }



      if(a<=l && r<=b){

        if(query_type==0)

          lazy1[k] = x;

        else if(query_type==1)

          lazy1[k] = x;

        else if(query_type==2)

          lazy1[k] = (r-l)*x;

        lazy1_flag[k] = true;

        eval1(k,l,r);

      }else{

        rangeupdate1(a, b, x, 2*k+1, l, (l+r)/2);

        rangeupdate1(a, b, x, 2*k+2, (l+r)/2, r);

        if(query_type==0)

          dat[k] = min(dat[2*k+1], dat[2*k+2]);

        else if(query_type==1)

          dat[k] = max(dat[2*k+1], dat[2*k+2]);

        else if(query_type==2)

          dat[k] = dat[2*k+1] + dat[2*k+2];

      }

      return;

    }



    //[a,b)の範囲に対してxを作用させる

    void rangeupdate2(ll a, ll b, ll x, ll k=0, ll l=0, ll r=-1){

      if(r<0) r=n;



      eval2(k,l,r);



      if(r<=a || b<=l){

        return;

      }



      if(a<=l && r<=b){

        if(query_type==0)

          lazy2[k] = min(lazy2[k], x);

        if(query_type==1)

          lazy2[k] = max(lazy2[k], x);

        if(query_type==2)

          lazy2[k] = lazy2[k] + (r-l)*x;

        lazy2_flag[k] = true;

        eval2(k,l,r);

      }else{

        rangeupdate2(a, b, x, 2*k+1, l, (l+r)/2);

        rangeupdate2(a, b, x, 2*k+2, (l+r)/2, r);

        if(query_type==0)

          dat[k] = min(dat[2*k+1], dat[2*k+2]);

        else if(query_type==1)

          dat[k] = max(dat[2*k+1], dat[2*k+2]);

        else if(query_type==2)

          dat[k] = dat[2*k+1] + dat[2*k+2];

      }

      return;

    }



    // search the minimum of [a, b)

    // Other values are used for simply

    // From outside, call query(a, b, 0, 0, n)

    // k is the node index, 

    // temporary block is [l, r)

    ll query(ll a, ll b, ll k, ll l, ll r){

      //if there are no overlap between [a, b) and [l, r)

      if(r<=a || b<=l){

        if(query_type==0)

          return INFLL;

        else if(query_type==1)

          return -(INFLL-1);

        else if(query_type==2)

          return 0;

      }



      eval1(k,l,r);

      eval2(k,l,r);



      //if [a, b) contains [l, r), return the value of this node

      if(a<=l && r<=b) return dat[k];



      ll vl = query(a, b, k*2+1, l, (l+r)/2);

      ll vr = query(a, b, k*2+2, (l+r)/2, r);

      if(query_type==0)

        return min(vl, vr);

      else if(query_type==1)

        return max(vl, vr);

      else if(query_type==2)

        return vl+vr;

    };



    // search the minimum of [a, b)

    ll query(ll a, ll b){

      if(a<0 || n_<b || a==b){

        fprintf(stderr, "Segment_Tree Search Space Error\n");

        fprintf(stderr, "Desired:\n");

        fprintf(stderr, "%lld <= %lld < %lld <= %lld\n", 0, a, b, n_);

        exit(0);

      }

      return query(a, b, 0, 0, n);

    };

};



ll N;

vll P(100007);

vll L_max(100007, -1), R_max(100007, -1);

vll l_num(2), r_num(2);



ll r_binary_search(Segment_Tree& que, ll l, ll r, ll value){

  if(l==r) return l;

  if(r-l==1){

    if(que.query(l,l+1)>value) return l;

    return r;

  }

  ll mid = (l+r)/2;

  if(que.query(l,mid+1)>value) return r_binary_search(que, l, mid, value);

  return r_binary_search(que, mid, r, value);

}



ll l_binary_search(Segment_Tree& que, ll l, ll r, ll value){

  if(l==r) return r;

  if(r-l==1){

    if(que.query(r,r+1)>value) return r;

    return l;

  }

  ll mid = (l+r)/2;

  if(que.query(mid,r+1)>value) return l_binary_search(que, mid, r, value);

  return l_binary_search(que, l, mid, value);

}



int main(){

  cin.tie(0); // cut the cin and cout (default, std::flush is performed after std::cin)

  ios::sync_with_stdio(false); // cut the iostream and stdio (DON'T endl; BUT "\n";)



  IN(N);

  REP(i,N) IN(P[i]);

  Segment_Tree que(N,1);

  REP(i,N) que.update1(i,P[i]);



  REP(i,N-1){

    L_max[i+1] = max(P[i], L_max[i]);

    R_max[N-2-i] = max(P[N-1-i], R_max[N-1-i]);

  }



  ll ans = 0;



  REP(i,N){

    l_num[0]=0; l_num[1]=0;

    r_num[0]=0; r_num[1]=0;

    if(0<i){

      ll l_index1;

      if(L_max[i]<P[i]) l_index1 = -1;

      else l_index1 = l_binary_search(que, 0, i-1, P[i]);

      l_num[0] = i-l_index1;

      if(l_index1-1>=0){

        que.update1(l_index1, 0);

        ll l_index2;

        if(que.query(0,l_index1)<P[i]) l_index2 = -1;

        else l_index2 = l_binary_search(que, 0, l_index1-1, P[i]);

        l_num[1] = l_index1-l_index2;

        que.update1(l_index1, P[l_index1]);

      }else if(l_index1>=0) l_num[1] = 1;

    }else{

      l_num[0] = 1;

    }

    if(i+1<N){

      ll r_index1;

      if(R_max[i]<P[i]) r_index1 = N;

      else r_index1 = r_binary_search(que, i+1, N-1, P[i]);

      r_num[0] = r_index1-i;

      if(r_index1+1<N){

        que.update1(r_index1, 0);

        ll r_index2;

        if(que.query(r_index1+1,N)<P[i]) r_index2 = N;

        else r_index2 = r_binary_search(que, r_index1+1, N-1, P[i]);

        r_num[1] = r_index2-r_index1;

        que.update1(r_index1, P[r_index1]);

      }else if(r_index1<N) r_num[1] = 1;

    }else{

      r_num[0] = 1;

    }

    //fprintf(stderr, "%lld:%lld %lld %lld %lld\n", i, l_num[1], l_num[0], r_num[0], r_num[1]);

    ans += P[i]*(l_num[0]*r_num[1] + l_num[1]*r_num[0]);

  }



  OUT(ans);



  return 0;

}