#include <stdio.h>

#define R register

#define ll long long

inline int read(){

	R int x; R bool f; R char c;

	for (f=0; (c=getchar())<'0'||c>'9'; f=c=='-');

	for (x=c^'0'; (c=getchar())>='0'&&c<='9'; x=(x<<3)+(x<<1)+(c^'0'));

	return f?-x:x;

}

#define MN 100005

int n,m,cnt[MN];

int main(){

	n=read(),m=read();

	while(m--) ++cnt[read()],++cnt[read()];

	for (R int i=1; i<=n; ++i) if (cnt[i]&1) return 0*puts("NO");

	puts("YES");return 0;

}