#include<stdio.h>

#include<string.h>

#include<stdlib.h>

int main()

{

    int n,b,i,j;

    scanf("%d%d",&n,&b);

    char s[n+1][b+1];

    for(i=0; i<n; i++)

    {

        scanf("%s",s[i]);

    }

    for(i=0; i<n; i++)

    {

        for(j=i+1; j<n; j++)

        {

            if(strcmp(s[i],s[j])>0)

            {

                char tem[b+1];

                strcpy(tem,s[i]);

                strcpy(s[i],s[j]);

                strcpy(s[j],tem);

            }

        }

    }

    for(i=0; i<n; i++)

    {

        printf("%s",s[i]);

    }

    printf( "\n" ) ;

}
