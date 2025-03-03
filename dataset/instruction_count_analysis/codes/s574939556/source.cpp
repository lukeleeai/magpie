#include "stdc++.h"



using namespace std;



#define For(i,a,b) for(ll i=a;i<b;i++)

#define Ford(i,a,b) for(ll i=a;i>=b;i--)

#define RET(x) { cout << x; exit(0); }

#define smin(a,b) a=min(a,b)

#define smax(a,b) a=max(a,b)

#define SZ(x) ((ll)((x).size()))

#define PB push_back

#define ER(x) cout << #x << ' ' << x << '\n';

#define X first

#define Y second



typedef long long int LL;

typedef LL ll;

typedef vector<ll> vll;

typedef pair<ll,ll> pll;

typedef string str;



const ll M=5e5+5,LG=30,mod=924844033;

ll pw(ll x,ll y){ if (y==0) return 1; return pw(x*x%mod,y/2)*(y&1?x:1)%mod; }



#define MOK(x) if (x>=mod) x-=mod;



struct bignum{

  ll ar[M];

  ll siz=0;

  void read(str s){

    while (SZ(s)){

      ar[siz]=s.back()-'0';

      s.pop_back();

      siz++;

    }

  }

  void mult9(){

    ll e=0;

    For(i,0,siz){

      ll p=ar[i]*9+e;

      e=p/10;

      ar[i]=p%10;

    }

    if (e){

      ar[siz++]=e;

    }

  }

  void plusplus(){

    for (ll i=0;1;i++){

      if (ar[i]!=9){

	ar[i]++;

	if (ar[siz]) siz++;

	return;

      }

      ar[i]=0;

    }

  }

  void decer(){

    ar[siz-1]--;

    while (siz && ar[siz-1]==0) siz--;

  }

  bool is0(){

    return (siz==0);

  }

  void chap(){

    For(i,0,siz) cout << ar[i];

    cout << '\n';

  }

};



bignum n;

  

int main(){

  ios::sync_with_stdio(0);

  str s;

  cin >> s;

  n.read(s);

  n.mult9();

  //n.chap();

  //return 0;

  ll tused=0;

  while (!n.is0()){

    n.plusplus();

    n.decer();

    tused++;

    //ER(tused);

    //n.chap();

    //if (tused>20) return 0;

  }

  RET((tused+8)/9);

}
