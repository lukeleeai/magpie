#include<stdio.h>

#include<string.h>





int main()

{

	char s[100005];

	int a[100005] = {0}, i=0, bsr,bsl, len;

	scanf("%s", s);

	len = strlen(s);

	while (i < len-1)

	{

		for (bsr=0; (bsr+i) < len-1; bsr++)/*寻找RL字符串*/

		{

			if ((s[i + bsr] == 'R') && (s[i + bsr + 1] == 'L'))

			{

				if (bsr % 2 == 0)

				{

					a[i + bsr] += (bsr / 2 + 1); a[i + bsr + 1] += bsr / 2;

				}

				else

				{

					a[i + bsr] += ((bsr + 1) / 2); a[i + bsr + 1] += ((bsr + 1) / 2);

				}

				for (bsl = 1; (i + bsr + bsl) < len; bsl++)

				{

					if (s[i + bsr + bsl] == 'R')

					{

						bsl--;

						break;

					}

					if ((i + bsr + bsl) == (len - 1))

						break;

				}

				if (bsl % 2 == 1)

				{

					a[i + bsr] += bsl / 2; a[i + bsr + 1] += (bsl / 2 + 1);

				}

				else

				{

					a[i + bsr] += bsl / 2; a[i + bsr + 1] += bsl / 2;

				}

				i = i + bsr + bsl + 1;

				break;

			}

		}

	}

	for (i = 0; i < len-1; i++)

		printf("%d ", a[i]);

	printf("%d\n", a[i]);

}