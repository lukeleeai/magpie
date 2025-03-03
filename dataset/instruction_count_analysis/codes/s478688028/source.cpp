#import<stdio.h>

int a[100010],b,i,s;main(){scanf("%d",&b);for(;i-b;++i)scanf("%d",a+i+1);for(i=1;i<=b;++i){i==a[a[i]]?++s:0;}printf("%d\n",s/2);}