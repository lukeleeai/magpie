#include <cstdio>

#include <cstring>

#include <algorithm>

using namespace std;



int main()

{

    // freopen("a.in","r",stdin);

    // freopen("k.out","w",stdout);

    int n,k;

    scanf("%d %d",&n,&k);

    int ans = (n-1)*(n-2)/2;

    if(ans < k)

    {

        printf("-1");

    }

    else

    {

        printf("%d\n",n-1 + ans - k );

        for(int i=2;i<=n;i++)

            printf("%d %d\n",1,i);



        for(int i=2;i<=n;i++)

            for(int j=i+1;j<=n;j++)

            {

                if(ans == k) return 0;

                printf("%d %d\n",i,j);

                ans--;

                

            }

    }

    return 0;

}