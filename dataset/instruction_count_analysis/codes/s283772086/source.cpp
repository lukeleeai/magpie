#include<stdio.h>



int main()

{

    int n,i,digit=0,mod,num;



    scanf("%d",&n);



    for(i=1;i<=n;i++)

    {

        if(i<=9)

            digit++;



        else if(100<=i && i<=999)

            digit++;



        else if(10000<=i && i<=99999)///100000

            digit++;

    }



    printf("%d",digit);



    return 0;

}
