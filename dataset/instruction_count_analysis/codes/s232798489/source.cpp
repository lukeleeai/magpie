#include <stdio.h>

#define rep(i,n) for(i=0;i<n;++i)

int a[1<<18],v[1<<18][3],n,m,q,c,i,j;

main(){scanf("%d%d%d",&n,&m,&q);rep(i,n)rep(j,2)v[i][j]=(i+n+1-2*j)%n;rep(i,m){scanf("%d",a+i);rep(j,a[i])c=v[c][a[i]&1];v[c][2]=1;rep(j,2)v[v[c][j^1]][j]=v[c][j];c=v[c][0];}rep(i,q)scanf("%d",&c),printf("%d\n",1-v[c][2]);}