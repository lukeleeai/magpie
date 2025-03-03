#include<stdio.h>

int main()

{

    int n,amount[100000],total_amount,i;

    scanf("%d %d",&n,&total_amount);

    for(i = 0;i<n;i++)

    {

        scanf("%d",&amount[i]);

    }

    int sum = 0;

    for(i = 0;i<n;i++)

    {

        sum = sum+amount[i];

    }

    int left;

    left = total_amount - sum;

    int total_donut;

    int max_donut = 0;;

    int donut;

    for(i = 0;i<n;i++)

    {

        donut = left/amount[i];

        if(max_donut<donut)

            max_donut = donut;

    }

    total_donut = n+ max_donut;

    printf("%d\n",total_donut);

}
