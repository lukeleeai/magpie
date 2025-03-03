#include<cstdio>

#include<cctype>

const int N=100007,P=1000000007;

int a[N],deg[N],vis[N],pre[N],cnt[N],f[N];

int read(){int x=0,c=getchar();while(isspace(c))c=getchar();while(isdigit(c))(x*=10)+=c&15,c=getchar();return x;}

int add(int a,int b){return a+=b-P,a+(a>>31&P);}

int mul(int a,int b){return 1ll*a*b%P;}

int main()

{

    int n=read(),ans=1;

    for(int i=1;i<=n;++i) ++deg[a[i]=read()];

    for(int i=1,p;(p=i)<=n;++i)

    {

	if(deg[i]>2) return puts("0"),0;

	if(deg[i]<2||vis[i]) continue;

	do

	{

	    if(vis[p]) return puts("0"),0;

	    vis[p]=1,pre[a[p]]=p,p=a[p];

	}while(p^i);

    }

    for(int i=1,p,l1,l2;i<=n;++i)

	if(!deg[i])

	{

	    for(p=i,l1=0,l2=0;!vis[p];p=a[p]) vis[p]=1,++l1;

	    do ++l2,p=pre[p]; while(deg[p]^2);

	    if(l1<l2) ans=add(ans,ans); else if(l1>l2) return puts("0"),0;

	}

    for(int i=1;i<=n;++i)

	if(!vis[i])

	{

	    int p=i,l=0;

	    do ++l,p=a[p],vis[p]=1; while(p^i);

	    ++cnt[l];

	}

    for(int i=1;i<=n;ans=mul(ans,f[cnt[i++]]))

    {

	f[0]=1,f[1]=1+(i^1&&i&1);

	for(int j=2;j<=cnt[i];++j) f[j]=add(mul(i,mul(j-1,f[j-2])),mul(f[1],f[j-1]));

    }

    printf("%d",ans);

}
