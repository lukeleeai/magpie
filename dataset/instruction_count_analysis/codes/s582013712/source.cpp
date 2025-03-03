#include<cstdio>

int e(int p,int q)

{

    if(q==0)

        return p;

    return e(q,p%q);

}

int main(void)

{

    int k,sum=0;

    scanf("%d" ,&k);

    for(int i=1;i<=k;i++)

        for(int j=1;j<=k;j++)

        {

            int g=e(i,j);

            for(int l=1;l<=k;l++)

                sum+=e(g,l);

        }

    printf("%d" ,sum);

    return 0;

}
