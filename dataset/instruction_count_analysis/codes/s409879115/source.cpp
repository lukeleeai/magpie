#include<cstdio>

#include<cstring>

#include<algorithm>

#define MN 20005

using namespace std;

inline int in(){

    int x=0;bool f=0; char c;

    for (;(c=getchar())<'0'||c>'9';f=c=='-');

    for (x=c-'0';(c=getchar())>='0'&&c<='9';x=(x<<3)+(x<<1)+c-'0');

    return f?-x:x;

}

int p[MN],rk[MN],a[MN],b[MN],n;

int main()

{

	n=in();

	for (int i=0;i<n;++i){

		a[i]=i*n;b[i]=(n-i)*n;p[i]=in();rk[p[i]-1]=i;

	}

	for (int i=0;i<n;++i) a[i]+=rk[i]; 

	for (int i=0;i<n;++i) printf("%d ",a[i]+1);puts("");

	for (int i=0;i<n;++i) printf("%d ",b[i]+1);return 0;

}