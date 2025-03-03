#include<stdio.h>

#define low 100010



int main()

{

    int type,amount,i,a[100],sum,left,min,total;



    scanf("%d %d",&type, &amount);



    for(i=0, sum=0, min=low; i<type ; i++)

    {

        scanf("%d",&a[i]);



        sum = sum + a[i];



        if(a[i]<min)

            min = a[i];

    }



    left = amount - sum;



    total = type + (left/min);



    printf("%d",total);



    return 0;

}
