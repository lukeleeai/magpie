#include"stdc++.h"

#define sqr(x) ((x)*(x))

#define ll long long

#define ull unsigned long long

#define ui unsigned int

#define ld long double

#define vi vector<int>

#define pii pair<int,int>

#define pb push_back

#define mp make_pair

#define debuge cerr<<"isok"<<endl

#define debug(x) cerr<<#x<<"="<<x<<endl

#define SS second

#define FF first

#define ls (k<<1)

#define rs (k<<1|1)

#define inf 0x3f3f3f3f

#define clr(a,x) memset(a,x,sizeof(a))

#define cpy(a,x) memcpy(a,x,sizeof(a))

#define file(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout);

using namespace std;



const int N=100005,M=100005,mod=1e9+7;

template<class T> inline void gmin(T &x,const T &y){if(x>y) x=y;}

template<class T> inline void gmax(T &x,const T &y){if(x<y) x=y;}

inline void ch(int &x,int y){x=(x+y)%mod;}

inline void read(int &x){

	x=0;char ch=getchar(),rev=0;

	while(ch>'9'||ch<'0') rev=(ch=='-'),ch=getchar();

	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();

	x=rev?-x:x;

}

inline int exp(int x,int y){

	int ans=1;

	while(y){

		if(y&1) ans=(ll)ans*x%mod;

		x=(ll)x*x%mod;y>>=1;

	}return ans;

}



int n,m,pw[20],dp[1<<15],cnt[20][1<<15];

bool g[20][20];



int solve(int mask){

	if((mask&1)^(mask>>1&1)) return 0;

	if(mask==3) return 1;

	if(~dp[mask]) return dp[mask];

	int ans=0;

	for(int i=mask-1;i;i=(i-1)&mask){

		int res=solve(i);

		for(int j=0;j<n;j++)

			if(i&(1<<j)) res=(ll)res*(pw[cnt[j][mask^i]]-1)%mod;

		i^=mask;

		for(int j=0;j<n;j++)

			if(i&(1<<j)) res=(ll)res*pw[cnt[j][mask^i]]%mod;

		i^=mask;ch(ans,res);

//		printf("%d %d\n",i,res);

	}

	ch(ans,1);

	return dp[mask]=ans;

}



int main(){

#ifdef rqgao2014

	freopen("input.txt","r",stdin);

#endif

	pw[0]=1;

	for(int i=1;i<=20;i++) pw[i]=pw[i-1]*2;

	scanf("%d%d",&n,&m);

	for(int i=1;i<=m;i++){

		int x,y;scanf("%d%d",&x,&y);

		x--;y--;

		g[x][y]=1;

	}

	clr(dp,-1);

	for(int i=0;i<n;i++)

		for(int mask=0;mask<(1<<n);mask++){

			if(mask&(1<<i)) continue;

			for(int j=0;j<n;j++)

				if((mask&(1<<j))&&g[i][j]) cnt[i][mask]++;

		}

	printf("%d\n",(exp(2,m)-solve((1<<n)-1)+mod)%mod);

	return 0;

}