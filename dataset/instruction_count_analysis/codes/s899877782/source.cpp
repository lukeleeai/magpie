#include "stdc++.h"

 

typedef long long ll;

 

using namespace std;

 

vector<int> par;

 

int find(int n){

	if(par[n]==n)return n;

	else return par[n]=find(par[n]);

}

 

void uni(int a,int b){

	a=find(a);

	b=find(b);

	if(a!=b)par[b]=a;

}

 

int main(){

	//freopen("input.in","r",stdin);

	//freopen("output.in","w",stdout);

	ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    cout.tie(NULL);

    int i,j,n,m,a,b;

    cin>>n>>m;

    par=vector<int>(n+1);

    for(i=1;i<=n;i++)par[i]=i;

    while(m--){

    	cin>>a>>b;

    	uni(a,b);

    }

    set<int> s;

    for(i=1;i<=n;i++)s.insert(find(i));

    cout<<s.size()-1;

 

 

	return 0;

}