#include<stdio.h>

double cal(long long x)

{

    long long sum=0,temp=x;

    while(x)

	{

        sum+=x%10;

        x/=10;

    }

    return (double)temp/sum;

}

int main()

{

	long long num=0,bot=1,temp1,temp2;

    int k;

    scanf("%d",&k);

    while(1)

	{

        while(1)

		{

			temp1=num+bot;

			temp2=num+bot*10;

			if(cal(temp1)<=cal(temp2))break;

            else bot=temp2-num;

        }

        num+=bot;

        printf("%lld\n",num);

        k--;

        if(!k)break;

    }

}