#include<map>

#include<iostream>

#include<iomanip>

//#include<conio.h>

#include<algorithm>

#include<vector>

#include<set>

#include<cmath>

#include<stdio.h>

#include<fstream>

#include<assert.h>

#include<time.h>

#include<queue>

#include<deque>

#include<stack>

#include<list>

#include<sstream>

#include<string.h>

#define mp make_pair

#define ll long long

#define all(v) v.begin(),v.end()

#define memset(a,b) memset(a,b,sizeof(a))

using namespace std;

const int INF=1e9;

inline void write(int x){

    if(x<0) putchar('-'),x=-x;

    if(x>9) write(x/10);

    putchar(x%10+'0');

}

inline void rd(int &val){

    int x=0;

    int f=1;

    char ch=getchar();

    while((ch<'0'||ch>'9')&&ch!='-') ch=getchar();

	if(ch=='-'){

		f=-1;

		ch=getchar();

	}

    while(ch>='0'&&ch<='9'){

        x=x*10+ch-'0';

        ch=getchar();

    }

    val=x*f;

}

int x,y;

bool ok=1;

int can[1005][1005],n,m;

int dp[1005];

int col[1005],cha,best;

int cnt[3],add,ta,tb;

inline int rds(int x){return ((x-1)*x)/2;}

inline bool dfs(int x,int co){

//	cout<<x<<' '<<co<<endl;

	if(col[x]==(!co)) return 0;

	if(col[x]==co) return 1;

	col[x]=co;

    cnt[co]++;

	for(int i=0;i<n;i++) if(can[x][i]) if(!dfs(i,!co)) return 0;

	return 1;

}

int main(){

	ios_base::sync_with_stdio(false);

	int i,j,x,y;

	cin>>n>>m;

	memset(can,1);

	for(i=0;i<=n;i++) can[i][i]=0;

	for(i=0;i<m;i++){

		cin>>x>>y;

		x--,y--;

		can[x][y]=0;

		can[y][x]=0;

	}

	memset(col,-1);

	dp[0]=1;

	for(i=0;i<n;i++){

		if(col[i]==-1){

//			for(j=1;j<=n;j++) cout<<col[j]<<' ';

//			cout<<endl;

			cnt[0]=0;

			cnt[1]=0;

			if(!dfs(i,0)) ok=0;

			if(cnt[0]>=cnt[1]) swap(cnt[0],cnt[1]);

	        add+=cnt[0];

    	    cha=cnt[1]-cnt[0];

    	    for(j=n;j>=cha;j--){

  //  	    	cout<<j<<' ';

    	    	if(dp[j-cha]) dp[j]=1;

			}

//			cout<<endl;

		}

	}

//	for(i=1;i<=n;i++) cout<<dp[i]<<' ';

//	cout<<endl;

	best=n*n;

	for(i=0;i<=n;i++){

		if(dp[i]){

        	ta=add+i,tb=n-ta;

        	best=min(best,rds(ta)+rds(tb));

    	}

	}

	if(!ok) cout<<-1<<endl;

	else cout<<best<<endl;

	return 0;

}