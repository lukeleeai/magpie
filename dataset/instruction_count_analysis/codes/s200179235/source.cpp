#include"stdc++.h"

using namespace std;

typedef long long ll;

const int N=2e3+5;

ll dp[N][N];

struct p{

	int x,id;

	bool operator<(const p&a)const{

		return x>a.x; 

	}

}a[N];

int main(){

	int n;

	scanf("%d",&n);

	for(int i=1;i<=n;i++)

		scanf("%d",&a[i].x),a[i].id=i;

	sort(a+1,a+n+1);//从大到小排序 

	for(int k=1;k<=n;k++)//对第k个元素进行放置(前k-1个元素所有情况都已知) 

		for(int i=0;i<k;i++)//遍历前k-1元素的所有情况. i为往左放置的个数. 

		{

			int j=k-1-i;//前k-1元素往右放置的个数. 

			dp[i+1][j]=max(dp[i+1][j],dp[i][j]+(ll)a[k].x*(a[k].id-(i+1)));//往左放 

			dp[i][j+1]=max(dp[i][j+1],dp[i][j]+(ll)a[k].x*(n-j-a[k].id));//往右放 

		}

	ll ans=0;

	for(int i=0;i<=n;i++) ans=max(ans,dp[i][n-i]);//取最大值. 

	printf("%lld\n",ans);

	return 0;

}

 