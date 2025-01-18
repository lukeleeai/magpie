#include"stdc++.h"

using namespace std;

typedef long long ll;

typedef pair<int,int> pii;

#define fe(i,a,b) for(int i=(a);i<=(b);i++)

#define fne(i,a,b) for(int i=(a);i<(b);i++)

#define read(x) scanf("%d",&x)

#define read2(x,y) scanf("%d%d",&x,&y)

#define read3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define readll(x) scanf("%lld",&x)

#define mst(a,b) memset(a,b,sizeof(a))

#define all(x) x.begin(),x.end()

#define pb push_back

#define lowbit(x) x&-x

#define lc rt<<1

#define rc rt<<1|1

#define ls lc,l,m

#define rs rc,m+1,r

#define dbg(x) cout<<' '<<#x<<" = "<<x<<endl;

#define dbg2(x,y) cout<<' '<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl;

#define dbg3(x,y,z) cout<<' '<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl;

const int INF =0x3f3f3f3f;

const int mod = 1e9+7;

const double eps=1e-8;

const int N = 2e5+5;

int dir[4][2]={0,1,0,-1,1,0,-1,0};

int mon[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};

ll dp[N];

int h[N];

int main(){

//	freopen("BZW.txt","r",stdin);

	//freopen("BZW.txt","r",stdin);

	//freopen("BZW.txt","r",stdin);

	//freopen("BZW.txt","r",stdin);

	int n,k;

	read2(n,k);

	fe(i,1,n)read(h[i]);

	mst(dp,0x3f);

    dp[1] = 0;

    fe(i,1,n){

		fe(j,1,k){

			if(i-j<1)break;

			dp[i] = min(dp[i],dp[i-j]+abs(h[i]-h[i-j]));

		}

    }

    printf("%lld\n",dp[n]);









	return 0;

}
