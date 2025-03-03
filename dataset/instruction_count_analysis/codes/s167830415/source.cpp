#include "stdc++.h"

using namespace std;

const int N=11,M=1e3+5;

int b[N][M],c[N][M];

int n,m,k,x,ms,l,r,mid,ans;



inline bool jay(int p,int mid)

{

	memset(c,0,sizeof(c));

	int tot=1;

	for (register int j=1; j<=m; ++j) c[tot][j]=b[1][j]; 

	

	

	

	for (register int i=2; i<=n; ++i)

	{

		if (p&(1<<(i-1))) tot++;

		for (register int j=1; j<=m; ++j) c[tot][j]+=b[i][j];

	}

	

	int res=mid-tot+1;

	if (res<0) return false;

	

	int l=0;

	for (register int r=1; r<=m; ++r)

	for (register int i=1; i<=tot; ++i)

	{

		if (c[i][r]-c[i][r-1]>k) return false;

		if (c[i][r]-c[i][l]>k) res--,l=r-1;

		if (res<0) return false;

	}

	return true;

}



int main(){

	scanf("%d%d%d",&n,&m,&k);

	for (register int i=1; i<=n; ++i)

	for (register int j=1; j<=m; ++j) 

	{

		scanf("%1d",&x);

		b[i][j]=b[i][j-1]+x;

	}

	

	int ms=1<<n;

	l=0; r=n+m-2;

	while (l<=r)

	{

		bool f=false;

		mid=l+r>>1;

		for (register int p=0; p<ms; ++p) if (jay(p,mid)) {f=true; break;}

		if (f) ans=mid,r=mid-1; else l=mid+1;

	}

	printf("%d\n",ans);

return 0;	

}
