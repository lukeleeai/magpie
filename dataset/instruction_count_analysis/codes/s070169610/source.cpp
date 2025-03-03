#include<cstdio>

inline int in();

inline void wr(int);

const int N=(int)1e5+5;

int a[N];

inline int mx(int,int);

inline int mn(int,int);

int main(int argc,char**argv){

#ifndef ONLINE_JUDGE

//	freopen("2386.in","r",stdin);

//	freopen("2386.ans","w",stdout);

#endif

	register int n=in();

	for(register int i=1;i<=n;++i)

		a[i]=in();

	register int x=0,y=n;

	for(register int i=1;i<=n;++i)

		x=mx(x,a[i]),y=mn(y,a[i]);

	if(x-y>1){puts("No");return 0;}

	if(!(x-y)){puts((x==n-1||(x<<1)<=n)?"Yes":"No");return 0;}

	register int m=0;

	for(register int i=1;i<=n;++i)

		m+=(a[i]==y);

	if(1+m<=x&&x<=m+((n-m)>>1))puts("Yes");

	else puts("No");

}

inline int mx(int x,int y){

	return x>y?x:y;

}

inline int mn(int x,int y){

	return x<y?x:y;

}

inline int in(){

	register char c=getchar();

	register int x=0,f=1;

	for(;c<'0'||c>'9';c=getchar())

		if(c=='-')f=-1;

	for(;c>='0'&&c<='9';c=getchar())

		x=(x<<1)+(x<<3)+(c&15);

	return x*f;

}

inline void wr(int x){

	if(x<0)putchar('-'),x=-x;

	if(x/10)wr(x/10);

	putchar(x%10+'0');

}
