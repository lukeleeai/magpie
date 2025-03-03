#include <algorithm>

#include <cstdio>



using namespace std;



int n,k,a,ak,h,i;



int max(int a,int b)

{return(a>b?a:b);}



int main()

{

    scanf("%d %d %d",&n,&k,&a);

    h=a;

    for(i=2;i<=n;++i)

    {

        scanf("%d",&ak);

        a=__gcd(a,ak);

        h=max(ak,h);

    }

    if(k%a==0&&k<=h)printf("POSSIBLE\n");

    else printf("IMPOSSIBLE\n");

    return 0;

}