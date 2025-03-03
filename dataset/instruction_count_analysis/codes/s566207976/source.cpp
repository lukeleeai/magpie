#include <stdio.h>

#define N 100005

char s[N],t[N];

int a,b,c,d,x[N],y[N];

inline void solve() {

	scanf("%d%d%d%d",&a,&b,&c,&d);

	puts(((x[b]-x[a-1]-y[d]+y[c-1])%3+3)%3?"NO":"YES");

}

int main() {

	int Q;

	scanf("%s%s%d",s+1,t+1,&Q);

	x[0]=y[0]=0;

	for(int i=1;s[i];++i) x[i]=x[i-1]+s[i]-'A'+1;

	for(int i=1;t[i];++i) y[i]=y[i-1]+t[i]-'A'+1;

	while(Q--) solve();

	return 0;

}