#include <stdio.h>

#include <string.h>

#include <string.h>

char a[100005];

int b[100005] = { 0 };

int main()

{

	int len, count = 0, max = 0, i, j, flag,x,y;

	char b = 0;

	scanf("%s", a);

	len = strlen(a);

	for (i = 0; i < len; i++)

	{

		if (a[i] == 'R' && a[i + 1] == 'L')

		{

			j = i - 1;

			flag = 1;

			x = y = 1;

			while (j >= 0 && a[j] == 'R')

			{

				if (flag == 1)

					y++;

				else x++;

				flag = 1 - flag;

				j--;

			}

			flag = 1;

			j = i + 2;

			while (j < len && a[j] == 'L')

			{

				if (flag == 1)

					x++;

				else y++;

				flag = 1 - flag;

				j++;

			}

			printf("%d %d ", x, y);

			i++;

		}

		else printf("0 ");

	}

}