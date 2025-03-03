#include"stdc++.h"

 using namespace std;

 int m=1000000007,n,x,y,z;

 unsigned long long f[41][131075],ne[131075][11],i,j,k;

 int main()

{

	scanf("%d%d%d%d",&n,&x,&y,&z);

	y+=x; z+=y;

	for(i=1;i<=1<<z;i++)

	 for(j=1;j<=10;j++)

	  {

		ne[i][j]=1;

		for(k=0;k+j<=z;k++)if(i&(1<<k))

		 if(!(k<x&&k+j>x)&&!(k<y&&k+j>y))ne[i][j]|=1<<(j+k);

		if((i==(1<<z))||ne[i][j]>=1<<z)ne[i][j]=1<<z;

	  }

	f[0][1]=1;

	for(i=1;i<=n;i++)

	 for(j=1;j<=1<<z;j++)

	  for(k=1;k<=10;k++)

	   f[i][ne[j][k]]=(f[i][ne[j][k]]+f[i-1][j])%m;

	cout<<f[n][1<<z];

	return 0;

}