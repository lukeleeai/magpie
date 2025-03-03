#include<stdio.h>

int main(){

    int N,A,YEN500;

    scanf("%d%d",&N,&A);

    YEN500=N%500;

    if(YEN500<=A)

    printf("Yes");

    else

    printf("No");

    return 0;

}