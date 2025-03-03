#include <stdio.h>

#include <string.h>



bool from[200005];

bool to[200005];



int main()

{

    int n,m;



    scanf("%d%d",&n,&m);



    for (int i = 0;i < m;i++)

    {

        int a,b;



        scanf("%d%d",&a,&b);



        if (a == 1) from[b] = 1;

        if (b == n) to[a] = 1;

    }



    bool ans = 0;



    for (int i = 2;i < n;i++)

    {

        if (from[i] && to[i])

        {

            ans = 1;

            break;

        }

    }



    if (ans) printf("POSSIBLE\n");

    else printf("IMPOSSIBLE\n");



    return 0;

}
