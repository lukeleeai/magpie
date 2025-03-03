#include <cctype>

#include <cstdio>

#include <cstring>

#include <algorithm>

#define rep(i,x,y) for (int i=x; i<=y; ++i)

#define repd(i,x,y) for (int i=x; i>=y; --i)

 

int get()

{

    char c;

    while (!isdigit(c=getchar()));

    int k=c-'0';

    for (; isdigit(c=getchar()); k=k*10+c-'0');

    return k;

}

 

using namespace std;

const int N=1e5+10,mod=1e9+7;

char s[N];

int n,m,ans,fac[N],ifac[N],l[N],r[N],f[2][N],a[N];



int inv(int x)

{

    return x>1? 1ll*(mod-mod/x)*inv(mod%x)%mod:1;

}



int c(int n,int m)

{

    return 1ll*fac[n]*ifac[m]%mod*ifac[n-m]%mod;

}

 

int main()

{

    n=get(),m=get();

    fac[0]=1;

    rep(i,1,n)

        fac[i]=1ll*fac[i-1]*i%mod;

    ifac[n]=inv(fac[n]);

    repd(i,n,1)

        ifac[i-1]=1ll*ifac[i]*i%mod;

    scanf("%s",s+1);

    rep(i,1,n)

        a[i]=a[i-1]+s[i]-48;

    int t=0;

    rep(i,1,m)

    {

        int x=get(),y=get();

        if (x==l[t])

            r[t]=max(r[t],y);

        else if (y>r[t])

            ++t,l[t]=x,r[t]=y;

    }

    m=t,l[m+1]=n+1,f[0][0]=1;

    rep(i,1,m)

    {

        int w=a[r[i]]-a[max(l[i]-1,r[i-1])];

        int s=min(r[i],l[i+1]-1)-l[i]+1;

        int mx=r[i]-l[i]+1-s;

        memset(f[i&1],0,sizeof(f[i&1]));

        rep(j,0,s)

            rep(k,max(0,w-j),mx)

                f[i&1][k]=(f[i&1][k]+1ll*f[(i&1)^1][j+k-w]*c(s,j))%mod;

    }

    rep(i,0,n)

        ans=(ans+f[m&1][i])%mod;

    printf("%d",ans);

    return 0;

}