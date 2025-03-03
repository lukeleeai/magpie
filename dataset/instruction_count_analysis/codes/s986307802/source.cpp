#include<cstdio>

using namespace std;

int main()

{

    int n,t,x,y;

    scanf("%d",&n);

    for(int i=1;i<=n;i++)

    {

        scanf("%d%d%d",&t,&x,&y);

        if(x+y>t)

        {

            printf("No\n");

            return 0;

        }

        if((x+y)%2==0&&t%2==1)

        {

            printf("No\n");

            return 0;

        }

        if((x+y)%2==1&&t%2==0)

        {

            printf("No\n");

            return 0;

        }

    }

    printf("Yes\n");

    return 0;

}