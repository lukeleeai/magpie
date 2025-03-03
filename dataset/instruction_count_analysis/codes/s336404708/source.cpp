#include<cstdio>

#include<algorithm>

using namespace std;



char c[101][102];

int f[101][102];

int main(){

	int n,m;

	scanf("%d%d",&n,&m);

	for(int i=1;i<=n;i++)

		scanf("%s",c[i]+1);

	for(int i=1;i<=n;i++)

		for(int j=1;j<=m;j++){

			if(i==1&&j==1){

				f[i][j]=(c[i][j]=='#');

				continue;

			}

			f[i][j]=2e9;

			if(i!=1)f[i][j]=min(f[i][j],f[i-1][j]+(c[i-1][j]=='.'&&c[i][j]=='#'));

			if(j!=1)f[i][j]=min(f[i][j],f[i][j-1]+(c[i][j-1]=='.'&&c[i][j]=='#'));

		}

	printf("%d\n",f[n][m]);

}
