#include <stdio.h>



int isPrime(int x)

{

    int i;

    if(x==2)

        return 1;

    if(x%2==0)

        return 0;

    for(i=3; i<=x/2; i+=2)

    {

        if(x%i==0)

            return 0;

    }

    return 1;

}



int main()

{

    int n, i;

    scanf("%d", &n);



    for(i=n; i<=1000000; i++)

    {

        if(isPrime(i))

        {

            printf("%d\n", i);

            break;

        }

    }



    return 0;

}
