#include"stdc++.h"

using namespace std;

#define N 100005

set<int>s[N];

map<int,int>mat[N];

queue<pair<int,int> >q;

int n,x,y,ans,f[N];

int find(int k){

	if (k==f[k])return k;

	return f[k]=find(f[k]);

}

void add(int x,int y){

	s[x].insert(y);

	s[y].insert(x);

	if (x>y)swap(x,y);

	if (++mat[x][y]==2){

		q.push(make_pair(x,y));

		mat[x][y]=0;

	}

}

void merge(int x,int y){

	if (s[x].size()>s[y].size())swap(x,y);

	f[x]=y;

	for(set<int>::iterator it=s[x].begin();it!=s[x].end();it++){

		int z=find(*it);

		if (y==z)continue;

		add(y,z);

		s[z].erase(x);

	}

	s[x].clear();

}

int main(){

	scanf("%d",&n);

	for(int i=1;i<=n;i++)f[i]=i;

	for(int i=1;i<2*n-1;i++){

		scanf("%d%d",&x,&y);

		add(x,y);

	}

	while (!q.empty()){

		ans++;

		merge(find(q.front().first),find(q.front().second));

		q.pop();

	}

	if (ans==n-1)printf("YES");

	else printf("NO");

}