#include<iostream>

#include<cstdio>

using namespace std;

int k,n,now;

const int N=505;

int A[N][N];

int main()

{

	cin>>k;

	if(k<=500)

	{

		cout<<k<<endl;

		for(int i=1;i<=k;++i,puts(""))

			for(int j=1;j<=k;++j)printf("%d ",i);

	}

	else

	{

		n=500;cout<<500<<endl;k-=n;

		for(int i=1,a,b,x,y;i<=n;++i)

		{

			a=++now;b=k?++now:now;k-=b-a;

			x=1;y=i;

			for(;x<=n;++x,y=(y==n?1:y+1))A[x][y]=x&1?a:b;

		}

		for(int i=1;i<=n;++i,puts(""))

			for(int j=1;j<=n;++j)printf("%d ",A[i][j]);

	}

	return 0;

}