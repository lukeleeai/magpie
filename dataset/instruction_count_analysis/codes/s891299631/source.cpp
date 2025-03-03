#include"stdc++.h"

using namespace std;



typedef long long ll;

typedef pair<ll,int> Pa;



ll N,P,Q;

Pa C[500005];

int main(){

  cin >> N >> P >> Q;

  ll sum = 0;

  for(int i=0;i<N;i++){

    ll c; cin >> c; sum+=c;

    C[i] = Pa( (ll)(Q-i)*P - c , i );

  }

  sort( C, C + N );

  ll res = sum;

  for(int i=N-1;i>-1;i--){

    ll p = N-1-i;

    res = max( res, sum + C[i].first + 2LL*p*P );

    sum = sum + C[i].first + 2LL * p * P;

  }

  cout << res << endl;

}