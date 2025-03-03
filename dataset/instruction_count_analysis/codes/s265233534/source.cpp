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



int main(){

	int N,W;

	

	scanf("%d %d",&N,&W);

	vector<int> dp(W+1,0);

	

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

	

	int ans=0;

	for(int i=0;i<=W;i++) ans=max(ans,dp[i]);

	printf("%d\n",ans);

}
