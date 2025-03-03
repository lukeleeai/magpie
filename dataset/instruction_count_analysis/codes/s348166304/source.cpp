#include<cstdio>

#include<cstring>

#include<algorithm>

#define MN 300005

using namespace std;

inline int in(){

    int x=0;bool f=0;char c;

    for (;(c=getchar())<'0'||c>'9';f=c=='-');

    for (x=c-'0';(c=getchar())>='0'&&c<='9';x=(x<<3)+(x<<1)+c-'0');

    return f?-x:x;

}

int a[MN],q[MN],tp,hd,tl,n;

int main()

{

	n=in();hd=tp=1;

	for (int i=1;i<=n;++i) a[i]=in();

	for (int i=1;i<=n;++i){

		tp=min(tp,i); 

		if((a[i]-tp)&1){if(a[i]!=i){printf("No");return 0;}}

		else if (hd>tl||q[tl]<a[i]) q[++tl]=a[i];

		else if (a[i]==tp) tp+=2;

		else {printf("No");return 0;}

		while (hd<=tl&&q[hd]==tp) tp+=2,++hd;

	}printf("Yes");return 0;

}