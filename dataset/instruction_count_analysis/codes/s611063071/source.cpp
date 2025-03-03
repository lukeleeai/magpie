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

inline void quickSort(int s[],int l,int r)  {

    if(l<r){

        int i=l,j=r,x=s[l];

        while(i<j){

            while(i<j&&s[j]>=x) j--;

            if(i<j) s[i++]=s[j];

            while(i<j&&s[i]<x) i++;

            if(i<j) s[j--] = s[i];

        }

        s[i]=x;

        quickSort(s, l, i - 1);

        quickSort(s, i + 1, r);

    }

}

int x,y;

vector<int> S[777],T[777],v[777],b[777];

bool dp[777];

int can[777][777],n,m;

int col[777],cha,best;

int cnt[2],add,ta,tb;

inline int rds(int x){return ((x-1)*x)/2;}

inline void dfs(int x,int co){

//	cout<<x<<' '<<co<<endl;

	if(col[x]==(!co)){

		write(-1);

		putchar('\n');

		exit(0);

	}

	if(col[x]==co) return;

	col[x]=co;

    cnt[co]++;

	for(int i=0;i<b[x].size();i++) dfs(b[x][i],!co);

	return; 

}

int main(){

	ios_base::sync_with_stdio(false);

	int i,j,x,y;

	rd(n),rd(m);

	for(i=1;i<=m;i++){

		rd(x),rd(y);

		can[x][y]=1;

		can[y][x]=1;

		v[x].push_back(y);

		v[y].push_back(x);

	}

	for(i=1;i<=n;i++) for(j=1;j<=n;j++) if(!can[i][j]&&i!=j) b[i].push_back(j),b[j].push_back(i);

	memset(col,-1);

	dp[0]=1;

	for(i=1;i<=n;i++){

		if(col[i]==-1){

//			for(j=1;j<=n;j++) cout<<col[j]<<' ';

//			cout<<endl;

			cnt[0]=0;

			cnt[1]=0;

			dfs(i,0);

			if(cnt[0]>cnt[1]) swap(cnt[0],cnt[1]);

	        add+=cnt[0];

    	    cha=cnt[1]-cnt[0];

    	    for(j=n+1;j>=cha;j--) if(dp[j-cha]) dp[j]=1;

		}

	}

//	for(i=1;i<=n;i++) cout<<dp[i]<<' ';

//	cout<<endl;

	best=pow(n,2);

	for(i=0;i<=n;i++){

		if(dp[i]) {

        	ta=add+i,tb=n-ta;

        	best=min(best,rds(ta)+rds(tb));

    	}

	}

	write(best);

	putchar('\n');

	return 0;

}
