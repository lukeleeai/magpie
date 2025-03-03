#include<stdio.h>

int main(){

int a,b,c,d;scanf("%d%d%d%d",&a,&b,&c,&d);

int e=a*b,f=c*d;

printf("%d\n",e<f?f:e);

}