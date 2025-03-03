#include<cstdio>

int main()

{

	int n,m;

	while(~scanf("%d%d",&n,&m))

	{

		

		int ans=n/(2*m+1);

		if(n%(2*m+1)!=0)

		ans++;

		printf("%d\n",ans);

	}

}