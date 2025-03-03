#include<cstdio>

#include<cstring>

using namespace std;

#define MAXN 1000005

char s[MAXN];

int main()

{

	scanf("%s",s);

	int len=strlen(s);

	for(int i=0;i<=len-1;i++)

	{

		if(s[i]==s[i+1])

		{

			printf("%d %d\n",i+1,i+2);

			return 0;

		}

		if(s[i]==s[i+2])

		{

			printf("%d %d\n",i+1,i+3);

			return 0;

		}

	}

	printf("-1 -1\n");

	return 0;

}