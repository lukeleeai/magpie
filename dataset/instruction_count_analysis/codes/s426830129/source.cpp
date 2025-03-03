#include<iostream>

#include<cstdio>

#include<algorithm>

#include<cmath>

#include<string.h>

using namespace std;

int main()

{

	int n,k=0;

	int ans=0,flag=0;

	int t=1;

	int a[100005],vis[100005];

	scanf("%d",&n);

	memset(vis,1,sizeof(vis));

	for(int i=0;i<n;i++)

	{

		scanf("%d",&a[i]);

	}

	sort(a,a+n);

	for(int i=0;i<n;i++)

	{

		if(a[i]==a[i+1])

		{

			vis[k]++;

		}

		else

		{

			k++;

		}

	}

	for(int i=0;i<k;i++)

	{

		if(vis[i]&1)

		{

			ans++;

		 } 

	}

	 printf("%d\n",ans);

	

	 return 0;

 } 