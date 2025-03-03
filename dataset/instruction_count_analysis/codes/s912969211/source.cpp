#include <stdio.h>

#include <string.h>

#define R register

#define MN 100005

int n,m,q,x,y,xx,yy,aa[MN],bb[MN];

char a[MN],b[MN];

inline int read(){

	R int x; R bool f; R char c;

	for (f=0; (c=getchar())<'0'||c>'9'; f=c=='-');

	for (x=c^'0'; (c=getchar())>='0'&&c<='9'; x=(x<<1)+(x<<3)+(c^'0'));

	return f?-x:x;

}

int main(){

	scanf("%s%s",a+1,b+1);

	n=strlen(a+1),m=strlen(b+1);

	for (R int i=1; i<=n; ++i)

		aa[i]=a[i]-'A'+aa[i-1]+1;

	for (R int i=1; i<=m; ++i)

		bb[i]=b[i]-'A'+bb[i-1]+1;

	q=read();while(q--){

		x=read(),y=read(),xx=read(),yy=read();

		(aa[y]-aa[x-1])%3==(bb[yy]-bb[xx-1])%3?

			puts("YES"):puts("NO");

	}return 0;

}