#include<cstdio>

int n,i,e,w,s=1e9,a[1<<19];char c[1<<19];main(){for(scanf("%d\n",&n);i<n;scanf("%c",c+i),a[i]=w,w+=c[i++]==87);for(;i>0;s=s<a[--i]+e?s:a[i]+e,e+=c[i]==69);printf("%d",s);}