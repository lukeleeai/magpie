#include<cstdio>

#include<cstring>

#include<algorithm>

#define inf 0x3f3f3f3f

#define MN 100005

using namespace std;

inline int in(){

    int x=0;bool f=0;char c;

    for (;(c=getchar())<'0'||c>'9';f=c=='-');

    for (x=c-'0';(c=getchar())>='0'&&c<='9';x=(x<<3)+(x<<1)+c-'0');

    return f?-x:x;

}

int a[MN],n,k,pos,res;

int main()

{

	n=in();k=in();res=inf;

	for (int i=1;i<=n;++i) a[i]=in();a[n+1]=inf;

	pos=lower_bound(a+1,a+n+1,0)-a;

	if (pos+k-1<=n) res=min(res,a[pos+k-1]);

	if (a[pos]){

		if (pos-k>0) res=min(res,-a[pos-k]);

	}else{

		if (pos-k+1>0) res=min(res,-a[pos-k+1]);

	}

	for (int i=max(0,((a[pos])?pos-k:pos-k+1))+1;i<pos&&i+k-1<=n;++i)

	res=min(res,2*(a[i+k-1]-a[i])-max(a[i+k-1],-a[i]));

	printf("%d",res);return 0;

}