#include "stdc++.h"

using namespace std;

typedef long long ll;

ll n,p,Q;



ll calc(ll a,ll l,ll n){return (a+l)*n/2;}



int main(){

  cin>>n>>p>>Q;

  vector<ll> V;

  

  for(int i=0;i<n;i++){

    ll C;

    cin>>C;

    V.push_back(C-p*(Q+i)-2*p*(n-i-1));

  }



  sort(V.begin(),V.end(),greater<ll>());

  ll sum = p*calc(Q,Q+n-1,n);

  ll ans = sum;

  for(int i=0;i<n;i++){

    sum += V[i]+ 2*p*i ;

    ans =max(ans,sum);

  }

  cout<<ans<<endl;

  return 0;

}