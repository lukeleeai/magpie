// This amazing code is by Eric Sunli Chen.

#include <algorithm>

#include <bitset>

#include <cmath>

#include <cstring>

#include <cstdio>

#include <cstdlib>

#include <ctime>

#include <iomanip>

#include <iostream>

#include <map>

#include <queue>

#include <set>

#include <string>

#include <utility>

#include <vector>

using namespace std;

template<typename T> bool get_int(T &x)

{

	char t=getchar();

	bool neg=false;

	x=0;

	for(; (t>'9'||t<'0')&&t!='-'&&t!=EOF; t=getchar());

	if(t=='-')neg=true,t=getchar();if(t==EOF)return false;

	for(; t<='9'&&t>='0'; t=getchar())x=x*10+t-'0';

	if(neg)x=-x;return true;

}

template<typename T> void print_int(T x)

{

	if(x<0)putchar('-'),x=-x;

	short a[20]= {},sz=0;

	while(x>0)a[sz++]=x%10,x/=10;

	if(sz==0)putchar('0');

	for(int i=sz-1; i>=0; i--)putchar('0'+a[i]);

}

#define ff first

#define ss second

#define pb push_back

#define mp make_pair

#define get1(a) get_int(a)

#define get2(a,b) (get1(a)&&get1(b))

#define get3(a,b,c) (get1(a)&&get2(b,c))

#define printendl(a) print_int(a),puts("")

typedef long long LL;

typedef unsigned long long uLL;

typedef pair<int,int> pii;

const int inf=0x3f3f3f3f;

const LL Linf=1ll<<61;

const double pi=acos(-1.0);



vector<int>g[2333],seq[2333],tmp;

bool use[2333];

int n,a[2333];



void dfs(int x)

{

	use[x]=1;

	for(auto v:g[x])if(!use[v])

	{

		dfs(v);

		tmp.resize(seq[x].size()+seq[v].size());

		merge(seq[x].begin(),seq[x].end(),seq[v].begin(),seq[v].end(),tmp.begin());

		seq[x]=tmp;

	}

	seq[x].resize(seq[x].size()+1);for(int i=seq[x].size()-2;i>=0;i--)seq[x][i+1]=seq[x][i];

	seq[x][0]=-a[x];

}



int main()

{

	get1(n);

	for(int i=1;i<=n;i++)

		get1(a[i]);

	sort(a+1,a+n+1);

	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(i!=j&&__gcd(a[i],a[j])>1)

	{

		g[i].pb(j);

		g[j].pb(i);

	}

	for(int i=1;i<=n;i++)sort(g[i].begin(),g[i].end());

	vector<int> ans;

	for(int i=1;i<=n;i++)

	{

		if(use[i])continue;

		dfs(i);

		tmp.resize(ans.size()+seq[i].size());

		merge(ans.begin(),ans.end(),seq[i].begin(),seq[i].end(),tmp.begin());

		ans=tmp;

	}

	for(auto x:ans)printf("%d ",-x);

	return 0;

}