#include"stdc++.h"

using namespace std;

int n,m,cnt,a[100010];

long long now,ans=1e18;

vector<int> v[100010],g[100010];

void add(int x)

{

	cnt+=v[x].size();

}

void del(int x)

{

	for (int i=0;i<g[x].size();i++)

	{

		int y=g[x][i];

		cnt--;

		int d=x-y;

		if (d<0)

		{

			d+=m;

		}

		now+=d-1;

	}

}

int main()

{

	scanf("%d%d",&n,&m);

	for (int i=0;i<n;i++)

	{

		scanf("%d",&a[i]);

	}

	for (int i=0;i<n-1;i++)

	{

		v[a[i]].push_back(a[i+1]);

		g[a[i+1]].push_back(a[i]);

		if (a[i]>a[i+1])

		{

			cnt++;

			now+=a[i+1];

		}

		else

		{

			now+=a[i+1]-a[i];

		}

	}

	ans=now;

	for (int i=1;i<m;i++)

	{

		del(i);

		now-=cnt;

		ans=min(ans,now);

		//cout<<i+1<<" "<<cnt<<" "<<now<<endl;

		add(i);

	}

	cout<<ans<<endl;

	return 0;

}
