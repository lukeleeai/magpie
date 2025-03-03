#include<stdio.h>

typedef long long LL;

const int e[40]={0,1,1,2,2,2,3,3,3,3,4,4,4,4,4,5,5,5,5,5,

                 5,6,6,6,6,6,6,6,7,7,7,7,7,7,7,7,8,8,8,8};

LL IN(void)

{

  LL x=0;short f=0,c=getchar();

  while(c<48||c>57)f^=c==45,c=getchar();

  while(c>47&&c<58)x=x*10+c-48,c=getchar();

  return f?-x:x;

}

int main(void)

{

  int x=0;LL a=0,p=1,q=-1,N=IN();

  while(N%2==0){x++;N/=2;}a+=e[x],x=0;

  while(N%3==0){x++;N/=3;}a+=e[x];

  while(q*q<=N)

  {

    p+=6,q+=6;

    x=0;while(!(N%p)){x++;N/=p;}a+=e[x];

    x=0;while(!(N%q)){x++;N/=q;}a+=e[x];

  }

  if(N>1)a++;

  return printf("%lld\n",a),0;

}