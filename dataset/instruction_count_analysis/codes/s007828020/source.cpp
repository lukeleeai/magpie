#include"stdc++.h"

using namespace std;

#define ll long long

#define rep(i,a,b) for(int i=a;i<=b;i++)

#define per(i,a,b) for(int i=a;i>=b;i--)

#define mset(s,_) memset(s,_,sizeof s)

#define fi first

#define se second

#define pb push_back



template<typename T>

void chmax(T &a,T b){

  if(a<b)a=b;

}



map<int,ll>dp[200010];

ll a[200010],n;



ll dfs(int num,int k){

	if(k<=0) return 0;

  if(num==n&&k==1) return a[num];

  if(k>(n-num)/2+1) return -1e18;

	if(dp[num].count(k)) return dp[num][k];

	if((n-num+1)&1){

		 return dp[num][k]=max(dfs(num+2,k-1)+a[num],max(dfs(num+3,k-1)+a[num+1],dfs(num+4,k-1)+a[num+2]));

	}

	else {

		return dp[num][k]=max(dfs(num+2,k-1)+a[num],dfs(num+3,k-1)+a[num+1]);

	}

}



int main(){

	cin>>n;

	rep(i,1,n) cin>>a[i];

	a[1+n]=-1e18;

	a[2+n]=-1e18;

	a[3+n]=-1e18;

	cout<<dfs(1,n/2)<<'\n';

}



	

	

	