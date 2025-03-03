#include<iostream>

#include<cstdio>

#include<cstring>

#include<algorithm>

#include<cmath>

using namespace std;

const int N=510;

struct dat{

    int x,y,id;

    dat(){}

    dat(int x,int y,int id):

        x(x),y(y),id(id){}

}a[N];

int n,mod,cnt=0;

long long ans=0ll;

long long f[N][N];

inline bool cmp(dat x,dat y)

{

    if(x.x^y.x) return x.x<y.x;

    else return x.y<y.y;

}

inline long long add(long long x,long long y)

{

    return x+y>=mod?x+y-mod:x+y;

}

inline long long sub(long long x,long long y)

{

    return x-y<0?x-y+mod:x-y;

}

int main()

{

//    freopen("1.in","r",stdin);

    scanf("%d%d",&n,&mod);

    for(int k=0;k<2*n;k++)

    {

        int l=max(0,(int)ceil(sqrt(n*n-k*k))),r=min(2*n-1,(int)sqrt(n*n*4-k*k));

        if(k<n) a[++cnt]=dat(l-1,r,k);

        else a[++cnt]=dat(r,0,k);

    }

    sort(a+1,a+1+cnt,cmp);

    for(int k=0;k<=n;k++)

    {

        memset(f,0,sizeof f);

        f[0][0]=1ll;

        int x=0;

        for(int i=1;i<=cnt;i++)

        {

            for(int j=0;j<=k;j++)

            {

                if(a[i].id<n)

                {

                    if(a[i].x+1-x-(j-1)>0&&j)

                        f[i][j]=add(f[i][j],f[i-1][j-1]*(a[i].x+1-x-(j-1))%mod);

                    if(a[i].y+1-k-n-(i-1-x-j)>0)

                        f[i][j]=add(f[i][j],f[i-1][j]*(a[i].y+1-k-n-(i-1-x-j))%mod);

                }

                else

                {

                    if(a[i].x+1-x-j>0)

                        f[i][j]=f[i-1][j]*(a[i].x+1-x-j)%mod;

                }

            }

            if(a[i].id>=n) x++;

        }

        if(k&1) ans=sub(ans,f[cnt][k]);

        else ans=add(ans,f[cnt][k]);

    }

    printf("%lld\n",ans);

    return 0;

}
