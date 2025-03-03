#include<cstdio>

int main()

{

	int N;

	scanf("%d",&N);

	int ans=N;

	for(int i=0;i<=N;i++)

	{

		int num=0,t=i;

		while(t) num+=t%6,t/=6;

		t=N-i;

		while(t) num+=t%9,t/=9;

		if(num<ans) ans=num;

	}

	printf("%d\n",ans);

	return 0;

}

/*#include<cstdio>

int N,C;

int t[3][35],d[35][35];

//t[i][j]:余数为i,颜色为j的数量

int main()

{

	int ans=0x3f3f3f3f;

	scanf("%d %d",&N,&C);

	for(int i=1;i<=C;i++)

		for(int j=1;j<=C;j++)

			scanf("%d",&d[i][j]);

	for(int i=1;i<=N;i++)

		for(int j=1;j<=N;j++)

		{

			int x;

			scanf("%d",&x);

			t[(i+j)%3][x]++;

		}

	int res=0;

	for(int i=0;i<=2;i++)

		for(int j=1;j<=C;j++)//余数为i的格子全部变成颜色j

			for(int k=1;k<=C;k++)

				res+=t[i][k]*d[k][i];

}*/