#include<stdio.h>

int min(int a,int b)

{

	if(a<b)

		return a;

	else

		return b;

}

int main()

{

	int n,t,i,pos,old,ans=0;

	scanf("%d%d",&n,&t);

	int min_pic=0x3f3f3f3f,max_value=0;

	for(i=0;i<n;i++)

	{

		scanf("%d",&pos);

		if(i==0)

		{

			min_pic=pos;

			old=pos;

		}

		else

		{

			if(pos>old)

			{

				if(pos-min_pic>max_value)

				{

					max_value=pos-min_pic;

					ans=1;

				}

				else if(pos-min_pic==max_value)

					ans++;

			}

			else

				old=pos;

			if(min_pic>pos)

				min_pic=pos;

		}

	}

	printf("%d\n",ans);

}