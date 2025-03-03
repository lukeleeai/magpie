#include <stdio.h>

#include <algorithm>

int s[10][10],v,e,t1,t2;

using namespace std;

main()

{

    scanf("%d %d",&v,&e);

    for(int i=0;i<e;i++)

    {

        scanf("%d %d",&t1,&t2);

        s[t1][t2]=1;

        s[t2][t1]=1;

    }

    int arr[v];

    for (int i=0;i<v;i++)

    {

        arr[i]=i+1;

    }

    bool p=true;

    int cnt=0;

    do

    {

        p=true;

        if(arr[0]!=1) break;

        for (int i=0;i<v-1;i++)

        {

            if(s[arr[i]][arr[i+1]]==1);

            else

            {

                p=false;

                break;

            }

        }

        if(p==true) cnt++;

    }while (next_permutation(arr,arr+v));

    printf("%d\n",cnt);

}
