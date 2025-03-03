#include<stdio.h>

#include<string.h>

int max(int x,int y)

{

    return x>y ? x:y;

}

int min(int x,int y)

{

    return x<y ? x:y;

}

int main()

{

    char ch[100010];

    while(scanf("%s",ch)!=EOF)

    {

        int len=strlen(ch);

        int ans=len;

        for(int i=1;i<=len-1;i++)

        {

            if(ch[i]!=ch[i-1])

                ans=min(ans,max(i,len-i));

        }

        printf("%d\n",ans);

    }

    return 0;

}
