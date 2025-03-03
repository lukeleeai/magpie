#include<cstdio>

using namespace std;



int n,k,x;

bool arr[10];



bool check(int n)

{

    while(n)

    {

        if(arr[n%10])

            return 0;

        n /= 10;

    }

    return 1;

}



int main()

{

    while(scanf("%d%d",&n,&k)!=EOF)

    {

        for(int i=0;i<k;i++)

        {

            scanf("%d",&x);

            arr[x] = 1;

        }

        for(int i=n;;i++)

        {

            if(check(i))

            {

                printf("%d\n",i);

                break;

            }

        }

    }

return 0;

}