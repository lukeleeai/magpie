#include <stdio.h>

#include <stdlib.h>



int main()

{

    int num;

    int t[100][10];

    scanf("%d",&num);

    int i;

    int p[100][11];

    for(i=0;i<num;i++)

    {

        scanf("%d %d %d %d %d %d %d %d %d %d ",&t[i][0],&t[i][1],&t[i][2],&t[i][3],&t[i][4],&t[i][5],&t[i][6],&t[i][7],&t[i][8],&t[i][9]);

    }

    for(i=0;i<num;i++)

    {

        scanf("%d %d %d %d %d %d %d %d %d %d %d",&p[i][0],&p[i][1],&p[i][2],&p[i][3],&p[i][4],&p[i][5],&p[i][6],&p[i][7],&p[i][8],&p[i][9],&p[i][10]);

    }

    int count,count1;

    int max,sum;

    int a[10];

    for(count1=1;count1<1024;count1++)

    {

        count=count1;

        int j;

        for(j=0;j<10;j++)

        {

            a[j]=count%2;

            count=count>>1;

        }

        int n;

        for(n=0;n<num;n++)

        {

            int m;

            int count2=0;

            for(m=0;m<10;m++)

            if((t[n][m]==1)&&(a[m]==1))

            {

                count2++;

            }

                if(n==0)

                    sum=p[n][count2];

                else

                    sum+=p[n][count2];

        }

        if(count1==1)

            max=sum;

        if(max<sum)

                max=sum;

    }

    printf("%d",max);



    return 0;

}