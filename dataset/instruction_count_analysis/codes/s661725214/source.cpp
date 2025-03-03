#include<cstdio>

const int maxn = 110;

int tag[maxn*maxn];

int tmp[maxn*maxn];

int ans[maxn][maxn];

int main()

{

	int n,m;

	while(~scanf("%d%d",&n,&m)){

		int times,cnt = 1,change = 1;

		scanf("%d",&times);

		for(int i = 1; i <= times; i++){

			scanf("%d",&tag[i]);

			for(int j = 1; j<=tag[i]; j++){

				tmp[cnt] = i; cnt++;

			}

		}

		cnt = 1;

		for(int i = 1; i<=n; i++){

			if(change == 1){

				for(int j = 1; j<=m; j++){

					ans[i][j] = tmp[cnt];

					cnt++;

				}

			}else {

				for(int j = m; j>=1; j--){

					ans[i][j] = tmp[cnt];

					cnt++;

				}

			}

			change = change * -1;

		}

		for(int i = 1; i<=n; i++){

			for(int j = 1; j<=m; j++){

				if(j == 1) printf("%d ",ans[i][j]);

				else printf("%d ",ans[i][j]);

			}

			printf("\n");

		}

	}

	return 0;

}