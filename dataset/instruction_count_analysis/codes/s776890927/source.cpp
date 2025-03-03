#include<stdio.h>

using namespace std;

int p[10010];

int main()

{

    int n,m;

    scanf("%d%d",&n,&m);

    int s;

    scanf("%d",&s);

    int a;

    int statu=0;

    for(int i=1;i<=s;i++)

    {

        scanf("%d",&a);

        for(int j=0;j<a;j++,statu++)

            p[statu]=i;

    }

    for(int i=0;i<n;i++)

    {

        if(i%2==0)

        {

            for(int j=0;j<m-1;j++)

            printf("%d ",p[i*m+j]);

            printf("%d\n",p[(i+1)*m-1]);

        }

        else

        {

            for(int j=m-1;j>0;j--)

                printf("%d ",p[i*m+j]);

            printf("%d\n",p[i*m]);

        }

    }

    return 0;

}
