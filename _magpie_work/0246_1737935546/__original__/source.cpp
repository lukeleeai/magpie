#include "stdc++.h"

using namespace std;



typedef long long ll;

#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))

#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)

#define all(x) (x).begin(),(x).end()

#define pb push_back

#define fi first

#define se second



int C,D,W,X;

int E[15][30],F[15][30];



int dp[31][51][15][6];

int dfs(int day, int cost, int place, int two)

{

    if(dp[day][cost][place][two]>=0) return dp[day][cost][place][two];

    if(day==D) return 0;



    int ret=0;



    // ??????????????????

    rep(i,C) ret=max(ret,dfs(day+1,cost,i,two));



    if(E[place][day]>0)

    {

        // 1????????????

        if(cost+F[place][day]<=W)

        {

            rep(i,C) ret=max(ret,dfs(day+1,cost+F[place][day],i,two)+E[place][day]);

        }



        // ?????°????????????

        if(two<X)

        {

            int tcost=cost+F[place][day];

            int tE=E[place][day];

            int now=place-1;

            while(now>=0)

            {

                if(E[now][day]==0) break;

                if(tcost+F[now][day]>W) break;



                tcost+=F[now][day];

                tE+=E[now][day];

                rep(i,C) ret=max(ret,dfs(day+1,tcost,i,two+1)+tE);



                --now;

            }



            tcost=cost+F[place][day];

            tE=E[place][day];

            now=place+1;

            while(now<C)

            {

                if(E[now][day]==0) break;

                if(tcost+F[now][day]>W) break;



                tcost+=F[now][day];

                tE+=E[now][day];

                rep(i,C) ret=max(ret,dfs(day+1,tcost,i,two+1)+tE);

                ++now;

            }

        }

    }



    dp[day][cost][place][two]=ret;

    return ret;

}



int main()

{

    while(scanf(" %d %d %d %d",&C,&D,&W,&X),C)

    {

        rep(i,C)rep(j,D) scanf(" %d", &E[i][j]);

        rep(i,C)rep(j,D) scanf(" %d", &F[i][j]);



        memset(dp,-1,sizeof(dp));

        int ans=0;

        rep(i,C) ans=max(ans,dfs(0,0,i,0));

        printf("%d\n", ans);

    }

    return 0;

}