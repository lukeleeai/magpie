#include<stdio.h>

#include<iostream>

#include<algorithm>

#include<math.h>

#include<stdlib.h>

#include<string.h>

#include<string>

#include<set>

#include<vector>

#include<bitset>

#include<map>

#define N 200005

#define ll long long

#define oo 100000000

#define For(i,x,y) for(int i=x;i<=y;i++)

#define Rep(i,x,y) for(int i=x;i>=y;i--)

#define Forn(i,x,y) for(int i=x;i<y;i++)

using namespace std;

inline int read(){int x=0,f=0;char ch=getchar();for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') f=1;for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+ch-48;return f?-x:x;}

inline void write(ll x){if(x<10) putchar(x+48);else write(x/10),putchar(x%10+48);}

inline void writeln(ll x){if(x<0) putchar('-'),x=-x;write(x);putchar('\n');}

int n,m,st[N],ed[N];

int main(){

	n=read();m=read();

	For(i,1,m){

		int x=read(),y=read();

		if(x>y) swap(x,y);

		if(x==1) st[y]=1;

		if(y==n) ed[x]=1;

	}

	For(i,1,n) if(st[i]&&ed[i]){puts("POSSIBLE");return 0;}

	puts("IMPOSSIBLE");

	return 0;

}