#include<stdio.h>



int a,b;



int main(void){

    scanf("%*d%d%d",&a,&b);

    if((b-a-1)&1)

        puts("Alice");

    else

        puts("Borys");

    return 0;

}