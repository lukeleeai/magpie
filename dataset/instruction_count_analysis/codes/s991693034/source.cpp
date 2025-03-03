#include<cstdio>

#define maxn 505

int n,m;

char s[3][maxn][maxn];

int main()

{

	scanf("%d%d",&n,&m);

	for(int i=1;i<=n;i++) scanf("%s",s[2][i]+1);

	for(int i=1;i<=n;i++)

		for(int j=1;j<=m;j++)

			s[i&1][i][j]='#',s[(i&1)^1][i][j]='.';

	for(int i=1;i<=n;i++) s[0][i][1]=s[1][i][m]='#',s[0][i][m]=s[1][i][1]='.';

	for(int i=1;i<=n;i++)

		for(int j=1;j<=m;j++)

			if(s[2][i][j]=='#') s[0][i][j]=s[1][i][j]='#';

	for(int i=1;i<=n;i++) printf("%s\n",s[0][i]+1);

	printf("\n");

	for(int i=1;i<=n;i++) printf("%s\n",s[1][i]+1);

}