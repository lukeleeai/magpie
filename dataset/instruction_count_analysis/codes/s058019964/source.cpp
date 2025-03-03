#include <stdio.h>

#include <iostream>

#include <algorithm>

#include <vector>

#include <cassert>

#include <queue>





using namespace std;



using ll = long long;



ll NAX = 2e5;



struct ST {

  vector<ll> t;

  ST() {

    t.assign(NAX*4+10, 0);

  }





  void build(ll root, ll l, ll r, vector<pair<ll,ll>> & ACid) {

    if (l > r) return ;



    if (l==r) {

      // cout << l << endl;

      if (ACid[l].second < 0) t[root] = 1;

      else t[root] = 0;

      return ;

    }



    ll m = (l + r) / 2;



    build(root*2, l, m, ACid);

    build(root*2+1, m+1, r, ACid);



    t[root] = t[root*2] + t[root*2+1];

  }



  ll sum(ll root, ll l, ll r, vector<pair<ll,ll>> &ACid) {

    if (t[root] == 0) return 0;

    if (l > r) return 0;



    if (l==r) {

      return t[root] * ACid[l].first;

    }



    ll m = (l + r) / 2;



    return sum(root*2, l, m, ACid) +  sum(root*2+1, m+1, r, ACid);

  }

  void add(ll root, ll pos, ll count, ll l, ll r) {

    if (l > r) return ;

    if (l == r && l == pos) {

      t[root] += count;

      return ;

    }





    if (t[root] == 0) {

      t[root*2] = 0;

      t[root*2+1] = 0;

    }



    ll m = (l + r) / 2;

    if (pos <= m) 

    add(root*2, pos, count, l, m);

    else

    add(root*2+1, pos, count, 1+ m, r);



    t[root] = t[root*2] + t[root*2+1];



  }



  void update(ll root, ll pos, ll maxc, ll l, ll r) {

    if (t[root] == 0) return ;

    if (maxc == 0 ) return ;

    if (l > r) return ;



    if (l == r) {

      t[root] = max(0LL, t[root] - maxc);

      return ;

    }



    ll m = (l+ r) / 2;



    if (pos  <= m) {

        update(2*root, pos, maxc, l, m);

    } else {

      if (t[root*2] <= maxc) {

        update(2*root+1, pos, maxc-t[root*2], m+1, r);

        t[root*2] = 0;

      } else {

        update(2*root, pos, maxc, l, m);

      }

    }

    t[root] = t[root*2] + t[root*2+1];

  }



  ll query();

};



int main() {

  ll N, M;



  cin >> N >> M;

  vector<ll> A(N);

  vector<pair<ll,ll>> ACid(N+M);

  for(auto i=0;i<N;i++) {

    cin >> A[i];

    ACid[i].first = A[i];

    ACid[i].second = -i-1;

  }



  vector<ll> B(M);

  vector<ll> C(M);

  for(auto i=0;i<M;i++) {

    cin >> B[i] >> C[i];

    ACid[N+i].first = C[i];

    ACid[N+i].second = i+1;

  }



  sort(ACid.begin(), ACid.end());

  vector<ll> Cmap(M);

  for(auto i = 0; i<M+N; i++) {

    if (ACid[i].second > 0) //

    Cmap[ACid[i].second - 1] = i;

  }



  ST tree;

  tree.build(1, 0, N+M-1, ACid);

  // cout << tree.t[1] << endl;

  for (auto i=0; i<M;i++) {

    tree.update(1,  Cmap[i], B[i], 0, M+N-1);

    // cout << tree.t[1] << endl;

    tree.add(1,  Cmap[i], N-tree.t[1], 0, M+N-1);

    // cout << tree.t[1] << endl;

  }





  cout << tree.sum(1, 0, N+M-1, ACid) << endl;





  return 0;

}
