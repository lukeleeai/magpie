#include<stdio.h>

int main() {

 long long int h,n;

 long long int i,sum=0;

 scanf("%lld %lld",&h,&n);

 for(i=0;i<n;i++) 

 { 

   long long int m;

   scanf("%lld",&m);

   sum = sum + m;     

 }

    if(sum>=h)

   { printf("Yes\n"); }  

    else {printf("No\n"); } 

        

  

    

    

    return 0;

}