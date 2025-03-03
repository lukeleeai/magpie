#include"stdc++.h" //Ithea Myse Valgulious

namespace chtholly{

typedef long long ll;

#define re0 register int

#define rec register char

#define rel register ll

#define gc getchar

#define pc putchar

#define p32 pc(' ')

#define pl puts("")

/*By Citrus*/

inline int read(){

  int x=0,f=1;char c=gc();

  for (;!isdigit(c);c=gc()) f^=c=='-';

  for (;isdigit(c);c=gc()) x=(x<<3)+(x<<1)+(c^'0');

  return f?x:-x;

  }

template <typename mitsuha>

inline bool read(mitsuha &x){

  x=0;int f=1;char c=gc();

  for (;!isdigit(c)&&~c;c=gc()) f^=c=='-';

  if (!~c) return 0;

  for (;isdigit(c);c=gc()) x=(x<<3)+(x<<1)+(c^'0');

  return x=f?x:-x,1;

  }

template <typename mitsuha>

inline int write(mitsuha x){

  if (!x) return 0&pc(48);

  if (x<0) x=-x,pc('-');

  int bit[20],i,p=0;

  for (;x;x/=10) bit[++p]=x%10;

  for (i=p;i;--i) pc(bit[i]+48);

  return 0;

  }

inline char fuhao(){

  char c=gc();

  for (;isspace(c);c=gc());

  return c;

  }

}using namespace chtholly;

using namespace std;

const int yuzu=2e5,mod=1e9+7;

typedef ll fuko[yuzu|10];

fuko cnt,jic={1},inv;



ll kasumi(ll a,ll b=mod-2){

ll s=1;

for (;b;b>>=1,a=a*a%mod) if (b&1) s=s*a%mod;

return s;

}



ll zuhe(int n,int m){

return jic[n]*inv[m]%mod*inv[n-m]%mod;

}



int main(){

int j,n=read(),m=read(),i;

for (i=1;i<=yuzu;++i) jic[i]=jic[i-1]*i%mod;

inv[yuzu]=kasumi(jic[yuzu]);

for (i=yuzu-1;~i;--i) inv[i]=inv[i+1]*(i+1)%mod;

for (i=2;i*i<=m;++i) 

  if (m%i==0) for (++*cnt;m%i==0;cnt[*cnt]++) m/=i;

if (m>1) cnt[++*cnt]++;

ll ans=1;

for (i=1;i<=*cnt;++i) ans=ans*zuhe(cnt[i]+n-1,cnt[i])%mod;

write(ans);

}