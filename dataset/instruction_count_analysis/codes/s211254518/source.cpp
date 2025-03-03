#include<cstdio>

#include<algorithm>

using namespace std;

#define ll long long

int main()

{

    int N;

    scanf("%d",&N);

    ll t,a;

    ll anst,ansa;

    anst=ansa=1;

    ll m,n;

    while(N--)

    {

        scanf("%lld%lld",&t,&a);

        m=anst/t;

        n=ansa/a;

        if(m*t!=anst)

            m++;

        if(n*a!=ansa)

            n++;

        n=max(n,m);

        anst=t*n;

        ansa=a*n;

    }

    printf("%lld\n",anst+ansa);

    return 0;

}
