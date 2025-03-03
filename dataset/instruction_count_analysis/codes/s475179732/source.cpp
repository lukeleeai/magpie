#include"stdc++.h"

using namespace std;

#define RI register int

int read() {

    int q=0;char ch=' ';

    while(ch<'0'||ch>'9') ch=getchar();

    while(ch>='0'&&ch<='9') q=q*10+ch-'0',ch=getchar();

    return q;

}

const int mod=1e9+7,N=100005;

int n,ans;

int a[N],du[N],kj[N],vis[N],hjw[N],sum[N],f[N];

int qm(int x) {return x>=mod?x-mod:x;}

void workkj(int x) {

    int now=0,fr=0,ed=0,hpp=0;

    while(kj[x]) {

        ++now,kj[x]=0;

        if(hjw[x]) {

            if(!fr) ed=fr=now,hpp=hjw[x];

            else {

                int kl=(hjw[x]<now-ed)+(hjw[x]<=now-ed);

                ans=1LL*ans*kl%mod,ed=now;

            }

        }

        x=a[x];

    }

    if(!fr) ++sum[now];

    else {

        int kl=(hpp<now-ed+fr)+(hpp<=now-ed+fr);

        ans=1LL*ans*kl%mod;

    }

}

void work() {

    for(RI i=1;i<=n;++i) {

        if(du[i]) continue;

        int x=i,len=0;while(!kj[x]) x=a[x],++len;

        hjw[x]=len;

    }

    ans=1;

    for(RI i=1;i<=n;++i) if(kj[i]) workkj(i);

    for(RI i=1;i<=n;++i) {

        if(!sum[i]) continue;

        f[0]=1;

        for(RI j=1;j<=sum[i];++j) {

            if(i>1&&(i&1)) f[j]=qm(f[j-1]+f[j-1]);

            else f[j]=f[j-1];

            if(j>1) f[j]=qm(f[j]+1LL*f[j-2]*(j-1)%mod*i%mod);

        }

        ans=1LL*ans*f[sum[i]]%mod;

    }

}

int main()

{

    n=read();

    for(RI i=1;i<=n;++i) a[i]=read(),++du[a[i]];

    for(RI i=1;i<=n;++i) {

        if(vis[i]) continue;

        int x=i;while(!vis[x]) vis[x]=i,x=a[x];

        if(vis[x]!=i) continue;

        while(!kj[x]) kj[x]=1,x=a[x];

    }

    for(RI i=1;i<=n;++i)

        if((kj[i]&&du[i]>2)||(!kj[i]&&du[i]>1)) {puts("0");

		return 0;

  }

    work();

    printf("%d\n",ans);

    return 0;

}