#include<stdio.h>



int isPrime(int n)

{

    int i,count=0;



    if(n>1)



    {

        for(i=2; i<n; i++)

        {

            if(n % i == 0)

            {

                count++;

                break;

            }

        }

    }

    if(n==1)

        return 0;

    else

    {



        if(count==0)

        {

            return 1;

        }



        else

        {

            return 0;

        }

    }

}



int main()



{

    int number,ans;



    scanf("%d",&number);

    while(1)

    {

        ans = isPrime(number);

        if(ans == 1)

        {

            printf("%d",number );

            break ;

        }

        else

            number ++ ;







    }

    return 0;











}
