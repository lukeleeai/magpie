#include<stdio.h>

#pragma GCC optimize("O2")

#define rep(i,N) for(int i=0;i<(int)N;i++)

#define swap(a,b) (a+=b,b=a-b,a-=b)

static inline int IN(void)

{

  int x=0,f=0,c=getchar();while(c<48||c>57){f^=c==45,c=getchar();}

  while(c>47&&c<58){x=x*10+c-48,c=getchar();}return f?-x:x;

}

static inline void Radix32(int *a,const int sz)

{

  int x,shift=0,elem[0400],temp[sz];

  while(shift<040)

  {

    int bucket[0400]={0};

    rep(i,sz){x=(a[i]>>shift)&0377;bucket[x]++;temp[i]=a[i];}

    elem[0]=0;rep(i,0377)elem[i+1]=elem[i]+bucket[i];

    rep(i,sz){x=(temp[i]>>shift)&0377;a[elem[x]]=temp[i];elem[x]++;}

    shift+=010;

  }

}

int main(void)

{

  int N=IN(),A[N];long sum=0;

  rep(i,N){A[i]=IN();}

  Radix32(A,N);rep(i,N>>1){swap(A[i],A[N-1-i]);}

  rep(i,N-1){sum+=A[(i+1)>>1];}

  return printf("%ld\n",sum),0;

}