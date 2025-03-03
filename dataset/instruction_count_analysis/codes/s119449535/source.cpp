#include <iostream>

#include"stdc++.h"

using namespace std;

long long int a[1000][1000],b[1000][1000],c[1000][1000];

//char x[1050][150],y[100050][20];



int main()

{

    long long int i,n,m,j,k,x,y;

    long long  int sum=0;

    scanf("%lld",&n);

    //memset(b,1,sizeof(b));

    for(i=1; i<=n; i++)

    {

        for(j=1; j<=n; j++)

        {

            scanf("%lld",&a[i][j]);



        }

    }

    memset(c,0,sizeof(c));

    for(k=1;k<=n;k++)

    {

        for(i=1;i<=n;i++)

        {

            for(j=1;j<=n;j++)

            {

                if(b[i][j]==0)

                {

                    b[i][j]=a[i][j];

                }

                b[i][j]=min(b[i][j],a[i][k]+a[k][j]);

                if((a[i][j]>=a[i][k]+a[k][j])&&(i!=k&&j!=k))

                {

                    c[i][j]=1;

                    b[i][j]=a[i][k]+a[k][j];

                }

            }

        }

    }

    int f=0;

    for(i=1;i<n;i++)

    {

        for(j=i+1;j<=n;j++)

        {

            if(a[i][j]!=b[i][j])

            {

                f=-1;

                break;

            }if((c[i][j]!=1)&&(a[i][j]==b[i][j]))

            {

                sum+=b[i][j];

            }

        }

        if(f==-1)

        {

            break;

        }

    }

    if(f==-1)

    {

        printf("-1");

    }else

    {

        printf("%lld",sum);

    }

    return 0;

}
