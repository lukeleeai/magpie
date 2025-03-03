#include <cstdio>

#include <cstring>

#include <algorithm>

using namespace std;

const int maxd = 20;

int arr[maxd][maxd],k;

int n,m,ans;

int abs(int x){ return (x<0)?-x:x;}

int check(int x,int y)

{

    int sum = 0;

    for(int i=1;i<=m;i++)

        sum+= (arr[x][i]-arr[y][i])*(arr[x][i] - arr[y][i]);



    //printf("%d %d %d\n",x,y,sum);

    for(int i=1;i*i<=sum;i++)

        if(i*i==sum) return 1;

    return 0;

}

int main()

{

    // freopen("a.in","r",stdin);

    // freopen("k.out","w",stdout);

    scanf("%d %d",&n,&m);

    for(int i=1;i<=n;i++)

        for(int j=1;j<=m;j++) scanf("%d",&arr[i][j]);

    for(int i=1;i<=n;i++)

        for(int j=i+1;j<=n;j++)

            ans += check(i,j);

    printf("%d",ans);

    return 0;

}