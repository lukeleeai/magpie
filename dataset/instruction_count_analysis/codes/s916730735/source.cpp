#include<stdio.h>

#pragma GCC optimize("O2")

#pragma GCC optimize("O3")

#pragma GCC target("avx")

#define rep(i,N) for(int i=0;i<(int)N;i++)

#define swap(a,b) (a+=b,b=a-b,a-=b)

const int MOD=1e9+7;

static inline int IN(void)

{

  int x=0,f=0,c=getchar();while(c<48||c>57){f^=c==45,c=getchar();}

  while(c>47&&c<58){x=x*10+c-48,c=getchar();}return f?-x:x;

}

static inline void AscRadix32(int *a,const int sz,const int minus)

{

  int x,shift=0,elem[256],temp[sz];

  while(shift<32)

  {

    int bucket[256]={0};

    rep(i,sz){x=(a[i]>>shift)&255;bucket[x]++;temp[i]=a[i];}

    elem[0]=0;rep(i,255)elem[i+1]=elem[i]+bucket[i];

    rep(i,sz){x=(temp[i]>>shift)&255;a[elem[x]]=temp[i];elem[x]++;}

    shift+=8;

  }

  rep(i,minus/2)swap(a[sz-minus+i],a[sz-1-i]);

  rep(i,(sz-minus)/2)swap(a[i],a[sz-minus-1-i]);

  rep(i,sz/2)swap(a[i],a[sz-1-i]);

}

int main()

{

  int N=IN(),K=IN(),l,m=0,r,accum=1,sign=1,A[N];long x,y;

  rep(i,N)A[i]=IN(),m+=A[i]<0?1:0;

  AscRadix32(A,N,m);

  if(K&1)accum=A[N-1],sign=(A[N-1]<0?-1:1),N--,K--;

  l=0,r=N-1;

  while(K)

  {

    x=1l*A[l]*A[l+1],y=1l*A[r]*A[r-1];

    if(x*sign>y*sign)x%=MOD,accum=1l*accum*x%MOD,l+=2;

    else y%=MOD,accum=1l*accum*y%MOD,r-=2;

    K-=2;

  }

  return printf("%ld\n",(1l*accum%MOD+MOD)%MOD),0;

}