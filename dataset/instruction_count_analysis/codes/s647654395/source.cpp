# include "iostream"

# include "cstdio"

# include "algorithm" 



using namespace std;



const int maxm=1000+10; 



int n,	//n个蛋糕 

	m; 	//取出m个蛋糕 



long long 

	dp[9][maxm], 

	ans,now; 



int main(){

	long long x,y,z;

	register int i,j; 

	scanf("%d%d",&n,&m);

	for(i=1;i<=n;i++){

		scanf("%lld%lld%lld",&x,&y,&z); 

		dp[1][i]=x+y+z; 

		dp[2][i]=x+y-z;

		dp[3][i]=x-y+z;

		dp[4][i]=-x+y+z;

		dp[5][i]=x-y-z;

		dp[6][i]=-x-y+z;

		dp[7][i]=-x+y-z;

		dp[8][i]=-x-y-z;

	}

	for(i=1;i<=8;i++){

		sort(dp[i]+1,dp[i]+1+n,greater<long long>());

		now=0; 

		for(j=1;j<=m;j++){

			now+=dp[i][j]; 

		}

		ans=max(ans,now); 

	}

	printf("%lld",ans); 

	return 0; 

} 