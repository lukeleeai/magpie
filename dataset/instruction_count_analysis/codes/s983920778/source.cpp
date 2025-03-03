#include<cstdio>

int n,a[200010];

inline int read(){

	int ret=0;char c=getchar();

	while(c<'0'||c>'9')c=getchar();

	while(c>='0'&&c<='9')ret=(ret<<1)+(ret<<3)+(c^48),c=getchar();

	return ret;

}

int main()

{

	n=read();

	for(register int i=1;i<=n;++i)a[i]=read();

	for(register int i=n;i>0;i-=2)printf("%d ",a[i]);

	for(register int i=(n&1)+1;i<=n;i+=2)printf("%d ",a[i]);

	return 0;

}