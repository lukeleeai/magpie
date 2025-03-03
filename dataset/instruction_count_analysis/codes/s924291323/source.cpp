#include<stdio.h>

#define rep(i,N) for(int i=0;i<(int)N;i++)

int main(void)

{

  int N,total=0,ope=0;char stones[200001]={0};if(!scanf("%d %s",&N,stones))return-1;

  rep(i,N){if(stones[i]=='R')total++;} 

  ope=total;rep(i,total){if(stones[i]=='R')ope--;}

  return printf("%d\n",ope),0;

}