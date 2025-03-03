#include<cstdio>

#include<algorithm>

#include<cstring>

using namespace std;

char a[200+5];

int n,t;

int ans=0;

int solve(int x)

{

	int tot=0;

	char s1[100+5]={},s2[100+5]={};

	int vis1[100+5]={},vis2[100+5]={};

	for(int i=0;i<=x;i++)

		s1[i]=a[i];

	for(int i=x+1;i<=n-1;i++)

		s2[i]=a[i];

	for(int i=0;i<=x;i++)

		if(!vis1[s1[i]-'a'])

			vis1[s1[i]-'a']=1;

	for(int i=x+1;i<=n-1;i++)

		if(vis1[s2[i]-'a']&&!vis2[s2[i]-'a'])

		{

			tot++;

			vis2[s2[i]-'a']=1;

		}

	return tot;

}

int main()

{

	scanf("%d",&n);

	scanf("%s",a);

	for(int i=0;i<=n-2;i++)

	{

		t=solve(i);

		ans=max(ans,t);

	}

	printf("%d\n",ans);

	return 0;

}
