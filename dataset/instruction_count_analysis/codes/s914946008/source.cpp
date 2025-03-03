#include<cstdio>

using namespace std;

int n,ans[30005],lst,cnt;

bool ok=0;

int main()

{

	scanf("%d",&n);

	if(n==3){printf("2 5 63");return 0;}

	for(int i=2;i<=30000&&n>0;i+=2)

	{

		lst+=i;

		n--;

		ans[++cnt]=i;

		if(n%2==0&&lst%3==0&&n<=5000)

		{

			for(int j=3;n>0&&j<=30000;j+=6) ans[++cnt]=j,n--;

			ok=1;

			break;

		}

		if(ok) break;

	}

	printf("2");

	for(int i=2;i<=cnt;i++) printf(" %d",ans[i]);

	return 0;

}