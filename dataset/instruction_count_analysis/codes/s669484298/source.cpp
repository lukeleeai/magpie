#include"stdc++.h"

using namespace std;

typedef long long ll;

const int N=2e3+5;

vector<pair<ll,ll> >v(N);//vector对pair排序时按'键'排序 即第一元素first 

ll dp[N][N];

int n;

ll fun(int l,int r){

	if(l>r) return 0;

	if(dp[l][r]) return dp[l][r];

	int i=n-(r-l+1);//当前要放入的数的下标 

	return dp[l][r]=max(fun(l,r-1)+v[i].first*(r-v[i].second),fun(l+1,r)+v[i].first*(v[i].second-l));//放两端取最大 

}

int main(){

	scanf("%d",&n);

	for(int i=0,x;i<n;i++)

		scanf("%d",&x),v.push_back({x,i});

	sort(v.rbegin(),v.rend());//贪心从大到小排 

	fun(0,n-1);

	printf("%lld\n",dp[0][n-1]);

	return 0;

}