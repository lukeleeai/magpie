#include<stdio.h>

#include<stdlib.h>



int main(){

    int a,b,c,sum;



    scanf("%d %d %d",&a,&b,&c);



    sum=a+b;



    if(sum>a+c)

        sum=a+c;

    if(sum>b+c)

        sum=b+c;



    printf("%d",sum);



    return 0;

}