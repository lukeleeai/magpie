#include<iostream>

#include<cstdio>

#include<cmath>

#include<algorithm>

#include<string>

#include<vector>

#include<map>

#include<stack>

#include<queue>



using namespace std;

#define MAX 100005

static const int INF=1<<19;



int main(){

	int N,W;

	int dp[MAX];

	int ans=0;

	

	fill(dp,dp+MAX,-INF);

	dp[0]=0;

	

	scanf("%d %d",&N,&W);

	for(int i=0;i<N;i++){

		int v,w,m;

		scanf("%d %d %d",&v,&w,&m);

		for(int k=0;m>0;k++){

			int key=min(m,(1<<k));

			m-=key;

			for(int j=W;j>=key*w;j--){

				dp[j]=max(dp[j],dp[j-key*w]+key*v);

			}

		}

	}

	for(int i=0;i<=W;i++) ans=max(ans,dp[i]);

	printf("%d\n",ans);

}
