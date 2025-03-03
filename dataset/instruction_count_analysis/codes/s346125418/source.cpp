#include<cstdio>

#include<algorithm>



#define REP(i,n)   for(int i=0;i<(n);++i)

const int INF = 1e9;



#define MV 100

#define ME 1000

int d[MV][MV],a[ME],b[ME],c[ME];



int main(){

    int v,e,ans=0;

    scanf("%d",&v);

    REP(i,v) REP(j,v) d[i][j] = INF;

    REP(i,v) d[i][i] = 0;

    scanf("%d",&e);

    REP(i,e) scanf("%d%d%d",a+i,b+i,c+i);

    REP(i,e){

        --a[i];--b[i];

        d[a[i]][b[i]] = d[b[i]][a[i]] = c[i];

    }



    REP(k,v) REP(i,v) REP(j,v) d[i][j] = std::min(d[i][j],d[i][k] + d[k][j]);



    bool used;

    REP(i,e){

        used = true;

        REP(s,v) if(d[s][a[i]] + c[i] == d[s][b[i]]) used = false;

        if(used) ++ans;

    }



    printf("%d\n",ans);

    return 0;

}
