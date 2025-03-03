#include<cstdio>

int x,y;

int main()

{

    scanf("%d%d",&x,&y);

    if(x%y)printf("%d",x);

    else printf("-1");

}