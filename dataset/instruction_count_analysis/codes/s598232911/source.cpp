#include"stdc++.h"

using namespace std;

typedef long long ll;

typedef pair<ll,ll> pll;

typedef vector<pll> vp;



const ll mod = 1e9+7;

inline ll lcm(ll a, ll b){return a/__gcd(a,b)*b;}



class SegmentTree{

  int n;

  vp node;

public:

  SegmentTree(vp a){

    int n_ = a.size();

    n=1;

    while(n<n_)n*=2;

    node.resize(2*n-1, pll(1, 0));

    for(int i=0;i<n_;i++)node[n-1+i] = a[i];

    for(int i=n-2;i>=0;i--){

      pll vl = node[2*i+1], vr = node[2*i+2];

      ll len = lcm(vl.first, vr.first);

      ll cost = ( (len/vl.first%mod) * vl.second) + ( (len/vr.first%mod) * vr.second);

      node[i] = pll(len,cost%mod);

    }

  }

  

  pll INTV_LCM(int a,int b,int k=0,int l=0,int r=0){

    if(l>=r)r = n;

    if(r<=a || b<=l)return pll(1,0);

    if(a<=l && r<=b)return node[k];

    pll vl = INTV_LCM(a,b,2*k+1,l,(l+r)/2);

    pll vr = INTV_LCM(a,b,2*k+2,(l+r)/2,r);

    ll len = lcm(vl.first, vr.first);

    ll cost = ( (len/vl.first%mod) * vl.second) + ( (len/vr.first%mod) * vr.second);

    return pll(len, cost%mod);

  }

};



int main(){

  int n,q;

  scanf("%d%d",&n,&q);

  vector<int> p(n+1);

  for(int i=1;i<=n;i++)scanf("%d",&p[i]);



  vector<pll> val(n);

  vector<int> use(n+1,0);

  for(int i=1;i<=n;i++){

    if(!use[i]){

      int cur = i;

      ll len = 0, sum = 0;

      

      do{

	len++; sum += p[cur];

	cur = p[cur];

      }while(cur != i);

      

      do{

	val[cur-1] = pll(len,sum%mod);

	use[cur] = 1;

	cur = p[cur];

      }while(cur != i);

    }

  }



  SegmentTree st(val);

  for(int i=0;i<q;i++){

    int l,r;

    scanf("%d%d",&l,&r);

    printf("%lld\n",(st.INTV_LCM(l-1,r)).second);

  }

}