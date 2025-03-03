#include"stdc++.h"

using namespace std;

const int N = 110;

int n,m,bel[N],a[N][N];

bool E[N][N],vis[N];

vector<int> vec[N][N];

bool find(int i)

{

	for(int j = 1;j <= n;j ++)

		if(!vis[j] && E[i][j])

		{

			vis[j] = 1;

			if(!bel[j] || find(bel[j]))

			{

				bel[j] = i;

				return 1;

			}

		}

	return 0;

}

void print()

{

	for(int i = 1;i <= n;i ++)

		for(int j = 1;j <= m;j ++)

			printf("%d%c",a[i][j],j == m?'\n':' ');

}

int main()

{

	scanf("%d%d",&n,&m);

	for(int i = 1;i <= n;i ++)

		for(int j = 1;j <= m;j ++)

		{

			int x;scanf("%d",&x);

			vec[i][(x-1)/m+1].push_back(x);

		}

	for(int i = 1;i <= m;i ++)

	{

		for(int j = 1;j <= n;j ++)

			for(int k = 1;k <= n;k ++)

				E[j][k] = (!vec[j][k].empty());

		memset(bel,0,sizeof(bel));

		for(int j = 1;j <= n;j ++)

			memset(vis,0,sizeof(vis)),find(j);

		for(int j = 1;j <= n;j ++)

		{

			int k = bel[j];

			a[k][i] = vec[k][j].back();

			vec[k][j].pop_back();

		}

	}

	print();

	for(int i = 1;i <= m;i ++)

		for(int j = 1;j <= n;j ++)

			for(int k = j+1;k <= n;k ++)

				if(a[j][i] > a[k][i])

					swap(a[j][i],a[k][i]);

	print();

	return 0;

}