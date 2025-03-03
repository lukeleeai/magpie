#include <algorithm>

#include <cstdio>

#include <iostream>

#include <cfloat>

#include <climits>

#include <cstdlib>

#include <cstring>

#include <cmath>

#include <queue>

#include <sstream>

#include <stack>

#include <time.h>

#include <vector>

#include <complex>

#include <map>

#include <set>

#include <iomanip>

#include <math.h>

#include <stdlib.h>

#include <list>

#include <utility>

#include <memory>

#include <cstring>

#include <fstream>

#include <numeric>

#include <assert.h>

#include "stdc++.h"

using namespace std;

#define f first

#define s second 

const int INF=1<<29;

typedef pair<int,int> pii;

int N,M;

int a[200004];

bool vis[200004];

vector <pii> g[200004];

int maxn,minn;

void dfs(int x){

	minn=min(a[x],minn);

	maxn=max(a[x],maxn);

	for (int i=0;i<g[x].size();i++){

		int n=g[x][i].f;

		if (vis[n]){

			if (a[n]!=a[x]+g[x][i].s){

				puts("No");

				exit(0);

			}

		}

		else{

			vis[n]=1;

			a[n]=a[x]+g[x][i].s;

			dfs(n);

		}

	}

}

int main(){

	cin>>N>>M;

	for (int i=0;i<M;i++){

		int x,y,d;

		cin>>x>>y>>d;

		g[x].push_back(pii(y,d));

		g[y].push_back(pii(x,-d));  

	}

	for (int i=1;i<=N;i++){

		if (vis[i]) continue;

		maxn=-INF,minn=INF;

		vis[i]=1;

		a[i]=0;

		dfs(i);

		if (maxn-minn<=1e9);

		else{

			puts("No");

			return 0;

		}

	}

	puts("Yes");

	return 0;

}