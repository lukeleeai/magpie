

#include"stdc++.h"

using namespace std;



typedef long long ll;

typedef pair<ll,int> Pa;



struct BIT{

  int d[500005];

  int n;

 void init(int _n){

   n = _n;

   memset(d,0,sizeof(d));

 }

  // i?????????x???????????? ???1????????°?????????

  void add(int i, int x){

    while(i <= n){

      d[i] += x;

      i += i & -i;

    }

  }



  // a1??????ai?????§???????¨?????±???????

  int sum(int i){

    int s = 0;

    while(i > 0){

      s += d[i];

      i -= i & -i;

    }

    return s;

  }

};



ll N,P,Q;

BIT bit;

Pa C[500005];

int main(){

  cin >> N >> P >> Q;

  ll sum = 0;

  for(int i=0;i<N;i++){

    ll c; cin >> c; sum+=c;

    C[i] = Pa( (ll)(Q-i)*P - c , i );

  }

  sort( C, C + N );

  bit.init(N);

  ll res = sum;

  for(int i=N-1;i>-1;i--){

    ll p = N-1-i;

    // cout << C[i].second << endl;

    //cout << sum << " " << C[i].first << " " << p << " = " << sum + C[i].first + 2LL*p*P << endl;

    res = max( res, sum + C[i].first + 2LL*p*P );

    sum = sum + C[i].first + 2LL * p * P;

    bit.add( C[i].second+1, 1 );

  }

  cout << res << endl;

}