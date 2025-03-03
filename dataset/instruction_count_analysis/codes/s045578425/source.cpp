# include<cstdio>

# include<cstring>

using namespace std;

char map[52][52],ans[52][52];

int dir[8][2]={{0,-1},{0,1},{-1,0},{1,0},{-1,1},{1,1},{1,-1},{-1,-1}};

int n,m;

void work(int x,int y)

{

	int count=0;

	for(int i=0;i<8;i++)

	{

		int newx=x+dir[i][0];

		int newy=y+dir[i][1];

		if(newx<1 || newx>n || newy<1 || newy>m)continue;

		if(map[newx][newy]=='#')count++;

	}

	ans[x][y]=count+'0';

	//printf("%d %d %d\n",x,y,count);

}

char get_char()

{

	char c=getchar();

	while(c==' ' || c=='\n')c=getchar();

	return c;

}

int main()//AT3595

{

	scanf("%d%d",&n,&m);

	for(int i=1;i<=n;i++)

		for(int j=1;j<=m;j++)

			map[i][j]=get_char();

	for(int i=1;i<=n;i++)	

		for(int j=1;j<=m;j++)

		{

			if(map[i][j]=='.')work(i,j);

			else ans[i][j]='#';

		}

	for(int i=1;i<=n;i++)

	{

		for(int j=1;j<=m;j++)

			putchar(ans[i][j]);

		putchar('\n');

	}

	return 0;

}