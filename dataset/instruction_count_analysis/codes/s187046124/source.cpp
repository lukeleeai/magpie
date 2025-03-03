#include<cstdio>

#define max(a,b) (a>b?a:b)

#define min(a,b) (a<b?a:b)

#define reg register

typedef long long ll;

inline int read(){

	reg int x=0,f=1;reg char ch=getchar();

	for(;ch>'9'||ch<'0';f=ch=='-'?-1:1,ch=getchar());

	for(;ch<='9'&&ch>='0';x=(x<<3)+(x<<1)+(ch^48),ch=getchar());

	return x*f;

}

int buf[15];

inline void write(int x){

	reg int cnt=0;

	if(!x){puts("0");return;}

	while(x)buf[++cnt]=x%10+48,x/=10;

	while(cnt)putchar(buf[cnt--]);

	puts("");

}

const int maxn=2e5+5;

int n,a[maxn],cnt[maxn],s[maxn];

int main(){

	n=read();reg int ans=0,m=read();

	for(reg int i=1;i<=n;i++)cnt[a[i]=read()]++;

	for(reg int i=1;i<=n;i++)

		if(cnt[i])s[max(i-cnt[i]+1,1)]++,s[min(i+1,n+1)]--;

	for(reg int i=1;i<=n;i++)ans+=!(s[i]+=s[i-1]);

	while(m--){

		reg int x=read(),y=read(),t=a[x];a[x]=y;

		if(t>=cnt[t]&&t<=cnt[t]+n-1)ans+=!(--s[t-cnt[t]+1]);

		cnt[t]--;cnt[y]++;

		if(y>=cnt[y]&&y<=cnt[y]+n-1)ans-=!(s[y-cnt[y]+1]++);

		write(ans);

	}

	return 0;

}