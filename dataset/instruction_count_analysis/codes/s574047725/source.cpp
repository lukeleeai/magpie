#include<cstdio>

int R,C,s[10000][10],f[10],N,i,j,n,m;void rec(int k){if(k<R){f[k]=0;rec(k+1);f[k]=1;rec(k+1);}else for(n=i=0;i<C;i++,n+=m>R-m?m:R-m,N=N>n?N:n)for(m=j=0;j<R;j++)m+=s[i][j]^f[j];}main(){for(;scanf("%d%d",&R,&C),R;rec(0),printf("%d\n",N))for(j=R;j-->0;)for(i=C;i-->0;)scanf("%d",s[i]+j);}