#include<cstdio>

#include<algorithm>

#define ll long long

#define For(i,x,y)  for(ll i=x;i<=y;++i)

#define FOr(i,x,y)  for(ll i=x;i>=y;--i)

#define lf else if

using namespace std;

inline ll read(){   ll x=0,f=1;char ch=getchar();   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}  while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}  return x*f; } 

inline void write(ll x){    if (x<0) putchar('-'),x=-x; if (x>=10) write(x/10);   putchar(x%10+'0');  } 

inline void writeln(ll x){ write(x);   puts("");   }

const ll N=100100;

ll f[N],a[N],b[N],c[N],n,ans;

int main(){

	n=read();

	For(i,1,n)	a[i]=read();

	For(i,1,n)	b[i]=read();

	For(i,1,n)	c[i]=read();

	sort(a+1,a+n+1);

	sort(b+1,b+n+1);

	sort(c+1,c+n+1);

	ll p=1;

	For(i,1,n){

		while(c[p]<=b[i]&&p<=n)	++p;

		f[i]=max(n-p+1,0ll);

	}

	FOr(i,n,1)	f[i]+=f[i+1];

	p=1;

	For(i,1,n){

		while(b[p]<=a[i]&&p<=n)	++p;

		ans+=f[p];

	}

	writeln(ans);

}