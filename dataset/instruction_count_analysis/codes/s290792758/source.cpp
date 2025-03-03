#include<cstdio>

#include<cstring>

#include<algorithm>

#define ll long long

using namespace std;

inline ll in(){

    ll x=0;bool f=0; char c;

    for (;(c=getchar())<'0'||c>'9';f=c=='-');

    for (x=c-'0';(c=getchar())>='0'&&c<='9';x=(x<<3)+(x<<1)+c-'0');

    return f?-x:x;

}

ll n,a,b,c,d,mxp,mnp,mxn,mnn;

int main()

{

	n=in();a=in();b=in();c=in();d=in();

	for (int i=0;i<n;++i){

		mnp=c*i;mxp=d*i;

		mxn=-c*(n-1ll-i);mnn=-d*(n-1ll-i);

		if (mnp+mnn<=b-a&&mxp+mxn>=b-a) {printf("YES");return 0;}

	}printf("NO");return 0;

}