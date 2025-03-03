#include<cmath>

#include<math.h>

#include<ctype.h>

#include<algorithm>

#include<bitset>

#include<cassert>

#include<cctype>

#include<cerrno>

#include<cfloat>

#include<ciso646>

#include<climits>

#include<clocale>

#include<complex>

#include<csetjmp>

#include<csignal>

#include<cstdarg>

#include<cstddef>

#include<cstdio>

#include<cstdlib>

#include<cstring>

#include<ctime>

#include<cwchar>

#include<cwctype>

#include<deque>

#include<exception>

#include<fstream>

#include<functional>

#include<iomanip>

#include<ios>

#include<iosfwd>

#include<iostream>

#include<istream>

#include<iterator>

#include<limits>

#include<list>

#include<locale>

#include<map>

#include<memory>

#include<new>

#include<numeric>

#include<ostream>

#include<queue>

#include<set>

#include<sstream>

#include<stack>

#include<stdexcept>

#include<streambuf>

#include<string>

#include<typeinfo>

#include<utility>

#include<valarray>

#include<vector>

#include<string.h>

#include<stdlib.h>

#include<stdio.h>

#define ll   long long

#define pb push_back

#define mp make_pair

#define F first

#define S second

#define MAX 100000000000000000

#define MOD 1000000007

#define files  freopen("OUTPUT.TXT","r",stdin);

#define PI 3.141592653589793238462

#define INF 1000000000

using namespace std;

int n,mx,dp[100005];

vector<int> v[100005];

void dfs(int x,int fa){

	dp[x]=0;

	int need=v[x].size()-1,cnt=0;

	for (int i=0;i<v[x].size();i++){

		int u=v[x][i];

		if (u==fa) continue;

		dfs(u,x);

		dp[x]+=dp[u];

		cnt+=(dp[u]!=0);

	}

	dp[x]+=max(0,(int)v[x].size()-(fa!=(-1))-cnt-1);

}

int main(){

	//freopen("input.txt","r",stdin);

	//freopen("output.txt","w",stdout);

	cin>>n;

	if (n==2){

		cout<<1;

		return 0;

	}

	for (int i=1;i<n;i++){

		int p,q;

		cin>>p>>q;

		v[p].pb(q);

		v[q].pb(p);

	}

	for (int i=1;i<n;i++){

		if (v[i].size()>v[mx].size()) mx=i;

	}

	dfs(mx,-1);

	cout<<dp[mx];

	return 0;

}
