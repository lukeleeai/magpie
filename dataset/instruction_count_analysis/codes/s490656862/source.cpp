#include<stdio.h>

#pragma GCC optimize("O3")

#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define rep(i,N) for(int i=0;i<(int)N;i++)

static inline int IN(void)

{

  int x=0,f=0,c=getchar();while(c<48||c>57){f^=c==45,c=getchar();}

  while(c>47&&c<58){x=x*10+c-48,c=getchar();}return f?-x:x;

}

int main(void)

{

  int N=IN(),total=0,ope=0;char stones[N+1];if(!scanf("%s",stones))return-1;

  rep(i,N){if(stones[i]=='R')total++;} 

  ope=total;rep(i,total){if(stones[i]=='R')ope--;}

  return printf("%d\n",ope),0;

}