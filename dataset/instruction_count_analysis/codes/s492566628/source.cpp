#include<stdio.h>

void ckmin(int&x,const int&y)

{

	x=x<y?x:y;

}

int n,m,a[100005],f[1<<15],ans;

int main()

{

	scanf("%d",&n);

	for(int i=1,x,y,z;i<n;i++)

	{

		scanf("%d%d%d",&x,&y,&z);

		a[x]^=z;a[y]^=z;

	}

	for(int i=0;i<n;i++)

		if(a[i]--)

			ans+=m>>a[i]&1,m^=1<<a[i];

	for(int s=1;s<=m;++s)

	{

		int x=0;

		for(int j=0;j<16;++j)if(s>>j&1)x^=j+1;

		if(x)f[s]=1e9;

		else{

			f[s]=__builtin_popcount(s)-1;

			for(int t=(s-1)&s;t;t=(t-1)&s)ckmin(f[s],f[t]+f[s^t]);

		}

	}

	printf("%d",ans+f[m]);

	return 0;

}
