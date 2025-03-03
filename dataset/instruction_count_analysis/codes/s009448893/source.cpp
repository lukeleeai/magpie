#include <stdio.h>

 

int main(){

    long long int na;

    long long int hasil =0;

    scanf("%lld", &na);

    

    for (int i=1 ; i<=na ; i++){

        if (i%3 == 0 || i%5 == 0 ){

            continue;

        }

        else {

            hasil+=i;

        }

    }

    printf("%lld", hasil);



    return 0;

}