#include<cstdio>

#include<iostream>

#include<algorithm>



using namespace std;



int memo[3][301];



int main(){

	for(int n,m;cin>>n>>m;){

		for(int i=0;i<3;i++)for(int j=0;j<=m;j++)	memo[i][j]=(j?-1:0);



		int ans=0;

		while(n--){

			getchar();	while(getchar()!='\n');

			int cost,prm[3];

			cin>>cost>>prm[0]>>prm[1]>>prm[2];

//			scanf("%d%d%d%d ",&cost,prm,prm+1,prm+2);

			for(int i=0;i<3;i++)for(int j=0;j+cost<=m;j++){

				if(memo[i][j]==-1)	continue;

				memo[i][j+cost]=max(memo[i][j+cost],memo[i][j]+prm[i]);

				ans=max(ans,memo[i][j+cost]);

			}

		}

		printf("%d\n",ans);

	}



	return 0;

}