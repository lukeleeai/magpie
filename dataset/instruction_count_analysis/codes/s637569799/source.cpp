#include<stdio.h>

int main()

{

    int i,n,p=0,w=0,g=0,y=0;

    scanf("%d",&n);

    char Arr[n];

    for(i=0; i<n; i++)

    {

        scanf("%s",&Arr[i]);

        if(Arr[i]=='P')

        {

            p++;

        }

        if(Arr[i]=='W')

        {

            w++;

        }

        if(Arr[i]=='G')

        {

            g++;

        }

        if(Arr[i]=='Y')

        {

            y++;

        }

    }

    if(p&&w&&g&&y)

    {

        printf("Four\n");

    }

    else

    {

        printf("Three\n");

    }

}
