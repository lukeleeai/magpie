#include<cstdio>

using namespace std;

int main()

{

    int n,t,x,y;

    scanf("%d",&n);

    for(int i=1;i<=n;i++)

    {

        scanf("%d%d%d",&t,&x,&y);

        if(x+y>t)//不用绕，使出吃奶的劲儿都到不了

        {

            printf("No\n");

            return 0;

        }

        if((x+y)%2==0&&t%2==1)//如果最优路径与时间的积偶不一，一定到不了

        {

            printf("No\n");

            return 0;

        }

        if((x+y)%2==1&&t%2==0)//同理

        {

            printf("No\n");

            return 0;

        }

    }

    printf("Yes\n");//因为如果No就都return 0了，所以剩下一定是Yes。

    return 0;

}
