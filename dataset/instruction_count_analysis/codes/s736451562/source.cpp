#include<cstdio>

#include<cstring>

#include<algorithm>

using namespace std;



int main()

{

	int a,b,x,y;

	while(~scanf("%d%d%d%d",&a,&b,&x,&y))

	{

		int n = x-a,m = y-b;

		for(int i = 0;i < m;i++)

			printf("U");

		for(int i = 0;i < n;i++)

			printf("R");

		for(int i = 0;i < m;i++)

			printf("D");

		for(int i = 0;i < n+1;i++)

			printf("L");

		for(int i = 0;i < m+1;i++)

			printf("U");

		for(int i = 0;i < n+1;i++)

			printf("R");

			printf("D");	

			printf("R");

		for(int i = 0;i < m+1;i++)

			printf("D");

		for(int i = 0;i < n+1;i++)

			printf("L");

		printf("U\n");

	}

return 0;

}