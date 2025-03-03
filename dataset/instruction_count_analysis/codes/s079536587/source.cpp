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





struct Mo{

  using F = function<void(int)>;

  vector<int> l,r,ord;

  int n,wid,nl,nr,ptr;

  F expandL,expandR;

  F shrinkL,shrinkR;

  Mo(int n,int wid,F expandL,F expandR,F shrinkL,F shrinkR):

    n(n),wid(wid),nl(0),nr(0),ptr(0),

    expandL(expandL),expandR(expandR),shrinkL(shrinkL),shrinkR(shrinkR){}

  Mo(int n,int wid,F expand,F shrink){

    *this = Mo(n,wid,expand,expand,shrink,shrink);

  }

  // add queries [l, r)

  inline void add(int a,int b){

    l.emplace_back(a);

    r.emplace_back(b);

  }

  // after all add()

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

    if(ptr == (int)ord.size())return -1;

    const int idx = ord[ptr++];

    while(nl > l[idx])expandL(--nl);

    while(nr < r[idx])expandR(nr++);

    while(nl < l[idx])shrinkL(nl++);

    while(nr > r[idx])shrinkR(--nr);

    return idx;

  }

};





int main(){

  

  cin.tie(0);

  ios::sync_with_stdio(0);

  int n,Q;

  cin >> n >> Q;

  vector<int> v(n);

  rep(i,n)cin >> v[i];

  int sum = 0;

  vector<int> cnt(n+1);

  auto expand = [&](int k){

    sum += cnt[v[k]]++==0;

  };

  auto shrink = [&](int k){

    sum-=--cnt[v[k]]==0;

  };

  Mo mo(n,1000,expand,shrink);

  rep(_,Q){

    int a,b;cin >> a >> b;

    mo.add(--a,b);

  }

  vector<int> res(Q);

  mo.build();

  rep(_,Q){

    int idx = mo.process();

    res[idx] = sum;

  }

  rep(i,Q)cout << res[i] << "\n";







  return 0;

}