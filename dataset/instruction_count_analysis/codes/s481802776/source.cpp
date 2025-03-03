#include"stdc++.h"

using namespace std;

int n,m;

static bool mp[55][55],mp1[55][55];

bool is_cmp()

{

	for(int i=1;i<=n-m+1;i++)

		for(int j=1;j<=n-m+1;j++)//mp[i][j]

		{

			int flag=1;

			for(int h=1;h<=m;h++)

				for(int k=1;k<=m;k++)

				if(mp[i+h-1][j+k-1]!=mp1[h][k]) flag=0;

			if(flag) return true;

		}

	return false ;

}

int main()

{

	scanf("%d%d",&n,&m);

	getchar();

	for(int i=1;i<=n;i++)

	{

		for(int j=1;j<=n;j++)

		{

			char c;

			scanf("%c",&c);

			if(c=='#') mp[i][j]=1;

		}

		getchar();

	}

	for(int i=1;i<=m;i++)

	{

		for(int j=1;j<=m;j++)

		{

			char c;

			scanf("%c",&c);

			if(c=='#') mp1[i][j]=1;

		}

		getchar();

	}

	if(is_cmp()) printf("Yes");

	else printf("No");

}