#include<cstdio>

#include<cctype>

#define SG getchar()

#define S return puts("No"),0

int n,m;

signed main()

{

	scanf("%d%d",&n,&m),SG;

	while(n--)

	{

		if(!isdigit(SG))

		{

			S;

		}

	}

	if(SG-45)

	{

		S;

	}

	while(m--)

	{

		if(!isdigit(SG))

		{

			S;

		}

	}

	return puts("Yes"),0;

}