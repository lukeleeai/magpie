#include <cstdio>

#include <iostream>

#include <cstring>

#include <queue>

#include <cctype>

#include <algorithm>

#include <cmath>

#include <map>

#include <string>

#include <vector>



using namespace std;

typedef long long ll;



int a[200005],d[200005],ans[200005],f[200005];

int main()

{

    int n,i;

    scanf("%d",&n);

    for(i=1;i<=n;i++)

    {

        scanf("%d",&a[i]);

        d[a[i]]=i;

    }

    for(i=n-1;i>=1;i--)

    {

        if(ans[i+1]==0)

        {

            if(d[i]>d[i+1])

            {

                ans[i]=1;

                f[i]=i+1;

            }

        }

        else

        {

            int aa=d[i],bb=d[i+1],cc=d[f[i+1]];

            if((aa<bb&&bb<cc)||(cc<aa&&aa<bb)||(bb<cc&&cc<aa))

            {

                ans[i]=ans[i+1];

                f[i]=f[i+1];

            }

            else

            {

                ans[i]=ans[i+1]+1;

                f[i]=i+1;

            }

        }

    }

    printf("%d\n",ans[1]);

    return 0;

}
