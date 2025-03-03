#include <cstdio>

#include <algorithm>

#include <vector>

using namespace std;

 

long long n,val[100005],w,v,k,mxw,ans;

bool dp[100005]; 

int main(){

	dp[0]=true;

	scanf("%lld%lld",&n,&mxw);

	for (int i=1;i<=n;i++){

		scanf("%lld%lld",&w,&v);

		for (int j=mxw;j>=0;j--){

			if (dp[j]== true && j+w <= mxw){

				dp[j+w]=true;

				val[j+w]=max(val[j+w],val[j]+v);

			}

		}

	}

	ans=0;

	for (int i=mxw;i>=1;i--){

		ans=max(ans,val[i]);

	}

	printf("%lld\n",ans);

	return 0;

} 