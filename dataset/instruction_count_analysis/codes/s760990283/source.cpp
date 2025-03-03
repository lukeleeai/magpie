#include<cstdio>

#include<cstring>

int main()

{

    long long a,b,x;

    scanf("%lld%lld%lld",&a,&b,&x);

    long long num=b/x-a/x;

    if(a%x==0)

        num++;

    printf("%lld\n",num);

    return 0;

}
