#include<stdio.h>

#include<string.h>

#include<algorithm>

using namespace std;

#define N 300010

#define Mod 998244353

#define LL long long

LL s1[N],s2[N];

LL find(LL x,LL y)

{

    LL ans=1;

    x=x%Mod;

    while(y)

    {

        if(y%2)

            ans=ans*x%Mod;

        x=x*x%Mod;

        y=y/2;

    }

    return ans;

}

int main()

{

    LL n,m,x,y;

    LL i,j,k;

    LL ans;

    scanf("%lld%lld%lld%lld",&n,&x,&y,&m);

    s1[0]=1;

    for(i=1;i<=n;i++)

        s1[i]=s1[i-1]*i%Mod;

    s2[n]=find(s1[n],Mod-2);

    for(i=n;i>=1;i--)

        s2[i-1]=s2[i]*i%Mod;

    ans=0;

    for(i=0;i<=n;i++)

    {

        if((m-i*x)%y!=0||(m-i*x<0)||(m-i*x)/y>n)

            continue;

        ans=(ans+s1[n]*s2[i]%Mod*s2[n-i]%Mod*s1[n]%Mod*s2[(m-i*x)/y]%Mod*s2[n-(m-i*x)/y]%Mod)%Mod;

    }

    printf("%lld\n",ans);

    return 0;

}