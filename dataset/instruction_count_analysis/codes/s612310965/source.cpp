//Coded by tzc_wk

/*

数据不清空，爆零两行泪。

多测不读完，爆零两行泪。

边界不特判，爆零两行泪。

贪心不证明，爆零两行泪。

D P 顺序错，爆零两行泪。

大小少等号，爆零两行泪。

变量不统一，爆零两行泪。

越界不判断，爆零两行泪。

调试不注释，爆零两行泪。

溢出不 l l，爆零两行泪。

*/

#include "stdc++.h"

using namespace std;

#define fi			first

#define se			second

#define fz(i,a,b)	for(int i=a;i<=b;i++)

#define fd(i,a,b)	for(int i=a;i>=b;i--)

#define foreach(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)

#define all(a)		a.begin(),a.end()

#define giveup(...) return printf(__VA_ARGS__),0;

#define fill0(a)	memset(a,0,sizeof(a))

#define fill1(a)	memset(a,-1,sizeof(a))

#define fillbig(a)	memset(a,0x3f,sizeof(a))

#define fillsmall(a) memset(a,0xcf,sizeof(a))

#define mask(a)		(1ll<<(a))

#define maskx(a,x)	((a)<<(x))

#define _bit(a,x)	(((a)>>(x))&1)

#define _sz(a)		((int)(a).size())

#define filei(a)	freopen(a,"r",stdin);

#define fileo(a)	freopen(a,"w",stdout);

#define fileio(a) 	freopen(a".in","r",stdin);freopen(a".out","w",stdout)

#define eprintf(...) fprintf(stderr,__VA_ARGS__)

#define put(x)		putchar(x)

#define eoln        put('\n')

#define space		put(' ')

#define y1			y_chenxiaoyan_1

#define y0			y_chenxiaoyan_0

typedef pair<int,int> pii;

inline int read(){

	int x=0,neg=1;char c=getchar();

	while(!isdigit(c)){

		if(c=='-')	neg=-1;

		c=getchar();

	}

	while(isdigit(c))	x=x*10+c-'0',c=getchar();

	return x*neg;

}

inline void print(int x){

	if(x<0){

		putchar('-');

		print(abs(x));

		return;

	}

	if(x<=9)	putchar(x+'0');

	else{

		print(x/10);

		putchar(x%10+'0');

	}

}

inline int qpow(int x,int e,int _MOD){

	int ans=1;

	while(e){

		if(e&1)	ans=ans*x%_MOD;

		x=x*x%_MOD;

		e>>=1;

	}

	return ans;

}

int n=read();

vector<int> g[200005];

int col[200005];

int cnt[2],a[200005];

inline void dfs(int x,int fa){

	col[x]=col[fa]^1;

	cnt[col[x]]++;

	foreach(it,g[x]){

		int y=*it;

		if(y==fa)	continue;

		dfs(y,x);

	}

}

signed main(){

	fz(i,1,n-1){

		int x=read(),y=read();

		g[x].push_back(y);

		g[y].push_back(x);

	}

	dfs(1,0);

	set<int> st;

	fz(i,1,n)	st.insert(i);

	if(cnt[0]<=n/3){

		int cnt1=0;

		fz(i,1,n)	if(col[i]==0)	cnt1++,a[i]=cnt1*3,st.erase(st.find(a[i]));

		fz(i,1,n){

			if(!a[i])	a[i]=*st.begin(),st.erase(st.begin());

		}

	}

	else if(cnt[1]<=n/3){

		int cnt1=0;

		fz(i,1,n)	if(col[i]==1)	cnt1++,a[i]=cnt1*3,st.erase(st.find(a[i]));

		fz(i,1,n){

			if(!a[i])	a[i]=*st.begin(),st.erase(st.begin());

		}

	}

	else{

		int cnt1=0,cnt2=0;

		fz(i,1,n){

//			cout<<col[i]<<endl;

			if(col[i]==0&&cnt1*3+1<=n)	a[i]=cnt1*3+1,cnt1++,st.erase(st.find(a[i]));

			if(col[i]==1&&cnt2*3+2<=n)	a[i]=cnt2*3+2,cnt2++,st.erase(st.find(a[i]));

			}

		fz(i,1,n){

			if(!a[i])	a[i]=*st.begin(),st.erase(st.begin());

		}

	}

	fz(i,1,n)	cout<<a[i]<<" ";

	return 0;

}