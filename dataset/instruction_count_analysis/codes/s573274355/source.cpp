//メモリ数確認したか?

#include<iostream>

#include<cstdio>

#include<string>

#include<vector>

#include<algorithm>

#include<cstdlib>

#include<math.h>

#include<set>

#include<map>

#include<queue>

using namespace std;

typedef long long int ll;



int main()

{

    int N,K;

	int C[2000],G[2000];

	vector<int>X[10];

	scanf("%d%d",&N,&K);

	for(int i=0;i<N;i++){

		scanf("%d%d",&C[i],&G[i]);

		X[G[i]-1].push_back(C[i]);

	}

	for(int i=0;i<10;i++){

		sort(X[i].begin(),X[i].end());

		reverse(X[i].begin(),X[i].end());

	}

	int sum[10][2001];

	for(int i=0;i<10;i++){

		sum[i][0]=0;

		for(int j=1;j<=X[i].size();j++){

			sum[i][j]=sum[i][j-1]+X[i][j-1]+2*(j-1);

		}

	}

	int dp[2001];

	fill(dp,dp+N+1,0);

	for(int i=0;i<10;i++){

		for(int j=2000-X[i].size();j>=0;j--){

			for(int k=0;k<=X[i].size();k++){

				dp[j+k]=max(dp[j+k],dp[j]+sum[i][k]);

			}

		}

	}

	printf("%d\n",dp[K]);

    return 0;

}

//メモリ数確認したか?