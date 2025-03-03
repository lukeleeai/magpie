#include<iostream>

#include<cstdio>

#include<cmath>

#include<cstring>

#include<algorithm>

#define fo(i,a,b) for(int i=a;i<=b;i++)

#define fod(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

typedef long long ll;

const int N=1e5+10,inf=(1<<30);

ll f[N],p[N];int n,e,t;

int main()

{

	scanf("%d%d%d",&n,&e,&t);

	fo(i,1,n) scanf("%lld",&p[i]);

	memset(f,63,sizeof(f));f[0]=0;

	ll mn=inf;

	for(int i=1,j=0;i<=n;i++) {

		for(;t<=(p[i]-p[j+1])<<1;j++)

			mn=min(mn,f[j]-2*p[j+1]);

			if(j<i) f[i]=min(f[i],f[j]+t);

			f[i]=min(f[i],mn+2*p[i]);

	}

	printf("%lld\n",f[n]+e);

	return 0;

}