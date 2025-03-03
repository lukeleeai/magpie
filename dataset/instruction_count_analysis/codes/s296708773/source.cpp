#include<stdio.h>

int main() {

    long long int i,N,sum=0;

    scanf("%lld",&N);

    for(i=1;i<=N;i++){

        sum+=i;

    }

    printf("%lld",sum);

    return 0; 

    }