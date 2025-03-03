#include<stdio.h>



int main(){

    int a,x=0, max=0;

    scanf("%d", &a);

    char b[101];

    scanf("%s", b);

    for(int i=0 ; i<=a ; i++){

        if(b[i]=='I')

        x++;

        else

        x--;

        if (max<x){

            max=x;

        }

    }

    printf("%d\n", max);

    return 0;

}