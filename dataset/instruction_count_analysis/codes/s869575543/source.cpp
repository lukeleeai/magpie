#include<cstdio>

#define ll long long

int main() {

    ll s;

    int n,x,a,b;

    scanf("%d%d",&n,&x);

    s=a=0;

    while(n--) {

        scanf("%d",&b);

        a=a+b>x?a+b-x:0;

        s+=a;

        a=b-a;

    }

    printf("%lld\n",s);

    return 0;

}
