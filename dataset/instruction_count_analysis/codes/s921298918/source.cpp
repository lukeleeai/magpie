#include <iostream>

#include <cstdio>

#include <algorithm>

using namespace std;

int main()

{

	int n;

	while(~scanf("%d",&n))

	{

		int a[500001];

		int flag,flag1,flag2;

		flag=flag1=flag2=0;

		for(int i=0;i<n;++i)

		{

			scanf("%d",&a[i]);

			if(a[i]%4 == 0)

				flag++;

			else if(a[i]%2 == 0)

				flag1++;

			else

				flag2++;

		}

		if(flag1)

			flag2++;

		if(flag2<=flag+1)

			printf("Yes\n");

		else

			printf("No\n");

	}

}