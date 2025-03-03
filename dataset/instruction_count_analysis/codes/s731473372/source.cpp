#include<stdio.h>

#include <string.h>

using namespace std;

int n,link[110][110],connect[110];

bool used[110];

bool find(int x)

{

    for(int i=1;i<=n;i++)

    {

        if(link[x][i]&&!used[i])

        {

            used[i]=true;

            if(connect[i]==0||find(connect[i]))

            {

                connect[i]=x;

                return true;

            }

        }

    }

    return false;

}

int main(void)

{

	int a[110],b[110],c[110],d[110];

	scanf("%d",&n);

	for(int i=1;i<=n;i++)

        scanf("%d%d",&a[i],&b[i]);

    for(int i=1;i<=n;i++)

        scanf("%d%d",&c[i],&d[i]);

    memset(connect,0,sizeof connect);

    for(int i=1;i<=n;i++)

        for(int j=1;j<=n;j++)

            if(a[i]<c[j]&&b[i]<d[j])

                link[i][j]=true;

    int ans=0;

    for(int i=1;i<=n;i++)

    {

        memset(used,false,sizeof used);

        if(find(i)) ans++;

    }

    printf("%d\n",ans);

	return 0;

}
