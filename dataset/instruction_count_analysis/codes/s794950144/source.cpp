#include<cstdio>

#include<algorithm>

using namespace std;

const int MAXN=505;

int n,m,f[MAXN][MAXN];

int ans,Ans[MAXN*MAXN][5];

int main(){

	scanf("%d%d",&n,&m);

	for(int i=1;i<=n;i++)

		for(int j=1;j<=m;j++)

			scanf("%d",&f[i][j]);

	for(int i=1;i<=n;i++){

		for(int j=1;j<m;j++)

			if(f[i][j]%2==1){

				f[i][j]--;

				f[i][j+1]++;

				ans++;

				Ans[ans][1]=i;

				Ans[ans][2]=j;

				Ans[ans][3]=i;

				Ans[ans][4]=j+1;

			}

		if(f[i][m]%2==1&&i!=n){

			f[i][m]--;

			f[i+1][m]++;

			ans++;

			Ans[ans][1]=i;

			Ans[ans][2]=m;

			Ans[ans][3]=i+1;

			Ans[ans][4]=m;

		}

	}

	printf("%d\n",ans);

	for(int i=1;i<=ans;i++)

		printf("%d %d %d %d\n",Ans[i][1],Ans[i][2],Ans[i][3],Ans[i][4]);

}