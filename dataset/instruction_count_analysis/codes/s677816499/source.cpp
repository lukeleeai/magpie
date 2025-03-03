#include<stdio.h>

#define rep(i,N) for(int i=0;i<(int)N;i++)

const int MOD=1e9+7,MAX=1e6;

static inline int IN(void)

{

  int x=0,f=0,c=getchar();while(c<48||c>57){f^=c==45,c=getchar();}

  while(c>47&&c<58){x=x*10+c-48,c=getchar();}return f?-x:x;

}

static inline int GCD(int a,int b){return !b?a:GCD(b,a%b);}

typedef struct{int SPF[1000001],Primes[168],sz;}Template;

Template P;

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

const char common[]="not coprime",disjoint[]="pairwise coprime",partial[]="setwise coprime";

int vol=0,esc[100][2];

static inline int Divise(int x)

{

  if(!x)return 0;

  rep(i,168)

  {

    if(x%P.Primes[i])continue;

    rep(j,vol){if(esc[j][0]==P.Primes[i]&&esc[j][1])return 0;}

    esc[vol][0]=P.Primes[i],esc[vol++][1]=1;

    while(x%P.Primes[i]==0){x/=P.Primes[i];}

  }

  if(x!=1)

  {

    rep(j,vol){if(esc[j][0]==x&&esc[j][1])return 0;}

    esc[vol][0]=x,esc[vol++][1]=1;

    return 1;

  }

  return 1;

}

int main(void)

{

  int N=IN(),A=0,g=0,flag=0;

  ready();

  rep(i,N){A=IN();g=GCD(g,A);if(!Divise(A)){flag=1;}}

  if(g>1)return puts(common),0;

  if(flag)return puts(partial),0;

  return puts(disjoint),0;

}