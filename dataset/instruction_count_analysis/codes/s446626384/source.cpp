#include<stdio.h>

#pragma GCC optimize("O2")

#define rep(i,N) for(int i=0;i<(int)N;i++)

static inline int IN(void)

{

  int x=0,f=0,c=getchar();while(c<48||c>57){f^=c==45,c=getchar();}

  while(c>47&&c<58){x=x*10+c-48,c=getchar();}return f?-x:x;

}

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

  int i=0,N=IN(),A[200000];long sum=0;

  while(i<N){A[i++]=IN();}

  Radix(A,N);

  i=1;while(i<N){sum+=A[N-1-i++/2];}

  return printf("%ld\n",sum),0;

}