#include<stdio.h>

#pragma GCC optimize("Os")

#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define rep(i,N) for(int i=0;i<(int)N;i++)

const int MOD=1e9+7,MAX=1e6;

int A[10000];

static inline char CH()

{

  static char buf[100000],*ptr1=buf,*ptr2=buf;

  return ptr1==ptr2&&(ptr2=(ptr1=buf)+fread(buf,1,100000,stdin),ptr1==ptr2)?EOF:*ptr1++;

}

static inline int IN(void)

{

  int x=0,f=0,c=CH();while(c<48||c>57){f^=c==45,c=CH();}

  while(c>47&&c<58){x=x*10+c-48,c=CH();}return f?-x:x;

}

typedef struct{int SPF[1000001];int Primes[168];int sz;}Template;

Template P;

static inline int MPow(int a,int b){return b?1l*MPow(1l*a*a%MOD,b>>1)*(b&1?a:1)%MOD:1;}

static inline void ready(void)

{

  *P.SPF=1,*P.Primes=2,P.sz=1;

  rep(i,MAX/2)P.SPF[2*(i+1)]=2,P.SPF[2*(i+1)-1]=2*(i+1)-1;

  rep(i,MAX/2-1)

  {

    int x=2*(i+1)+1;if(P.SPF[x]==x){P.Primes[P.sz++]=x;}if(x*x>MAX)break;

    rep(j,P.sz){if(P.Primes[j]<=P.SPF[x]&&x*P.Primes[j]<=MAX)P.SPF[x*P.Primes[j]]=P.Primes[j];else break;}

  }

}

static inline int count(const int prime,const int sz)

{

  int max=0;rep(i,sz){int now=0;while(A[i]%prime==0){now++;A[i]/=prime;}if(max<now)max=now;}return max;

}

int main(void)

{

  int N=IN(),x=0;ready();

  rep(i,N){A[i]=IN();x=(x+1l*MPow(A[i],MOD-2))%MOD;}

  rep(i,168)x=1l*x*MPow(P.Primes[i],count(P.Primes[i],N))%MOD;

  rep(i,N){if(A[i]>1){rep(j,N-1-i){if(A[i]==A[i+j+1]){A[i+j+1]=1;}}x=1l*x*A[i]%MOD;}}

  return printf("%d\n",x),0;

}