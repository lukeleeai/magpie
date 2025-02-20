//Bokan ga bokka--nn!!

//Daily Lunch Special Tanoshii !!

#include <cstdio>

#include <cstring>

#include <cstdlib>

#include <cmath>

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

#define s(x) scanf("%d",&x)

#define rep(i,x) for(int i=0;i<x;i++)

int rui[1005][1005][3]={};

char f[1005][1005];

int n,m,q;

int main()

{

	scanf("%d %d %d",&n,&m,&q);

	for(int i=0;i<n;i++)

	{

		scanf("%s",f[i]);

	}

	for(int i=1;i<=n;i++)

	{

		for(int j=1;j<=m;j++)

		{

			rui[i][j][0]=rui[i-1][j][0]+rui[i][j-1][0]-rui[i-1][j-1][0]+(f[i-1][j-1]=='J');

			rui[i][j][1]=rui[i-1][j][1]+rui[i][j-1][1]-rui[i-1][j-1][1]+(f[i-1][j-1]=='O');

			rui[i][j][2]=rui[i-1][j][2]+rui[i][j-1][2]-rui[i-1][j-1][2]+(f[i-1][j-1]=='I');

			

		}

	}

	for(int aa=0;aa<q;aa++)

	{

		int x,y,z,w;

		scanf("%d %d %d %d",&x,&y,&z,&w);

		int r[3];

		for(int i=0;i<3;i++) r[i]=rui[z][w][i]-rui[z][y-1][i]-rui[x-1][w][i]+rui[x-1][y-1][i];

		printf("%d %d %d\n",r[0],r[1],r[2]);

	}

}