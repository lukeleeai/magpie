#include <cstdio>

#define rg register

using namespace std;

typedef long long ll;

template <typename Tp> inline int getmin(Tp &x,Tp y){return y<x?x=y,1:0;}

template <typename Tp> inline int getmax(Tp &x,Tp y){return y>x?x=y,1:0;}

template <typename Tp> inline void read(Tp &x)

{

	x=0;int f=0;char ch=getchar();

	while(ch!='-'&&(ch<'0'||ch>'9')) ch=getchar();

	if(ch=='-') f=1,ch=getchar();

	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();

	if(f) x=-x;

}

int x1,y1,x2,y2,a,b;

int main()

{

	read(x1);read(y1);read(x2);read(y2);

	a=x2-x1;b=y2-y1;

	printf("%d %d %d %d\n",x2-b,y2+a,x2-a-b,y2+a-b);

	return 0;

}