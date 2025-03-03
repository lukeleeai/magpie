#include"stdc++.h"

//#include<atcoder/all>



using namespace std;

//using namespace atcoder;

using ll = long long;

using ull = unsigned long long;

using P = pair<int,int>;

#define rep(i,n) for(ll i = 0;i < (ll)n;i++)

#define ALL(x) (x).begin(),(x).end()

#define MOD 1000000007



class Mo{

  public:

  vector<int> l,r,ord;

  vector<bool> is;

  int wid,nl,nr,ptr;

  Mo(int n) : wid((int)sqrt(n)),nl(0),nr(0),ptr(0),is(n){}

  // add queries [l, r)

  void insert(int a,int b){

    l.push_back(a);

    r.push_back(b);

  }

  // after all insert()

  void build(){

    ord.resize(l.size());

    iota(ALL(ord),0);

    sort(ALL(ord),[&](int a,int b){

      if(l[a]/wid != l[b]/wid)return l[a] < l[b];

      if(r[a] == r[b])return l[a] < l[b];

      return bool((r[a] < r[b])^((l[a]/wid) & 1));

    });

  }

  inline int process(){

    if(ptr == ord.size())return -1;

    const int idx = ord[ptr++];

    while(nl < l[idx])distribute(nl++);

    while(nl > l[idx])distribute(--nl);

    while(nr > r[idx])distribute(--nr);

    while(nr < r[idx])distribute(nr++);

    return idx;

  }

  inline void distribute(int idx){

    is[idx].flip();

    if(is[idx])add(idx);

    else del(idx);

  }

  void add(int idx);

  void del(int idx);

};

vector<int> v(500010);

vector<int> cnt(500010);

vector<int> res(500010);

int sum = 0;



inline void Mo::add(int idx){

  cnt[v[idx]]++;

  if(cnt[v[idx]] == 1)sum++;

}

inline void Mo::del(int idx){

  cnt[v[idx]]--;

  if(cnt[v[idx]] == 0)sum--;

}





int main(){

  

  cin.tie(0);

  ios::sync_with_stdio(0);

  int n,Q;

  cin >> n >> Q;

  rep(i,n)cin >> v[i];

  Mo mo(n);

  rep(_,Q){

    int l,r;cin >> l >> r;

    mo.insert(--l,r);

  }

  mo.build();

  rep(_,Q){

    int idx = mo.process();

    res[idx] = sum;

  }

  rep(i,Q)cout << res[i] << "\n";







  return 0;

}