#include<stdio.h>

#include<string.h>

int main()

{

    int j,n,flag,count;

    char w[100]={0},i;

    scanf("%s",w);

    flag=0;

    n=strlen(w);

    for(i=97;i<='z';i++)

    {

        count=0;

        for(j=0;j<n;j++)

            if(w[j]==i)

                count++;

        if(count%2!=0)

        {

            flag=1;

            break;

        }

    }

        if(flag==1)

        printf("No\n");

        else

    printf("Yes\n");

    return 0;

}
