#include<cstdio>

#include<cstring>

#include<algorithm>

#define LL long long

using namespace std;

const int M=1e5+7;

int read(){

	int ans=0,f=1,c=getchar();

	while(c<'0'||c>'9'){if(c=='-') f=-1; c=getchar();}

	while(c>='0'&&c<='9'){ans=ans*10+(c-'0'); c=getchar();}

	return ans*f;

}

int ans[M],T[M];

struct pos{int T,s;}e[M];

int x,k=1,n,m,sgn=-1;

void calc(LL &k){if(k<0) k=0; if(k>x) k=x;}

int main(){

	x=read();

	n=read(); for(int i=1;i<=n;i++) T[i]=read();

	m=read(); for(int i=1;i<=m;i++) e[i].T=read(),e[i].s=read();

	LL h=0,mx=x,mn=0;

	for(int i=1;i<=m;i++){

		while(k<=n&&T[k]<=e[i].T){

			LL v=(T[k]-T[k-1])*sgn;

			mx+=v; mn+=v; h+=v;

			calc(mx); calc(mn);

			k++;sgn*=-1; 

		}//printf("[%lld %lld %lld]\n",mx,mn,h);

		LL now=e[i].s+h,nowh=(e[i].T-T[k-1])*sgn; //printf("[%lld %lld]\n",now,nowh);

		if(now<mn) now=mn;

		if(now>mx) now=mx;

		now+=nowh; calc(now);

		printf("%lld\n",now);

	}

	return 0;

}