#include<stdio.h>

int main(){

    int N,A,B, i, temp, t, remainder, sum, total = 0;

    scanf("%d %d %d", &N,&A,&B);



    for(i = 1; i <= N; i++){

        t = i;

        sum  = 0;

        while (t != 0){

              remainder = t % 10;

              sum += remainder;

              t /= 10;

           }



           if(sum >= A && sum <= B){

               total += i;

        }

    }



    printf("%d", total);



}