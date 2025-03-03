#include<cstdio>

#include<cstring>

#include<algorithm>

#define ll long long

#define MN 200005

using namespace std;

inline int in(){

    int x=0;bool f=0;char c;

    for (;(c=getchar())<'0'||c>'9';f=c=='-');

    for (x=c-'0';(c=getchar())>='0'&&c<='9';x=(x<<3)+(x<<1)+c-'0');

    return f?-x:x;

}

int a[MN],n,x;

ll res;

int main()

{

	n=in();

	for (int i=1;i<=n;++i) a[i]=in()-i;

	sort(a+1,a+n+1);x=a[(n+1)>>1];

	for (int i=1;i<=n;++i) res+=1ll*abs(a[i]-x);

	printf("%lld",res);return 0;

}