#include<math.h>

#include<string.h>

#include<stdio.h>

#include<stdlib.h>

#include<string.h>

#include<algorithm>

#include<string>

#include<queue>

#include<vector>

#include<stack>

#include<set>

#include<map>

using namespace std;



int ser[1000010];

int main()

{

	int c1, c2, c4;

	int n,temp;

	c1 = c2 = c4 = 0;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)

	{

		scanf("%d", &temp);

		if (temp % 4 == 0)

			c4++;

		else if (temp % 2 == 0)

			c2++;

		else

			c1++;

	}

	if (c2 != 0)

	{

		if (c1 <= c4)

			printf("Yes\n");

		else

			printf("No\n");

	}

	else

	{

		if(c1<=c4+1)

			printf("Yes\n");

		else

			printf("No\n");

	}

 	return 0;

}
