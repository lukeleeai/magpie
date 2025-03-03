#include<cstdio>

#define F(i,l,r) for(int i=l;i<=r;i++)

int m=1e9+7,n,k,d[2333][2333];main(){scanf("%d%d",&n,&k);d[1][1]=1;F(i,2,n)F(j,1,i)d[i][j]=(d[i][j-1]+d[i-1][j])%m;F(i,1,n-k-1)(d[n][k]*=2)%=m;printf("%d\n",d[n][k]);}