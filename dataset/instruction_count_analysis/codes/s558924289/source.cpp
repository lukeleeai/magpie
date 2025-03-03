#include<cstdio>



const int N=500;

int m,n;

int a[N+5][N+5],f[N+5][N+5],Ans,ans[N*N+5][5];



int main()

{

	scanf("%d %d",&m,&n);

	for(int i=1;i<=m;i++)

		for(int j=1;j<=n;j++)

		{

			scanf("%d",&a[i][j]);

			if( ( f[i][j] ^= (a[i][j] & 1) )&& j != n)

			{

				f[i][j]=0;

				f[i][j+1]=1;

				ans[++Ans][1]=i,ans[Ans][2]=j,ans[Ans][3]=i,ans[Ans][4]=j+1;

			}

		}

	for(int i=1;i<m;i++)

		if(f[i][n])

		{

			f[i][n]=0;

			f[i+1][n] ^= 1;

			ans[++Ans][1]=i,ans[Ans][2]=n,ans[Ans][3]=i+1,ans[Ans][4]=n;

		}

	printf("%d\n",Ans);

	for(int i=1;i<=Ans;i++)

		printf("%d %d %d %d\n",ans[i][1],ans[i][2],ans[i][3],ans[i][4]);

	return 0;

}