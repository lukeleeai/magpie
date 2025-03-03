#include<cstdio>

int n,a,b,h[100000],i,l,m,r;

long long x;

main(){

  for(scanf("%d%d%d",&n,&a,&b),a-=b;i<n;l=1,r=1e9)scanf("%d",h+i++);

  while(l<r){

    m=(l+r)/2;

    for(x=i=0;i<n;++i)h[i]>(long long)m*b?x+=(h[i]-m*b+a-1)/a:0;

    x<=m?r=m:l=m+1;

  }

  printf("%d\n",l);

}