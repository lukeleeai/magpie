#include<cstdio>

#include<cstring>

char str[100050];

int main()

{

	while(~scanf("%s",str))

	{

		int ans = 0;

		char ch;

		int n = strlen(str);

		ch = str[0];

		for(int i = 0;i < n;i++)

		{

			if(str[i] != ch)

			{

				ans++;

				ch = str[i];

			}

		} 

		printf("%d\n",ans);

	}

}