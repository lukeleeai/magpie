#include "stdc++.h"

using namespace std;

int n,m;

int num[100005];

int yu[100005];

int temp;

int ans;

int main()

{

    scanf("%d %d",&n,&m);

    for(int i=0;i<n;i++)

    {

        scanf("%d",&temp);

        num[temp]++;

        yu[temp%m]++;

    }

    if(yu[0]>=2)

    {

        int minn=yu[0]/2;

        yu[0]-=minn*2;

        ans+=minn;

    }

    for(int i=1;i<m;i++)

    {

        if(yu[i]>0 && yu[m-i]>0)

        {

            if(i!=m-i)

            {int minn=min(yu[i],yu[m-i]);

            yu[i]-=minn;

            yu[m-i]-=minn;

            ans+=minn;}

            else

            {

                int minn=yu[i]/2;

                yu[i]-=minn*2;

                ans+=minn;

            }

        }

    }

    for(int i=1;i<=100000;i++)

    {

        if(num[i]>=2 && yu[i%m]>=2)

        {

            int minn=min(num[i]/2,yu[i%m]/2);

            yu[i%m]-=2*minn;

            ans+=minn;

            //cout<<i<<endl;

        }

    }

    printf("%d\n",ans);

}
