#include<stdio.h>

#include<string.h>

char ch[205][11],str[11];

int s[205];

int main()

{

	int a,b,k=0;

	scanf("%d",&a);

	getchar();

	for(int i=0;i<a;i++)

	{

		scanf("%s",str);

		int flag=0;

		for(int j=0;j<k;j++)

		{

			if(strcmp(ch[j],str)==0)

			{

				flag=1;

				s[j]++;

				break;

			}

		}

		if(flag==0)

		{

			strcpy(ch[k],str);

			s[k]++;

			k++;

		}

	}

	scanf("%d",&b);

	getchar();

	for(int i=0;i<b;i++)

	{

		scanf("%s",str);

		int flag=0;

		for(int j=0;j<k;j++)

		{

			if(strcmp(ch[j],str)==0)

			{

				flag=1;

				s[j]--;

				break;

			}

		}

		if(flag==0)

		{

			strcpy(ch[k],str);

			s[k]--;

			k++;

		}

	}

	int max=0;

	for(int i=0;i<k;i++)if(s[i]>max)max=s[i];

	printf("%d\n",max);

}