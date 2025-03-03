#include"stdc++.h"

using namespace std;



const int maxn=1000000;

int main()

{

    int n,w[maxn],ans,m,tmp;

    char rank[maxn];

    while(~scanf("%d",&n))

    {

        scanf("%s",rank+1);

        fill(w+1,w+n,0);

        for(int i=n;i>=1;i--)

        {

            w[i]=w[i+1];

            if(rank[i]=='W') w[i]++;

        }

        m=w[1];

        ans=maxn;

        for(int i=n;i>=1;i--)

        {

            tmp=((n-i)-w[i+1])+(m-w[i]);

            ans=min(ans,tmp);

        }

        printf("%d\n",ans);

    }

    return 0;

}
