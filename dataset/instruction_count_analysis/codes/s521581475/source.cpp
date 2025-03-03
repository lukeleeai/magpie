#include"stdc++.h"

#define Ll long long

using namespace std;

const int N=2e5+5;

vector<int>h[N];

int n,m,x,y;

void dfs(int x,int y){

	if(y>2)return;

	if(x==n){cout<<"POSSIBLE";exit(0);}

	for(int k=0;k<h[x].size();k++)

		dfs(h[x][k],y+1);

}

int main()

{

	scanf("%d%d",&n,&m);

	for(int i=1;i<=m;i++){

		scanf("%d%d",&x,&y);

		h[x].push_back(y);

	}

	dfs(1,0);

	cout<<"IMPOSSIBLE"; 

}