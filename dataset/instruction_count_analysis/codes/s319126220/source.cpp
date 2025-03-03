#include<cstdio>

#include<cstring>

#include<algorithm>

const int maxn=1e5+10;

int n,k,x[maxn],ans=0x7fffffff;

int main()

{

    scanf("%d%d",&n,&k);

    for(int i=1;i<=n;i++)

    {

        scanf("%d",&x[i]);

    }

    for(int l=1;l+k-1<=n;l++)

    {

        int r=l+k-1;

        ans=std::min(ans,x[r]-x[l]+std::min(abs(x[l]),abs(x[r])));

    }

    printf("%d\n",ans);

}
