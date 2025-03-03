#include<cstdio>

#include<cctype>

#include<cstring>

#include<ctime>

#include<cstdlib>

#include<algorithm>

#define max(a,b) (a>b?a:b)

#define min(a,b) (a<b?a:b)

#define reg register

typedef long long ll;

template<typename T>inline T read(){

    reg T x=0;reg short f=1;reg char c=getchar();

    for(;!isdigit(c);f=c=='-'?-1:1,c=getchar());

    for(;isdigit(c);x=x*10+(c^48),c=getchar());

    return x*f;

}

int n,a[200005]={-1};

int main(){

	n=read<int>();reg ll ans=0;

	for(reg int i=1;i<=n;i++)

		if((a[i]=read<int>())-a[i-1]>1)return 0*puts("-1");

	for(reg int i=2;i<=n;i++)

		if(a[i]>a[i-1])ans++;

		else ans+=a[i];

	printf("%lld\n",ans);

	return 0;

}