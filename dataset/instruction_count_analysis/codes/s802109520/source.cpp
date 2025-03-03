#include"stdc++.h"

using namespace std;

const int N=100005;

pair<int,int>p[N];

int n,m,a[N],vis[N];

vector<pair<int,int>>e[N];

vector<int>ans;

inline int dfs(int x)

{

	vis[x]=1;

	int rt=a[x];

	for(auto v:e[x])

	{

		int y=v.first;

		if(vis[y])

			continue;

		int t=dfs(y);

		if(t)

			ans.push_back(v.second);

		rt^=t;

	}

	return rt;

}

int main()

{

	ios_base::sync_with_stdio(false);

	cin>>n>>m;

	for(int i=0;i<n;i++)

		cin>>p[i].first>>p[i].second;

	sort(p,p+n);

	a[0]=p[0].second;

	for(int i=1;i<n;++i)

		a[i]=p[i-1].second^p[i].second;

	a[n]=p[n-1].second;

	for(int i=0,l,r;i<m;i++)

	{

		cin>>l>>r;

		l=lower_bound(p,p+n,make_pair(l,0))-p;

		r=upper_bound(p,p+n,make_pair(r,1))-p;

		e[l].push_back({r,i+1});

		e[r].push_back({l,i+1});

	}

	for(int i=0;i<=n;i++)

	{

		if(!vis[i])

		{

			if(dfs(i))

			{

				cout<<"-1\n";

				return 0;

			}

		}

	}

	cout<<ans.size()<<endl;

	sort(ans.begin(),ans.end());

	for(int i:ans)

		cout<<i<<' ';

	return 0;

}
