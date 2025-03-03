/*

×¢Òâ·¶Î§£¡

short·¶Î§£º-32768~32767

unsigned short·¶Î§£º0~65535

int·¶Î§£º-2147483648~2147483647

uint·¶Î§£º0~4294967295

INT·¶Î§£º-9223372036854775808~9223372036854775807

UINT·¶Î§£º0~18446744073709551615

float·¶Î§£º-3.4e38~3.4e38£¬¾«¶È£º6~7Î»

double·¶Î§£º-1.7e308~1.7e308£¬¾«¶È£º15~16Î»

ldouble·¶Î§£º-1.2e4932~1.2e4932£¬¾«¶È£º18~19Î»

*/

#include <algorithm>

#include <bitset>

#include <cassert>

#include <cctype>

#include <cmath>

#include <complex>

#include <cstdio>

#include <cstdlib>

#include <cstring>

#include <ctime>

#include <deque>

#include <fstream>

#include <functional>

#include <iomanip>

#include <iostream>

#include <list>

#include <map>

#include <numeric>

#include <queue>

#include <set>

#include <sstream>

#include <stack>

#include <string>

#include <utility>

#include <vector>

#define LL long long

#define pb push_back

#define pob pop_back

#define mp make_pair

#define FILL(a,v) memset((void*)a,v,sizeof(a))

#define FILL0(a) FILL(a,0)

#define FILL1(a) FILL(a,-1)

#define ALL(a) (a).begin(),(a).end()

#define Inf 1e9

#define Mod 1000000007

#define foreach(it,x) for(typeof(x.begin()) it=x.begin();it!=x.end();it++)

#define FOR(i,x) for(int i=1;i<=x;i++)

#define RFOR(i,x) for(int i=x-1;i>=0;i--)

#define FFOR(i,a,b) for(int i=a;i<b;i++)

#define FRFOR(i,a,b) for(int i=a-1;i>=b;i--)

#define SZ(a) ((int)(a).size())

#define FI first

#define SE second

#define OVER(a) return puts(a),0

#define fastio ios::sync_with_stdio(0)

#define filei(a) freopen(a,"r",stdin)

#define fileo(a) freopen(a,"w",stdout)

using namespace std;

using namespace __gnu_cxx;

typedef pair<int,int> pii;

typedef unsigned long long UINT;

typedef unsigned int uint;

typedef long long INT;

typedef pair<INT,INT> PII;

typedef long double ldouble;



int n,k;

int a,b;

vector<int> neigh[2007];

int shp[2007][2007],removed[2007],rm=0;

set<int> ngood[2007];

bool lgl[2007];



void bfs(int c)

{

	memset(lgl,0,sizeof(lgl));

	queue<int> q,bs;

	q.push(c);

	bs.push(0);

	shp[c][c]=0;

	lgl[c]=1;

	while(q.size())

	{

		int Q=q.front(),B=bs.front();

		q.pop(),bs.pop();

		for(int i=0;i<neigh[Q].size();i++)

		{

			if(!lgl[neigh[Q][i]])

			{

				q.push(neigh[Q][i]);

				bs.push(B+1);

				lgl[neigh[Q][i]]=1;

				shp[c][neigh[Q][i]]=B+1;

			}

		}

	}

}



int main()

{

	scanf("%d%d",&n,&k);

	for(int i=0;i<n-1;i++)

	{

		scanf("%d%d",&a,&b);

		neigh[a].push_back(b);

		neigh[b].push_back(a);

	}

	for(int i=1;i<=n;i++)

		bfs(i);

	FOR(i,n)

		FOR(j,n)

			if(shp[i][j]>k)

				ngood[i].insert(j);

	while(1)

	{

		pii maxn=mp(0,0);

		FOR(i,n)if(!removed[i])

			maxn=max(maxn,mp(SZ(ngood[i]),i));

		if(maxn.first==0)break;

		removed[maxn.second]=1;

		FOR(i,n)if(!removed[i])

			ngood[i].erase(maxn.second);

		rm++;

	}

	printf("%d\n",rm);

	return 0;

}