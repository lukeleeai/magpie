#include<stdio.h>

int main(){

    int N, i;

    double b, a=0;

    scanf("%d",&N);

    for(i=1; i<=N; i++){

        if(i%2 != 0){

            a++;

        }

    }

    b = a/N;

    printf("%.10lf\n",b);

    return 0;

}
