#include<stdio.h>

#include<string.h>

    char s[105][105];

    int n,l,i,j;

    char a[105];

    int main()

    {

    while(~scanf("%d%d",&n,&l))

       {

       for(i=0;i<n;i++)

          scanf("%s",s[i]);

       for(i=0;i<n-1;i++)

          for(j=0;j<n-1-i;j++)

             if(strcmp(s[j],s[j+1])>0)

                {

                strcpy(a,s[j]);

                strcpy(s[j],s[j+1]);

                strcpy(s[j+1],a);

                }

       for(i=0;i<n;i++)

       printf("%s",s[i]);

       printf("\n");

    }

}