#include <cstdio>

#include <algorithm>

using std::max;



#define MAXN 100003

int d[MAXN][3],a[MAXN][3];

int main(void)

{

    int i,N;

    scanf("%d",&N);

    for(i=0;i<N;i++)

    {

        scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);

    }

    d[0][0]=a[0][0];

    d[0][1]=a[0][1];

    d[0][2]=a[0][2];

    for(i=1;i<N;i++)

    {

        d[i][0]=a[i][0]+max(d[i-1][1],d[i-1][2]);

        d[i][1]=a[i][1]+max(d[i-1][0],d[i-1][2]);

        d[i][2]=a[i][2]+max(d[i-1][1],d[i-1][0]);

    }

    printf("%d\n",max(d[N-1][0],max(d[N-1][1],d[N-1][2])));



    return 0;

}