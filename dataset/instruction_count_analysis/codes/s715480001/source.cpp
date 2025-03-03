#include <iostream>

#include <stdio.h>

#include <math.h>

#include <string.h>

#include <time.h>

#include <stdlib.h>

#include <string>

#include <bitset>

#include <vector>

#include <set>

#include <map>

#include <queue>

#include <algorithm>

#include <sstream>

#include <stack>

#include <iomanip>

using namespace std;

#define pb push_back

#define mp make_pair

typedef pair<int,int> pii;

typedef long long ll;

typedef double ld;

typedef vector<int> vi;

#define fi first

#define se second

#define fe first

#define FO(x) {freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);}

#define Edg int M=0,fst[SZ],vb[SZ],nxt[SZ];void ad_de(int a,int b){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;}void adde(int a,int b){ad_de(a,b);ad_de(b,a);}

#define Edgc int M=0,fst[SZ],vb[SZ],nxt[SZ],vc[SZ];void ad_de(int a,int b,int c){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;vc[M]=c;}void adde(int a,int b,int c){ad_de(a,b,c);ad_de(b,a,c);}

#define es(x,e) (int e=fst[x];e;e=nxt[e])

#define VIZ {printf("digraph G{\n"); for(int i=1;i<=n;i++) for es(i,e) printf("%d->%d;\n",i,vb[e]); puts("}");}

#ifdef LOCAL

#define TIMER cerr<<clock()<<"ms\n"

#else

#define TIMER

#endif

#define SZ 666666

int n,e,t,x[SZ];

ll dp[SZ],qzm[SZ];

int main()

{

	scanf("%d%d%d",&n,&e,&t);

	for(int i=1;i<=n;i++) scanf("%d",x+i);

	memset(dp,127/3,sizeof(dp)); dp[0]=0;

	memset(qzm,127/3,sizeof(qzm));

	int p=0; qzm[0]=dp[0]-2*x[1];

	for(int i=1;i<=n;i++)

	{

		while((x[i]-x[p+1])*2>t&&p<i) ++p;

		//for j>=p: (x[i]-x[j+1])*2<=t

		if(p<i) dp[i]=dp[p]+t;

		if(p) dp[i]=min(dp[i],qzm[p-1]+2*x[i]);

		qzm[i]=min(qzm[i-1],dp[i]-2*x[i+1]);

	}

	cout<<dp[n]+e<<"\n";

}
