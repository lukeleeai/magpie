#include<cstdio>

#include<cstring>

#include<algorithm>

int h,w;

int r[110],c[110];

char s[110][110];

int main()

{

    scanf("%d%d",&h,&w);

    for(int i=1;i<=h;i++)

    {

        scanf("%s",s[i]+1);

        for(int j=1;j<=w;j++)

        {

            if(s[i][j]=='.')

            {

                r[i]++;

                c[j]++;

            }

        }

    }

    for(int i=1;i<=h;i++)

    {

        if(r[i]==w) continue;

        for(int j=1;j<=w;j++)

        {

            if(c[j]==h) continue;

            printf("%c",s[i][j]);

        }

        printf("\n");

    }

}
