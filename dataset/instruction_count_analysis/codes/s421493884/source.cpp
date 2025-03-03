#include"stdc++.h"

using namespace std;

#define MAX 300000

#define int long long

struct Pair{

	int x,y, id;

};

int n;

Pair a[MAX+1];

typedef Pair PP;

typedef pair<int,int> pp;

vector<pair<int,int> > G[MAX+1];

bool cmp(PP a,PP b){return a.x<b.x;};

bool CMP(PP a,PP b){return a.y<b.y;};

bool visited[MAX+1];

int ans;

#define fi first

#define se second

void DJK(int x){

	ans = 0;

	priority_queue<pp,vector<pp> ,greater<pp> >pq;

	pq.push({0,x});

	while(!pq.empty()){

		int u = pq.top().se;

		int w = pq.top().fi;

		pq.pop();

		if(visited[u]) continue;

		ans+=w;

		visited[u] = 1;

		for(pp ii : G[u]){

			int v = ii.se;

			pq.push({ii.fi,v});

		}

	}

}

signed main(){

	cin >> n;

	for(int i=1;i<=n;i++){

		cin >> a[i].x >> a[i].y;

		a[i].id = i;

	}

	sort(a+1,a+n+1,cmp);

	for(int i=2;i<=n;i++){

		G[a[i].id].push_back({a[i].x-a[i-1].x,a[i-1].id});

		G[a[i-1].id].push_back({a[i].x-a[i-1].x,a[i].id});

	}

	sort(a+1,a+n+1,CMP);

	for(int i=2;i<=n;i++){

		G[a[i].id].push_back({a[i].y-a[i-1].y,a[i-1].id});

		G[a[i-1].id].push_back({a[i].y-a[i-1].y,a[i].id});

	}

	DJK(1);

	cout << ans;

}