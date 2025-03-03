//Zory in 2018

//*******************头文件*******************

#include<cstdio>

#include<cstring>

#include<cmath>

#include<queue>

#include<vector>

#include<set>

#include<queue>

#include<algorithm>

typedef long long ll;

typedef unsigned long long ull;

ll mymax(ll x,ll y) {return x>y?x:y;}

int mymin(int x,int y) {return x<y?x:y;}

int myabs(int x) {return x>0?x:-x;}

//*******************全局常量*******************

const int MAXN=110000;

//*******************全局定义*******************

ll f[MAXN],g[MAXN];//顺时针，逆时针

ll x[MAXN],v[MAXN];

//*******************实现*******************



//*******************主函数*******************

int main()

{

	//freopen("tmp.in","r",stdin);

    int n;ll c;scanf("%d%lld",&n,&c);

    for(int i=1;i<=n;i++) scanf("%lld%lld",&x[i],&v[i]);



    ll ans=0,sum;

    sum=0;for(int i=1;i<=n;i++) sum+=v[i],f[i]=sum-x[i],ans=mymax(ans,f[i]);

    sum=0;for(int i=n;i>=1;i--) sum+=v[i],g[i]=sum-(c-x[i]),ans=mymax(ans,g[i]);



    ll mx;

    mx=0;for(int i=n-1;i>=1;i--) mx=mymax(mx,g[i+1]),ans=mymax(ans,f[i]+mx-x[i]);

    mx=0;for(int i=2;i<=n;i++) mx=mymax(mx,f[i-1]),ans=mymax(ans,g[i]+mx-(c-x[i]));



    printf("%lld",ans);

}
