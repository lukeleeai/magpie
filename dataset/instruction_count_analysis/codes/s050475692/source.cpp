#include<cstdio>

using namespace std;

int n,sum[110];

int main(){

    scanf("%d",&n);

    if(n==1)

	{

        printf("1\n");

        return 0;

    }

    sum[1]=2;

    for(int i=2;i<=100;i++)

        sum[i]=sum[i-1]*2;

    for(int i=1;i<=100;i++)

	{

        if(n<sum[i+1]&&n>=sum[i])

		{

        	printf("%d\n",sum[i]);

            break;

        }

    }

    return 0;

}