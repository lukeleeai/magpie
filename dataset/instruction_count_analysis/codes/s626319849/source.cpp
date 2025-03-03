#include<cstdio>

using namespace std;



int dp[330];

int s,d,m;

int k[110],w[110][55],p[110][55],f;



int main(){

  while(scanf("%d%d%d",&s,&d,&m)!=EOF){

    for(int i=0;i<s;i++){

      scanf("%d",&k[i]);

      for(int j=0;j<k[i];j++)scanf("%d%d",&w[i][j],&p[i][j]);

    }



    for(int i=0;i<=m;i++)dp[i] = -1;

    dp[0] = 0;



    for(int i=0;i<d;i++){

      scanf("%d",&f);

      for(int x=0;x<k[f];x++){

	int v = p[f][x], c = w[f][x];

	for(int j=m-v;j>=0;j--){

	  if(dp[j]>=0 && dp[j+v]<dp[j]+c)dp[j+v] = dp[j]+c;

	}

      }

    }

	

    int ans = 0;

    for(int i=1;i<=m;i++)

      if(dp[i] > dp[ans])ans = i;

    printf("%d %d\n",dp[ans],ans);

  }

}