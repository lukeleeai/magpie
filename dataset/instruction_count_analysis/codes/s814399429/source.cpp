#include<stdio.h>

typedef long long LL;

const int sz=2e5;

int A[sz]={0},town[sz]={0};

inline LL IN(void)

{

  LL x=0;int f=1;char c=getchar();

  while((c<'0'||c>'9')&&c!='-')c=getchar();

  if(c=='-')f=-f,c=getchar();

  while(c>='0'&&c<='9')x=x*10+c-48,c=getchar();

  return f*x;

}

int main(void)

{

  int N,i,j,p;LL K;

  N=IN(),K=IN();

  for(i=0;i<N;i++)A[i]=IN(),town[i]=-1;

  for(i=0,j=0;;i=A[i]-1,j++)if(town[i]<0)town[i]=j;else break;

  for(p=0;K>0;p=A[p]-1,K--)if(i==p){K%=town[i]-j;if(!K)break;}

  return printf("%d\n",p+1),0;

}