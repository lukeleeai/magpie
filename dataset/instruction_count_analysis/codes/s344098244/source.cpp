#include <stdio.h>

#include <math.h>

#include <string.h>



int gcd(int a,int b){

    if(a<b){

        int now=a;

        a=b;

        b=a;

    }



    int r=a%b;

    while(r!=0){

        a=b;

        b=r;

        r=a%b;

    }



    return b;

}









int main(void){

    int n;

    scanf("%d",&n);

    int goal=0;

    int start=10000;







    int i;

    for(i=0;i<n;i++){

        int now;

        scanf("%d",&now);



        if(now<start){

            start=now;

        }

        if(goal<now){

            goal=now;

        }

    }



    printf("%d\n",goal-start);



    return 0;

}