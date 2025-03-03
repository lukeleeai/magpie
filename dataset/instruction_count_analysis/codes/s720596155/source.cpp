#import<iostream>

int n,c,i,a[1<<17];

main(){for(std::cin>>n;std::cin>>i;)c+=!!a[i]++;std::cout<<n-c-c%2;}