#include<iostream>

#include<numeric>

#include<math.h>

#include<vector>

#include<algorithm>

#include<set>

#include<map>

#include<queue>

#include<climits>

#define fi first

#define se second

#define pb push_back

#define pii pair<int,int>

#define ll long long

#define pll pair<ll,ll>

#define rep(i,from,to) for(int i=from;i<to;i++)

#define repd(i,from,till) for(int i=from;i>=till;i--)

#define waste ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

#define inf 1000000001

#define mod 1e9+7

#define inf1 1e18+1

#define pie 3.14159265358979323846

#define N 100005



using namespace std;



int n,k;

ll a[100002];

ll dp[100002];



int rec(int i){

	if(i+k>=n)return abs(a[i]-a[n-1]);

	if(dp[i]!=inf)return dp[i];

	rep(j,0,k){

		dp[i]=min(dp[i],abs(a[i]-a[i+j+1])+rec(i+1+j));

	}

	return dp[i];

}



int solve(){

	rep(i,0,100002)dp[i]=inf;

    cin>>n>>k;

	rep(i,0,n)cin>>a[i];

	cout<<rec(0)<<endl;

	return 0;

}

int main(){

    waste;

    int t;

    //cin>>t;

    t=1;

    while(t--){

       	solve();

    }

}
