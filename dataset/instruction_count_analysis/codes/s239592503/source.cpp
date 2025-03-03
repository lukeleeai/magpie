#import<iostream>

main(){int n,c,i,a[1<<17]={};for(std::cin>>n;n--;){std::cin>>i;if(!a[i]++){++c;a[i]++;}}for(i=1<<17;i--;)n^=a[i]&1;std::cout<<(n&1?c:c-1);}