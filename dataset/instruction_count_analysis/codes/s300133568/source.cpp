#include "stdc++.h"

#define ll long long

#define INF 999999999

#define MOD 1000000007

#define rep(i,n) for(int i=0;i<n;i++)



using namespace std;



typedef pair<int,int>P;



const int MAX_N = 100005;



int dp[MAX_N];



int main()

{

	int n,W;

	int v,w,m;

	scanf("%d%d",&n,&W);

	fill(dp,dp+MAX_N,-INF);

	dp[0] = 0;

	rep(i,n){

		scanf("%d%d%d",&v,&w,&m);

		for(int j=0;m>0;j++){

			int hoge = min(m,(1<<j));

			m-=hoge;

			for(int k=W;k>=hoge*w;k--){

				dp[k] = max(dp[k],dp[k-hoge*w]+hoge*v);

			}

		}

	}

	cout << *max_element(dp,dp+W+1) << "\n";

	return 0;

}