#include<cstdio>

#include<algorithm>

using namespace std;

int inp[100000];

int main()

{

	int n,ans=0;

	scanf("%d",&n);

	for(int i=0;i<n;i++) scanf("%d",&inp[i]);

	sort(inp,inp+n);

	for(int i=0,cnt;i<n;i++)

	{

		cnt=1;

		while(inp[i]==inp[i+1])

		{

			cnt++;

			i++;

		}

		if(inp[i]<=cnt) ans+=cnt-inp[i];

		else ans+=cnt;

	}

	printf("%d",ans);

	return 0;

}