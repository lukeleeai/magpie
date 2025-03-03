# include "cstdio"

# include "algorithm" 

 

const int maxm=1000+10; 

 

int n,	//n个蛋糕 

	m; 	//取出m个蛋糕 

 

long long 

	dp[5][maxm], 

	ans,now1,now2; 

 

inline long long read(){

	long long s=0,w=1;

	char ch=getchar();

	while(ch<'0' || ch>'9'){

		if(ch=='-') w=-w;

		ch=getchar();

	}

	while(ch>='0' && ch<='9'){

		s=s*10+ch-'0';

		ch=getchar();

	}

	return s*w;

}



inline long long max(long long x,long long y){

	return x>y?x:y; 

} 



inline bool comp(long long x,long long y){

	return x>y?true:false; 

} 



int main(){

	long long x,y,z;

	register int i,j; 

	n=read(),m=read();

	for(i=1;i<=n;i++){

		x=read(),y=read(),z=read(); 

		dp[1][i]=x+y+z; //-x-y-z

		dp[2][i]=x+y-z;	//-x-y+z

		dp[3][i]=x-y+z;	//-x+y-z

		dp[4][i]=x-y-z;	//-x+y+z

	}

	for(i=1;i<=4;i++){

		std::sort(dp[i]+1,dp[i]+1+n,comp);

		now1=now2=0; 

		for(j=1;j<=m;j++){

			now1+=dp[i][j];

			now2+=dp[i][n-j+1]; 

		}

		now1=now1>0?now1:-now1;

		now2=now2>0?now2:-now2; 

		ans=max(ans,max(now1,now2)); 

	}

	printf("%lld",ans); 

	return 0; 

} 