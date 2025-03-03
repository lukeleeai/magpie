#include<cstdio>

#include<cstring>

using namespace std;

char a[4];

int num[180];

int main()

{

	int pd=0;

	scanf("%s",&a);

	for(int i=0;i<4;i++)

	{

		num[a[i]]++;

	}

	for(int i=0;i<180;i++)

	{

		if(num[i]%2!=0)

		pd=1;

		if(num[i]>2)

		pd=1;

	}

	if(pd==1)

	printf("No");

	else

	printf("Yes");

} 