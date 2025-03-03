#include<cstdio>

#include<cstring>

#include<algorithm>

#define ll long long

#define MN 100005

using namespace std;

inline int in(){

    int x=0;bool f=0; char c;

    for (;(c=getchar())<'0'||c>'9';f=c=='-');

    for (x=c-'0';(c=getchar())>='0'&&c<='9';x=(x<<3)+(x<<1)+c-'0');

    return f?-x:x;

}

int st[MN],sum[MN],a[MN],b[MN],pos[MN],dif[MN];

int n,top,mx,cnt,cur;

ll res,ans[MN];

int main()

{

	n=in();top=0;st[top]=0;

	for (int i=1;i<=n;++i) a[i]=b[i]=in();b[n+1]=0x7fffffff;

	for (int i=1;i<=n;++i) if (!top||a[i]>a[st[top]]) st[++top]=i;

	sort(b+1,b+n+1);cnt=unique(b+1,b+n+1)-b-1;b[cnt+1]=0x7fffffff;

	for (int i=1;i<=n;++i) pos[i]=lower_bound(b+1,b+cnt+1,a[i])-b,++sum[pos[i]],mx=max(mx,pos[i]);

	for (int i=1;i<=cnt;++i) dif[i]=b[i]-b[i-1];

	for (int i=mx;i>=0;--i){

		sum[i]+=sum[i+1];res=1ll*dif[i]*sum[i];

		if (pos[st[top]]==i) cur=st[top],--top;ans[cur]+=res;

	}ans[1]+=ans[0]; 

	for (int i=1;i<=n;++i) printf("%lld\n",ans[i]);return 0;

}