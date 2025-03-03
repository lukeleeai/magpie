#include<stdio.h>

#include<iostream>

#include<algorithm>

#include<cstring>

using namespace std;

struct robot

{

	int x,y; 

}r[200005];

int left1[200005];

int right1[200005];

int res[200005];

int cmp(struct robot a,struct robot b)

{

	return a.x<b.x;

}

int main(void)

{

	int n;

	int m;

	while(~scanf("%d %d",&n,&m))

	{

		for(int i=0;i<=n;i++)

		{

			left1[i]=right1[i]=i;

		}

		memset(res,0,sizeof(res));

		for(int i=1;i<=m;i++)

		{

			scanf("%d %d",&r[i].x,&r[i].y);

		}

		sort(r+1,r+m+1,cmp);

		for(int i=1;i<=m;i++)

		{

			int xx=r[i].y;

			left1[xx]=left1[xx+1]=min(left1[xx],left1[xx+1]);

			right1[xx]=right1[xx+1]=max(right1[xx],right1[xx+1]);

		}

		cout<<right1[1]-left1[1]+1;

		for(int i=2;i<=n;i++)

		{

			cout<<" "<<right1[i]-left1[i]+1;

		}

		cout<<endl;

		

		

	}

}