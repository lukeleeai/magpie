#include <cstdio>

using namespace std;

int main()

{

    int k,sum=0;

    scanf("%d",&k);

    for(int i=2;i<=k;i++)

    {

        if(!(i&1))

        {

            for(int j=1;j<=k;j++)

            if(j&1)

            sum++;

        }

    }

    printf("%d\n",sum);

}
