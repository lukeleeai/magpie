#include<iostream>

#include<algorithm>

#include<cstring>

using namespace std;

typedef long long ll;



ll gcd(ll a,ll b){ return b?gcd(b,a%b):a; }

ll lcm(ll a,ll b){ return a/gcd(a,b)*b; }



ll n,q,l,r;

ll p[100100];

ll sum[100100], len[100100];

bool use[100100];

const ll mod = 1e9+7;

ll par_sum[50][100100];



ll n_, c[1<<20];



void init(int n){

  n_ = 1;

  while(n_<n)n_*=2;



  for(int i=n_-1;i<2*n_-1;i++){

    if(i-n_+2<=n)c[i] = len[i-n_+2];

    else c[i] = 1;

  }



  for(int i=n_-2;i>=0;i--){

    c[i] = lcm(c[2*i+1],c[2*i+2]);

  }

}



ll query(int a,int b,int k,int l,int r){

  if(r<=a || b<=l)return 1;

  if(a<=l && r<=b)return c[k];

  ll vl = query(a,b,k*2+1,l,(l+r)/2);

  ll vr = query(a,b,k*2+2,(l+r)/2,r);

  return lcm(vl,vr);

}



int main(){

  cin >> n >> q;

  for(int i=1;i<=n;i++)cin >> p[i];



  memset(use,0,sizeof(use));



  for(int i=1;i<=n;i++){

    if(!use[i]){

      ll now = p[i];

      ll tmplen = 1, tmpsum = i;

     

      while(now!=i){

	tmplen++; (tmpsum += now) %= mod;

	now = p[now];

      }



      now = i;

      while(!use[now]){

	use[now] = true;

	len[now] = tmplen;

	sum[now] = tmpsum;

      }

    }

  }



  for(int i=1;i<=45;i++){

    par_sum[i][0] = 0;

    for(int j=1;j<=n;j++){

      if(len[j]==i)par_sum[i][j] = (par_sum[i][j-1] + sum[j]) % mod;

      else par_sum[i][j] = par_sum[i][j-1];

    }

  }



  init(n);



  for(int i=0;i<q;i++){

    cin >> l >> r;

    ll cycle = query(l-1,r,0,0,n_);



    ll res = 0;

    for(int i=1;i<=45;i++){

      res += (((cycle/i)%mod)*(((par_sum[i][r]-par_sum[i][l-1])%mod+mod)%mod))%mod;

      res %= mod;

    }



    cout << res << endl;

  }

}