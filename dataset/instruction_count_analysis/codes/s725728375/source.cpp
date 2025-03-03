#include<cstdio>

#include<cctype>

#define RI register int

#define g (p1==p2&&(p2=(p1=buf)+fread(buf,1,size,stdin),p1==p2)?EOF:*p1++)

using namespace std;

typedef long long ll;

const int mod=1e9+7,N=1e5+10,size=N<<2;

char buf[size],*p1=buf,*p2=buf;

void qr(int &x) {

	char c=g;x=0;

	while(!isdigit(c))c=g;

	while(isdigit(c))x=x*10+c-'0',c=g;

}

int n; ll ans;

int a[N],deg[N],vis[N],footL[N],sum[N],f[N];

bool cir[N];

inline int qm(int x) {return x>=mod?x-mod:x;}

void workcir(int x) {

	int now=0,fr=0,frL=0,ed=0;

	//now是当前环的长度，fr是第一个有脚点的位置,frL是位置对应的脚长,ed为上一个有脚点的位置。 

	while(cir[x]) {

		++now; cir[x]=0;

		if(footL[x]) {

			if(!fr) ed=fr=now,frL=footL[x];

			else {

				ans=ans*((footL[x]<now-ed)+(footL[x]<=now-ed))%mod;//脚的放法 

				ed=now;

			}

		}

		x=a[x];

	}

	if(!ed) ++sum[now];

	else ans=ans*((frL<now-ed+fr)+(frL<=now-ed+fr))%mod;

}

void work() {

	for(RI i=1;i<=n;i++) {//脚对环上交接点贡献 

		if(deg[i]) continue;

		int x=i,len=0; while(!cir[x])x=a[x],++len;

		footL[x]=len;//脚长 

	}

	ans=f[0]=1;

	for(RI i=1;i<=n;i++) if(cir[i]) workcir(i);//以环为基准计算基环内向树的情况 

	for(RI i=1;i<=n&&ans;i++) {//计算简单环 

		for(RI j=1;j<=sum[i];j++) {

			if(i>1&&(i&1)) f[j]=qm(f[j-1]<<1);

			else f[j]=f[j-1];

			if(j>1) f[j]=qm(f[j]+(ll)f[j-2]*(j-1)%mod*i%mod);

		}

		ans=ans*f[sum[i]]%mod;

	}

}

int main() {

	qr(n);

	for(RI i=1;i<=n;i++) qr(a[i]),++deg[a[i]];

	for(RI i=1;i<=n;i++) if(!vis[i]) {

		int x=i;while(!vis[x]) vis[x]=i,x=a[x];

		if(vis[x]!=i) continue;//脚 

		while(!cir[x]) cir[x]=1,x=a[x];//标记环上点 

	}

	for(RI i=1;i<=n;i++)

		if((cir[i]&&deg[i]>2)||(!cir[i]&&deg[i]>1)) return puts("0"),0;//开叉就不行 

	work(); printf("%lld\n",ans); return 0;

}