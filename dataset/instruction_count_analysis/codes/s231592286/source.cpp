#include <stdio.h>

#include <string.h>

#define MAXN 10010

double v,e,f,b;

int dis[MAXN];

double dp[MAXN],time[MAXN];

int r,n;

void calc()

{

    int i;

    memset(time,0,sizeof time);

    for (i = 0; i <= dis[n]+1; i++)

    {

        double tmp;

        if (i >= r) tmp = 1.0 / (v - e * (i - r));

        else tmp = 1.0 / (v - f * (r - i));

        time[i+1] = time[i] + tmp;

    }

}



int main() {

    while (scanf("%d", &n) && n)

    {

        memset(dp,0,sizeof dp);

        memset(dis,0,sizeof dis);

        for (int i = 1; i <= n; i++)

            scanf("%d", &dis[i]);

        scanf("%lf",&b);

        scanf("%d%lf%lf%lf",&r,&v,&e,&f);

        calc();

        double min;



        for(int i = 1; i <= n; i++)

        {

            double tmp;

            min = 10000000000;

            for(int j = 0; j < i; j++)

                if ((tmp = dp[j] + time[dis[i] - dis[j]]) < min)

                    min = tmp;

            dp[i] = min + b;

        }

        printf("%.4lf\n", dp[n] - b);

    }

}