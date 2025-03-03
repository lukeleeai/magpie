 #include<cstring>

#include<cstdio>

#include<cmath>

#include<memory.h>

#include<algorithm>

#include<map>

#define ll long long

#define ld long double

#define maxn 310

#define For(i,j,k)  for(ll i=j;i<=k;++i)

#define FOr(i,j,k)  for(ll i=j;i>=k;--i)

const ll inf=1e9;

const ld eps=1e-7;

using namespace std;

inline ll read(){   ll x=0,f=1;char ch=getchar();   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}  while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}  return x*f; }

inline void wrote(ll x){    if (x<0) putchar('-'),x=-x; if (x>=10) wrote(x/10);   putchar(x%10+'0');  }

void writeln(ll x){ wrote(x);   puts("");   }

const ll N=100010;

ll a[N],n;

ll dis(ll a,ll b){	return abs(a-b);	}

ll work(){

	ll sum=0,ans=0;

	For(i,1,n){

		sum+=a[i];

		if (i&1){

			if (sum<=0)	ans+=dis(1,sum),sum=1;

		}else{

			if (sum>=0)	ans+=dis(-1,sum),sum=-1;

		}

	}return ans;

}

int main(){

	n=read();

	For(i,1,n)	a[i]=read();

	ll ans1=work();

	For(i,1,n)	a[i]=-a[i];

	ll ans2=work();

	writeln(min(ans1,ans2));

}