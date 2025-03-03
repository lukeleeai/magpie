#include<cstdio>

int n,k,i,j,l,a[1<<20];int main(){scanf("%d%d",&k,&n);if(k&1){while(j<n)a[j++]=k+1>>1;for(j=n;i<n-1;i+=2)if(--a[--j])while(++j<n)a[j]=k;while(l<j)printf("%d ",a[l++]);}else{for(;i<n;i++)printf("%d ",k/(1+!i));}}