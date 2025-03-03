#include<stdio.h>

int main()

{

 long long int n;

 scanf("%lld",&n);

 int i,count1=0;

 for(i=1;i<=n;i++)   

 {

     int temp;

     temp=i; 

     int count2=0;

     while(temp!=0)  

    {

      count2++;

      temp = temp/10;

    } 

    if(count2%2==1) 

       {

        count1++;

       }

 }

    

   printf("%d",count1); 

    return 0;

}