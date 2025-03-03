#include<cstdio>

int n;

int a[100100];

int main()

{

	scanf("%d", &n);

	bool flag = false;

	for (int i = 1; i <= n; i++)

	{

		scanf("%d", &a[i]);

		if (a[i] & 1) flag = true;

	}

	if (flag) printf("first\n");

	else printf("second\n");

	return 0;

}
