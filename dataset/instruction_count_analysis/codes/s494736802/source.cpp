#include "stdc++.h"

using namespace std;

#define MAX 300000

vector<int>g[MAX];

int dfs(int u,int p){

    int l=0;

    for(int v:g[u]){

        if(v!=p){

         l^=1+dfs(v,u);   

        }

    }

    return l;

}

int main() {

	int n,u,v;

	cin>>n;

	for(int i=0;i<n-1;i++){

	    cin>>u>>v;

	    g[u].push_back(v);

	    g[v].push_back(u);

	}

	cout<<(dfs(1,0)?"Alice":"Bob");

	return 0;

}