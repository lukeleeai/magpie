#include <cstdio>

int main(){int N,M,i;scanf("%d%d",&N,&M);for (i=M/N;i>=1;i--){if((M-i*N)%i==0){printf("%d\n",i);break;}}}