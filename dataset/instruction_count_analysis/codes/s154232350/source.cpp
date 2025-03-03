#include<stdio.h>

#pragma GCC optimize("O2")

#define rep(i,N) for(int i=0;i<(int)N;i++)

const int MOD=1e9+7;

static inline int IN(void)

{

  int x=0,f=0,c=getchar();while(c<48||c>57){f^=c==45,c=getchar();}

  while(c>47&&c<58){x=x*10+c-48,c=getchar();}return f?-x:x;

}

static inline int Mult(int x,int y){long z=x*y-(long)((long double)x/MOD*y+1e-8)*MOD;return z;}

static inline void Radix(int A[],const int N)

{

  int temp[200001];

  rep(k,4)

  {

    int u[256]={},v[256]={};

    rep(i,N)u[A[i]>>8*k&255]++;

    rep(i,255)u[i+1]+=u[i];

    rep(i,N){temp[--u[A[N-1-i]>>8*k&255]]=A[N-1-i];}k++;

    rep(i,N)v[temp[i]>>8*k&255]++;

    rep(i,255)v[i+1]+=v[i];

    rep(i,N)A[--v[temp[N-1-i]>>8*k&255]]=temp[N-1-i];

  }

}

int main()

{

  int N=IN(),K=IN(),m=0,p=0,z=0,accum=1,A[200000];

  rep(i,N){A[i]=IN();if(A[i]>0)p++;else if(A[i]<0)m++;else z++;}

  Radix(A,N);

  if(K==N){if(z){return puts("0"),0;}else{rep(i,K){accum=Mult(accum,A[i]);}K=0;}}

  if(m+p<K)return puts("0"),0;

  if(!p&&K&1){if(z){return puts("0"),0;}else rep(i,K){accum=Mult(accum,A[N-1-i]);}K=0;}

  p+=z,m=p;

  if(K&1){K--;accum=Mult(accum,A[--p]);}

  while(K)

  {

    K-=2;

    if(p>=2&&m<=N-2&&1l*A[p-1]*A[p-2]>1l*A[m]*A[m+1]){accum=Mult(Mult(accum,A[p-1]),A[p-2]),p-=2;continue;}

    if(p>=2&&m<=N-2&&1l*A[p-1]*A[p-2]<1l*A[m]*A[m+1]){accum=Mult(Mult(accum,A[m]),A[m+1]),m+=2;continue;}

    if(p>=2){accum=Mult(Mult(accum,A[p-1]),A[p-2]),p-=2;continue;}

    if(m<=N-2){accum=Mult(Mult(accum,A[m]),A[m+1]),m+=2;continue;}

  }

  return printf("%d\n",accum<0?accum+MOD:accum),0;

}