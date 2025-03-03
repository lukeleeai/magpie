#include"stdc++.h"

using namespace std;

int f[4][4];

int main()

{

    int a,b,c;

    scanf("%d%d%d",&f[1][1],&f[1][2],&f[2][2]);

    a=f[2][2]*3;

    f[1][3]=a-f[1][1]-f[1][2];

    f[3][1]=a-f[1][3]-f[2][2];

    f[3][3]=a-f[1][1]-f[2][2];

    f[2][1]=a-f[1][1]-f[3][1];

    f[2][3]=a-f[2][1]-f[2][2];

    f[3][2]=a-f[1][2]-f[2][2];

    for(int i=1;i<=3;i++)

    {

        for(int j=1;j<=3;j++)

        {

            printf("%d ",f[i][j]);

        }

        printf("\n");

    }

    return 0;

}