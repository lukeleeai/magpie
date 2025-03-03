#include"stdc++.h"

#define ll long long

#define max(a,b) ((a)>(b)?(a):(b))

#define min(a,b) ((a)<(b)?(a):(b))

inline int read()

{

	int x=0,f=1;char ch=getchar();

	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}

	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}

	return x*f;

}

#define MN 100005

int v[MN],nm[2][MN],mx[2],ans=-10000000;

int main(){

	register int i,n;

	n=read();

	for(i=1;i<=n;i++) v[i]=read();

	for(i=1;i<=n;i++)

		nm[i&1][v[i]]++;

	for(i=1;i<MN;i++){

		if(!nm[0][v[i]]) nm[0][v[i]]=-100000000;

		if(!nm[1][v[i]]) nm[1][v[i]]=-100000000;	

	}

	mx[0]=mx[1]=-111111111;

	for(i=1;i<MN;i++){

		ans=max(ans,mx[0]+nm[1][i]);

		ans=max(ans,mx[1]+nm[0][i]);

		mx[0]=max(mx[0],nm[0][i]);

		mx[1]=max(mx[1],nm[1][i]);

	}

	printf("%d\n",n-ans);

	return 0;

}