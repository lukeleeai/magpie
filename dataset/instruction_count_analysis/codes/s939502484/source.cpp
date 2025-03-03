#include <cstdio>

#include <cmath>

#include <vector>

#include <queue>

#include <cstring>

using namespace std;

typedef long long ll;

char s[1000005];

struct hhh

{

	int from;

	char h;

	int to;

}arr[1000000];

int main()

{

	scanf("%s", s);

	int q;

	int flag = 0, cnt = 0, head, end;

	scanf("%d", &q);

	head = 0;

	if (strlen(s) == 1)

	{

		arr[0].h = s[0];

		arr[0].to = -1;

		arr[0].from = -1;

	}

	else

	for (int i = 0; i < strlen(s); i++)

	{

		if (i == strlen(s) - 1)

		{

			arr[cnt].from = cnt - 1;

			arr[cnt].h = s[i];

			arr[cnt].to = -1;

			break;

		}

		if (i == 0)

		{

			arr[cnt].from = -1;

			arr[cnt].h = s[i];

			arr[cnt++].to = i + 1;

			continue;

		}

		arr[cnt].from = cnt - 1;

		arr[cnt].h = s[i];

		arr[cnt++].to = i + 1;

	}

	end = cnt;

	while (q--)

	{

		int a;

		scanf("%d", &a);

		if (a == 1)

		{

			flag = (flag + 1) % 2;

		}

		else

		{

			int b;

			char c;

			scanf("%d %c", &b, &c);

			b = (b + flag) % 2;

			if (b == 1)

			{

				cnt++;

				arr[cnt].h = c;

				arr[cnt].to = head;

				arr[cnt].from = -1;

				arr[head].from = cnt;

				head = cnt;

			}

			else if(b == 0)

			{

				cnt++;

				arr[cnt].h = c;

				arr[cnt].to = -1;

				arr[cnt].from = end;

				arr[end].to = cnt;

				end = cnt;

			}

		}

	}

	if (flag == 0)

	{

		for (int i = head; i != -1; i = arr[i].to)

		{

			printf("%c", arr[i].h);

		}

	}

	else

	{

		for (int i = end; i != -1; i = arr[i].from)

		{

			printf("%c", arr[i].h);

		}

	}

	printf("\n");

}
