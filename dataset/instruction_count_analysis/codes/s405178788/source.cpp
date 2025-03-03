#include<stdio.h>

#include<math.h>

int main()

{

    long long int X,i,j,d,prym,num;

    scanf("%lld",&X);

    if(X==1||X==2)

    {

        printf("2");

    }

    else if(X==3)

    {

        printf("3");

    }

    else

    {

        for(i=X; 1; i++)

        {

            for(j=2; j<=sqrt(i); j++)

            {

                if(i%j==0)

                {

                    num=0;

                    break;

                }

                else num=1;

            }

            if(num==1)

            {

                printf("%lld",i);

                break;

            }

        }

    }



    return 0;

}
