#include<cstdio>

#include<cmath>

#include<cstring>

using namespace std;



long long gcd(long long a,long long b)

{

    return !b?a:gcd(b,a%b);

}



long long lms(long long  a,long long  b)

{

    return (a*b)/gcd(a,b);

}



int main()

{

    long long a,b,c,d,nc=0;

    //long long i,j;

    while(~scanf("%lld%lld%lld%lld",&a,&b,&c,&d)){

    nc=0;

    long long Lms=lms(c,d);

    if(a%c==0) nc++;

    //if(b%c==0) nc++;

    if(a%d==0) nc++;

    //if(b%d==0) nc++;

    nc+=(b/c-a/c);

    nc+=(b/d-a/d);

    if(a%Lms==0) nc--;

    //if(b%Lms==0) nc--;

    nc-=(b/Lms-a/Lms);

    printf("%lld",b-a+1-nc);}

}
