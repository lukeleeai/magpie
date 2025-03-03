#include"stdc++.h"

#define LL long long

#define db double

 

using namespace std;

const int N=1000+10;

LL rd()

{

	LL x=0,w=1;char ch=0;

	while(ch<'0'||ch>'9'){if(ch=='-') w=-1;ch=getchar();}

	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}

	return x*w;

}

int zx[8]={1,1,1,0,0,-1,-1,-1},zy[8]={-1,0,1,-1,1,-1,0,1};

int n,c[N],s[N],fx[N][N],an[N][N];

bool ban[30];

void print()

{

	for(int i=1;i<=n;++i)

		for(int j=1;j<=n;++j)

		{

			memset(ban,0,sizeof(ban));

			if(fx[i][j]==1)

			{

				for(int k=0;k<8;++k)

				{

					int xx=i+zx[k],yy=j+zy[k];

					ban[an[xx][yy]]=1;

				}

				for(int k=0;k<8;++k)

				{

					int xx=i+1+zx[k],yy=j+zy[k];

					ban[an[xx][yy]]=1;

				}

				int sht=1;

				while(ban[sht]) ++sht;

				an[i][j]=an[i+1][j]=sht;

			}

			else if(fx[i][j]==2)

			{

				for(int k=0;k<8;++k)

				{

					int xx=i+zx[k],yy=j+zy[k];

					ban[an[xx][yy]]=1;

				}

				for(int k=0;k<8;++k)

				{

					int xx=i+zx[k],yy=j+1+zy[k];

					ban[an[xx][yy]]=1;

				}

				int sht=1;

				while(ban[sht]) ++sht;

				an[i][j]=an[i][j+1]=sht;

			}

		}

	for(int i=1;i<=n;++i)

	{

		for(int j=1;j<=n;++j)

			printf("%c",an[i][j]?an[i][j]+96:'.');

		puts("");

	}

	exit(0);

}

bool vs[N][N];

bool ck()

{

	for(int i=1;i<=n;++i)

		if(c[i]!=3||s[i]!=3) return 0;

	return 1;

}

void dfs(int x,int y)

{

	if(ck())

	{

		print();

		exit(0);

	}

	if(x>n) return;

	if(!vs[x][y])

	{

		if(x+1<=n&&!vs[x+1][y])

		{

			fx[x][y]=1,vs[x+1][y]=1,++c[x],++s[y],++c[x+1];

			y==n?dfs(x+1,1):dfs(x,y+1);

			vs[x+1][y]=0,--c[x],--s[y],--c[x+1];

		}

		if(y+1<=n&&!vs[x][y+1])

		{

			fx[x][y]=2,vs[x][y+1]=1,++c[x],++s[y],++s[y+1];

			y==n?dfs(x+1,1):dfs(x,y+1);

			vs[x][y+1]=0,--c[x],--s[y],--s[y+1];

		}

	}

	fx[x][y]=0,y==n?dfs(x+1,1):dfs(x,y+1);

}

int f3[3][3]={{2,0,1},{1,0,0},{0,2,0}};

int f4[4][4]={{2,0,1,1},{2,0,0,0},{1,1,2,0},{0,0,2,0}};

int f5[5][5]={{2,0,1,2,0},{1,0,0,2,0},{0,2,0,2,0},{1,1,1,0,0},{0,0,0,0,0}};

int f6[6][6]={{1,1,1,0,0,0},{0,0,0,0,0,0},{1,0,2,0,2,0},{0,1,2,0,0,0},{0,0,0,1,2,0},{2,0,0,0,2,0}};

 

int main()

{

	n=rd();

	if(n==2) puts("-1");

	else if(n==3)

	{

		for(int i=0;i<3;++i)

			for(int j=0;j<3;++j)

				fx[1+i][1+j]=f3[i][j];

		print();

	}

	else if(n==4)

	{

		for(int i=0;i<4;++i)

			for(int j=0;j<4;++j)

				fx[1+i][1+j]=f4[i][j];

		print();

	}

	else if(n==5)

	{

		for(int i=0;i<5;++i)

			for(int j=0;j<5;++j)

				fx[1+i][1+j]=f5[i][j];

		print();

	}

	else if(n==6)

	{

		for(int i=0;i<6;++i)

			for(int j=0;j<6;++j)

				fx[1+i][1+j]=f6[i][j];

		print();

	}

	else if(n==7)

	{

		puts(".aabbcc");

		puts("adde...");

		puts("ag.e...");

		puts("bgff...");

		puts("b...hhi");

		puts("c...k.i");

		puts("c...kjj");

	}

	else if(n%3==0)

	{

		for(int h=1;h<=n;h+=3)

			for(int i=0;i<3;++i)

				for(int j=0;j<3;++j)

					fx[h+i][h+j]=f3[i][j];

		print();

	}

	else

	{

		for(int h=1;h<=n;)

		{

			if(n-h+1==5)

			{

				for(int i=0;i<5;++i)

					for(int j=0;j<5;++j)

						fx[h+i][h+j]=f5[i][j];

				h+=5;

			}

			else if(n-h+1==6)

			{

				for(int i=0;i<6;++i)

					for(int j=0;j<6;++j)

						fx[h+i][h+j]=f6[i][j];

				h+=6;

			}

			else if(n-h+1==11)

			{

				for(int i=0;i<5;++i)

					for(int j=0;j<5;++j)

						fx[h+i][h+j]=f5[i][j];

				h+=5;

				for(int i=0;i<6;++i)

					for(int j=0;j<6;++j)

						fx[h+i][h+j]=f6[i][j];

				h+=6;

			}

			else

			{

				for(int i=0;i<4;++i)

					for(int j=0;j<4;++j)

						fx[h+i][h+j]=f4[i][j];

				h+=4;

			}

		}

		print();

	}

	return 0;

}