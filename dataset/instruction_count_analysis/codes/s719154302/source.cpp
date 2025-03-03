#include<iostream>

#include<cstdio>

#include<algorithm>

#include<cmath>

#include<map>

#include<cstring>

#include<climits>

#include<queue>

using namespace std;

#define MAXC 30

#define MAXN 500

int n,c,ans;

int D[MAXC+5][MAXC+5],C[MAXN+5][MAXN+5];

int cont[4][MAXC+5];

int main()

{

    ans=INT_MAX;

    scanf("%d%d",&n,&c);

    for(int i=1;i<=c;i++)

        for(int j=1;j<=c;j++)

        scanf("%d",&D[i][j]);

    for(int i=1;i<=n;i++)

        for(int j=1;j<=n;j++)

        scanf("%d",&C[i][j]);

    for(int i=1;i<=n;i++)

        for(int j=1;j<=n;j++)

        cont[(i+j)%3][C[i][j]]++;

    for(int i=1;i<=c;i++)

        for(int j=1;j<=c;j++)

        if(i!=j)

            for(int k=1;k<=c;k++)

            if(k!=i&&k!=j)

            {

                int res=0;

                for(int p=1;p<=c;p++)res+=cont[0][p]*D[p][i];

                for(int p=1;p<=c;p++)res+=cont[1][p]*D[p][j];

                for(int p=1;p<=c;p++)res+=cont[2][p]*D[p][k];

                ans=min(ans,res);

            }

    printf("%d",ans);

}
