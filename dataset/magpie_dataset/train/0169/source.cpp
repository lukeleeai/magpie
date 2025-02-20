//Bokan ga bokka--nn!!

//Daily Lunch Special Tanoshii !!

//これは、頭が悪く競プロが世界で一番できないHIR180が

//IOI2014日本代表になるまでのN日間の記録である。

#include <cstdio>

#include <cstring>

#include <cstdlib>

#include <cmath>

#include <ctime>

#include <cassert>

#include <string>

#include <algorithm>

#include <vector>

#include <queue>

#include <stack>

#include <functional>

#include <iostream>

#include <map>

#include <set>

using namespace std;

typedef pair<int,int> P;

typedef pair<int,P> P1;

typedef pair<P,P> P2;

typedef long long ll;

#define pu push

#define pb push_back

#define mp make_pair

#define eps 1e-7

#define INF 2000000000

#define f first

#define s second

#define rep(i,x) for(int i=0;i<x;i++)

P za[100005];

int main()

{

	srand((unsigned int)time(NULL));

	int n,x,y;  scanf("%d",&n);

	int lx=INF,ly=INF,rx=-INF,ry=-INF;

	for(int i=0;i<n;i++)

	{

		scanf("%d%d",&x,&y);

		za[i]=mp(x+y,x-y);

		lx=min(lx,x+y);

		rx=max(rx,x+y);

		ly=min(ly,x-y);

		ry=max(ry,x-y);

	}

	int ret1=0,ret2=0;

	for(int i=0;i<n;i++)

	{

		//(lx,ly)(rx,ry)

		ret1=max(ret1,min(max(za[i].f-lx,za[i].s-ly),max(rx-za[i].f,ry-za[i].s)));

		//(lx,ry)(rx,ly)

		ret2=max(ret2,min(max(za[i].f-lx,ry-za[i].s),max(rx-za[i].f,za[i].s-ly)));

	}

	printf("%d\n",min(ret1,ret2));

}