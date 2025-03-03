#include<stdio.h>

#include<algorithm>

int*t,n,m,d,i,s[99999];main(){for(;scanf("%d%d%d",&d,&n,&m),s[i=n]=d;printf("%d\n",i)){for(;--i;)scanf("%d",s+i);for(std::sort(s,s+n);m--;i+=std::min(d-*--t,*t-d))scanf("%d",&d),t=std::upper_bound(s,s+n,d);}}