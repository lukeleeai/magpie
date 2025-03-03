#include"stdc++.h"

using namespace std;

typedef long long ll;

typedef long double ld;

#define rep(i, n) for (ll i = 0; i < n; i++)

#define FOR(i, a, b) for (ll i = a; i < b; i++)

#define is(a, b) a == b

#define len(v) ll(v.size())



//vector書き出し

template <class T>

void cout_vec(const vector<T> &vec1){

  rep(i,len(vec1)){

    cout<<vec1[i]<<' ';

  }

  cout<<'\n';

}



typedef pair<ll,ll> P;

const ll mod=1e9+7;



int main(){

    cin.tie(0);

    ios::sync_with_stdio(false);

    ll x;

    cin>>x;

    vector<ll> sum;

    sum.push_back(1);

    ll cnt=2;

    while(sum.back()<=1e9){

      sum.push_back(cnt+sum.back());

      cnt++;

    }

    cout<<lower_bound(begin(sum),end(sum),x)-begin(sum)+1<<endl;

}