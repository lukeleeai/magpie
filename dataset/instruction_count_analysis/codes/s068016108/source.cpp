#include<cstdio>

#include<algorithm>

using namespace std;

#define mod 1000000007

#define N 200005

typedef long long LL;

LL f1[N],s[N];

int n;

inline LL pow(LL a,int k)

{

    LL x=1;

    while(k)

	{

        if(k&1)

			x=x*a%mod;

        a=a*a%mod;

        k>>=1;

    }

    return x;

}

inline void prepare() 

{

    s[0]=1;

    for(int i=1;i<=n;i++)

        s[i]=s[i-1]*i%mod;

    f1[0]=1;

    f1[n]=pow(s[n],mod-2);

    for(int i=n-1;i>0;i--)

        f1[i]=f1[i+1]*(i+1)%mod;

}

inline LL C(int a,int b)

{

    if(a<0||b<0)

		return 1;

    return s[a]*f1[b]%mod*f1[a-b]%mod;

}

int main()

{

    int h,w,a,b;

    scanf("%d%d%d%d",&h,&w,&a,&b);

    n=h+w-2;

    prepare();

    LL ans=C(h+w-2,h-1);

    for(int i=1;i<=b;i++) 

	{

        ans-=C(h-a+i-2,h-a-1)*C(a-1+w-i,a-1)%mod;

        ans=(ans+mod)%mod;

    }

    printf("%lld\n",ans);

    return 0;

}
