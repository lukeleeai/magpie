#include<stdio.h>

#include<string.h>

char s[1000001];

int main()

{

    scanf("%s",s);

    int ans=0,x=0,y=0;

    for(int i=0;i<strlen(s);i++)

    {

        if(x==y)

        {

            x++;

            if(s[i]=='p')

            ans--;

        }

        else

        {

            y++;

            if(s[i]=='g')

            ans++;

        }

    }

    printf("%d",ans);

}