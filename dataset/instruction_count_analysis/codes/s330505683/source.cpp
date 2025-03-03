#include<stdio.h>

int s[100005][5];

int main()

{

    int n,first=0;

    scanf("%d",&n);

    for(int i = 1;i <= n;i++)

        for(int j = 1;j <= 3;j++)

        scanf("%d",&s[i][j]);

    for(int i = 1;i <= n;i++)

    {

        int a,b;

        a = (s[i][2]+s[i][3])-(s[i-1][2]+s[i-1][3]);

        if(a<0) a=-a;

        b = s[i][1]-s[i-1][1];

        if(a>b||(a-b)%2||a==0&&(b-4)%2)  {first = 1;break;}

    }

    if(first)  printf("No");

    else printf("Yes");

    return 0;

}

   
