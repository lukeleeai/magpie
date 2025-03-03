#include<cstdio>

using namespace std;

int n;

int main()

{

	scanf("%d",&n);

	if(n<3){printf("No\n");return 0;}

	if(n&1)

	{

		printf("Yes\n");

		printf("%d %d\n",1,2);printf("%d %d\n",2,3);printf("%d %d\n",3,n+1);printf("%d %d\n",n+1,n+2);printf("%d %d\n",n+2,n+3);

		for(int i=4;i<=n;i+=2)printf("%d %d\n",i,i+1),printf("%d %d\n",i+n,i+n+1),printf("%d %d\n",i,1),printf("%d %d\n",i+n+1,1);

	}

	else

	{

		for(int i=1;i<n;i++)

		if((n^i^1)<n)

		{

			int st=n^i^1;

			printf("Yes\n");

			printf("%d %d\n",1,2);printf("%d %d\n",2,3);printf("%d %d\n",3,n+1);printf("%d %d\n",n+1,n+2);printf("%d %d\n",n+2,n+3);

			for(int j=4;j<n;j+=2)printf("%d %d\n",j,j+1),printf("%d %d\n",j+n,j+n+1),printf("%d %d\n",j,1),printf("%d %d\n",j+n+1,1);

			printf("%d %d\n",n,(i&1)?i+n:i);printf("%d %d\n",n*2,(st&1)?st+n:st);

			return 0;

		}

		printf("No\n");

	}

}
