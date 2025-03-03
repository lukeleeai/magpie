#include<stdio.h>

int main()

{

    int a_coin,total;

    scanf("%d\n%d",&total,&a_coin);

    int x=total/500;

    int b=x*500;

    if(b==total){

        printf("Yes\n");

    }

    else{

       int c=total-b;

        if(a_coin>=c){

            printf("Yes\n");

        }

        else{

            printf("No\n");

        }

        return 0;

    }

}
