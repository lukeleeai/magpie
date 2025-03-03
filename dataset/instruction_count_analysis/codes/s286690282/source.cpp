#include <iostream>

using namespace std;

typedef long long ll;



const ll m = 1e9+7;

ll sm[400005];

void sm_bulid() {

	sm[0]=1;for(ll i=1;i<400005;i++) sm[i]=sm[i-1]*i%m;

}

ll mod_pow(ll x, ll a) {

	ll an = 1;

	while(a > 0) {

		if (a&1) an = an * x % m;

		x = x * x % m; a >>= 1;

	}

	return an;

}

ll ncr0(ll n, ll r) {

  return sm[n] * mod_pow(sm[n-r], m-2) % m * mod_pow(sm[r], m-2) % m;

}

ll ncr(ll n, ll r) {

  // n*(n-1)*(n-2)*...(n-r+1) / r*(r-1)*...*1

  if (r>n/2) r=n-r;

  ll res=mod_pow(sm[r],m-2) % m;

  for(ll x=n,i=0;i<r;x--,i++) {

    res=res*x%m;

  }

  return res;

}



int main(){

	sm_bulid();

	// nC0+nC1+...+nCn - nC0: 不要分

  // 花束の作り方：a,b,n-a,n-b (n==a+bのとき、a,b)

	ll n,a,b; cin>>n>>a>>b;

	ll an=(mod_pow(2,n)-ncr(n,0)+m*10)%m;

  //an=(an-ncr(n,a)-ncr(n,b)+m)%m;

  //cout<<an<<endl;

  

  an=(an-ncr(n,a)+m)%m;

  //cout<<an<<endl;

  an=(an-ncr(n,b)+m)%m;



  cout<<an<<endl;



}