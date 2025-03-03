#include "stdc++.h"

#include <ext/pb_ds/assoc_container.hpp>

#include <ext/pb_ds/tree_policy.hpp>

 

using namespace std;

using namespace __gnu_pbds;

 

#define fi first

#define se second

#define mp make_pair

#define pb push_back

#define fbo find_by_order

#define ook order_of_key

 

typedef long long ll;

typedef pair<int,int> ii;

typedef vector<int> vi;

typedef long double ld; 

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

typedef set<int>::iterator sit;

typedef map<int,int>::iterator mit;

typedef vector<int>::iterator vit;



vi R[111111];

vi B[111111];

int ans[111111];

vi adj[111111];



void add_pair(int x, int y)

{

	adj[x].pb(y); adj[y].pb(x);

}



void calcred(int u, int p)

{

	ans[u]=1;

	for(int i=0;i<R[u].size();i++)

	{

		int v=R[u][i];

		if(v==p) continue;

		calcred(v,u);

		ans[u]^=1;

	}

}



void calcblue(int u, int p)

{

	int cur=1;

	for(int i=0;i<B[u].size();i++)

	{

		int v=B[u][i];

		if(v==p) continue;

		calcblue(v,u);

		cur^=1;

	}

	if(cur!=ans[u])

	{

		cout<<"IMPOSSIBLE\n"; exit(0);

	}

}



int matchred(int u, int p)

{

	int cur=-1; if(ans[u]) cur=u;

	for(int i=0;i<R[u].size();i++)

	{

		int v=R[u][i];

		if(v==p) continue;

		int tmp=matchred(v,u);

		if(tmp!=-1)

		{

			if(cur==-1) cur=tmp;

			else

			{

				add_pair(cur,tmp); cur=-1;

			}

		}

	}

	return cur;

}



int matchblue(int u, int p)

{

	int cur=-1; if(ans[u]) cur=u;

	for(int i=0;i<B[u].size();i++)

	{

		int v=B[u][i];

		if(v==p) continue;

		int tmp=matchblue(v,u);

		if(tmp!=-1)

		{

			if(cur==-1) cur=tmp;

			else

			{

				add_pair(cur,tmp); cur=-1;

			}

		}

	}

	return cur;

}



bool vis[111111];

void coloring(int u, int col)

{

	vis[u]=1; ans[u]=col;

	for(int i=0;i<adj[u].size();i++)

	{

		int v=adj[u][i];

		if(!vis[v])

		{

			coloring(v,col*-1);

		}

	}

}



int main()

{

	ios_base::sync_with_stdio(0); cin.tie(0);

	int n; cin>>n;

	int rt1=0; int rt2=0;

	for(int i=0;i<n;i++)

	{

		int p; cin>>p;

		if(p==-1) rt1=i;

		else

		{

			p--; R[p].pb(i);

		}

	}

	for(int i=0;i<n;i++)

	{

		int p; cin>>p;

		if(p==-1) rt2=i;

		else

		{

			p--; B[p].pb(i);

		}

	}

	calcred(rt1,-1); calcblue(rt2,-1);

	matchred(rt1,-1); matchblue(rt2,-1);

	for(int i=0;i<n;i++) {if(!vis[i]&&ans[i]!=0) coloring(i,1);}

	cout<<"POSSIBLE\n";

	for(int i=0;i<n;i++) cout<<ans[i]<<(i<n-1?' ':'\n');

}
