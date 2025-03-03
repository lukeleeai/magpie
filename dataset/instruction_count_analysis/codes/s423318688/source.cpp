#include<stdio.h>

int main()

{

    int a,b,n,i,j,x,y,sum=0;

    scanf("%d",&n);

    int array[n];

    scanf("%d",&array[0]);

    a=array[0];

    for(i=1; i<n; i++)

        {

            scanf("%d",&array[i]);

            if(a<array[i])

                {

                    a=array[i];

                }





        }

    for(i=0; i<n; i++)

        {

            sum=sum+array[i];

        }

    sum=sum-a;

    if(a<sum)

        printf("Yes");

    else

        printf("No");



    return 0;







}
