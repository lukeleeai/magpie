#include<cstdio>

long long p,ans=1,n;

int main()

{

    scanf("%lld%lld",&n,&p);

    if (n==1)

    {

        printf("%lld\n",p);

        return 0;

    }

    for (long long i=2;i*i<=p;i++)

    {

        long long cnt=0;

        while (p%i==0) ++cnt,p=p/i;

        for (long long j=1;j*n<=cnt;j++) ans=ans*i;

    }

    printf("%lld\n",ans);

}