#include<cstdio>

long long a,b,x;

int main(){

    scanf("%lld%lld%lld",&a,&b,&x);

    printf("%lld",b/x-(a%x==0?a/x:a/x+1)+1);

    return 0;

}