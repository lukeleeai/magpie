#include <cstdio>

#include <cstring>

#include <algorithm>

#include <cstring>

using namespace std;

const int mx = 2020;

int dp[mx][mx],cw[mx][mx],cb[mx][mx],w[mx],b[mx];

char col[10];

int main()

{

    int n,a,cont1=1,cont2=1;

    scanf("%d",&n);

    for(int i=1;i<=n;i++)

        for(int j=1;j<=n;j++)

            dp[i][j]=100000000;

    for(int i=1;i<=2*n;i++){

        scanf("%s",col);

        scanf("%d",&a);

        if(col[0]=='W')

            w[a]=i;

        else

            b[a]=i;

    }

    for(int i=1;i<=n;i++){

        for(int j=1;j<i;j++)

            if(w[j]>w[i])

                cw[i][0]++;

        for(int j=1;j<=n;j++){

            cw[i][j]=cw[i][j-1];

            if(w[i]<b[j])

                cw[i][j]++;

        }

    }

    for(int i=1;i<=n;i++){

        for(int j=1;j<i;j++)

            if(b[j]>b[i])

                cb[0][i]++;

        for(int j=1;j<=n;j++){

            cb[j][i]=cb[j-1][i];

            if(b[i]<w[j])

                cb[j][i]++;

        }

    }

    dp[0][0]=0;

    int c1=0,c2=0;

    for(int i=1;i<=n;i++){

        c1+=cw[i][0];

        c2+=cb[0][i];

        dp[i][0]=c1;

        dp[0][i]=c2;

    }

    for(int i=1;i<=n;i++)

        for(int j=1;j<=n;j++)

            dp[i][j]=min(dp[i-1][j]+cw[i][j],dp[i][j-1]+cb[i][j]);

    printf("%d\n",dp[n][n]);

    return 0;

}
