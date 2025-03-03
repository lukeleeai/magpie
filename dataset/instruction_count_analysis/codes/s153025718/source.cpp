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

const int N=3010,mod=1e9+7;

char s[N];

int n,m,ans,c[N][N],l[N],r[N],lb[N],rb[N],f[N][N],a[N];

 

int main()

{

    n=get(),m=get();

    rep(i,0,n)

    {

        c[i][0]=1;

        rep(j,1,i)

            c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;

    }

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

        lb[i]=max(0,lb[i-1]+w-s),rb[i]=min(mx,rb[i-1]+w);

        rep(j,lb[i],rb[i])

            rep(k,max(j-w,lb[i-1]),min(s+j-w,rb[i-1]))

                f[i][j]=(f[i][j]+1ll*f[i-1][k]*c[s][k+w-j])%mod;

    }

    rep(i,lb[m],rb[m])

        ans=(ans+f[m][i])%mod;

    printf("%d",ans);

    return 0;

}