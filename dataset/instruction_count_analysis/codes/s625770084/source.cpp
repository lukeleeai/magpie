#include<stdio.h>



int main() {

    long long a[5];

    int temp;

    for(int i=0; i<3; i++){

        scanf("%lld",&a[i]);

    }

    for(int i=0; i<2; i++){

        for(int j=0; j<2-i; j++){

            if(a[j] > a[j+1]){

                temp = a[j];

                a[j] = a[j+1];

                a[j+1] = temp;

            }

        }

    }

    printf("%lld\n",a[0]+a[1]);

    return 0;

}
