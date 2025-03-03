#include<stdio.h>



long long n,t;



int main(void){

    scanf("%lld%lld",&n,&t);

    if(n-t<=0)

        return puts("0"),0;

    printf("%lld\n",n-t);

    return 0;

}