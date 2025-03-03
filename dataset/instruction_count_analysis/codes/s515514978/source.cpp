#include<cstdio>

using namespace std;

char mp[4]={'R','G','Y','B'};

int main ()

{

    int n,m,d,cx,cy;

    scanf("%d%d%d",&n,&m,&d);

    for(int i=1;i<=n;i++)

    {

        for(int j=1;j<=m;j++)

            cx=i+j+500,cy=i-j+500,printf("%c",mp[cx/d%2+cy/d%2*2]);

        printf("\n");

    }

    return 0;

}