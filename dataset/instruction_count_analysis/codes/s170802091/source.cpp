///e. next prime

#include <stdio.h>

#include <math.h>



int isPrime(int a)

{

    if(a==2) return 1;

    for(int i=2;i<=sqrt(a);i++){

        if(a%i==0) return 0;

    }

    return 1;

}

int main()

{

    int x;

    scanf("%d",&x);



    for(int i=x;;i++){

        if(isPrime(i)==1) {

            printf("%d",i);

            break;

        }

    }

}