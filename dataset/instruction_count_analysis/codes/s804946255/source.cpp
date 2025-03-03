#include "stdc++.h"

using namespace std;

#define maxn 100010

int q[maxn],top=0;

int Max=0,cnt=0;

int n,a[maxn];

int main()

{

    int t,T;

    t=1;

    while (t--)

    {

        scanf("%d %d",&n,&T);

        for (int i=0;i<n;i++) scanf("%d",&a[i]);

        q[0]=a[0],top=0;

        Max=-1;

        for (int i=1;i<n;i++)

        {

            if (a[i]>q[top]) q[++top]=a[i];

            else if (a[i]<q[top])

            {

                if (q[top]-q[0]>Max) Max=q[top]-q[0],cnt=1;

                else if (q[top]-q[0]==Max) cnt++;

                while (top>=0&&a[i]<q[top]) top--;

                q[++top]=a[i];

            }

        }

        if (q[top]-q[0]>Max) Max=q[top]-q[0],cnt=1;

        else if (q[top]-q[0]==Max) cnt++;

        printf("%d\n",cnt);

    }

    return 0;

}
