#include<stdio.h>

#include<string.h>

#include<algorithm>

using namespace std;

long long a,b,c,d;

int main(){

   while(~scanf("%lld%lld%lld%lld",&a,&b,&c,&d)){

       long long s=0,t1,t2;

       t1=b/c-a/c;

       if(a%c==0)

        t1++;

        t2=b/d-a/d;

        if(a%d==0)

            t2++;

        s=t1+t2;

        long long p;

        p=__gcd(c,d);

        p=c*d/p;

        s-=b/p-a/p;

        if(a%p==0)

            s--;

            s=(b-a+1)-s;

        printf("%lld\n",s);

   }

}
