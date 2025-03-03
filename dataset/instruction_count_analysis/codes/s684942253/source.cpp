#include <cstdio>

#include <cstring>

#include <algorithm>

#include <vector>

#include <queue>

#include <map>

#include <string>

#include <iostream>



#define pb push_back

#define mp make_pair



using namespace std;



char s[15][25];

int calc[15][15];

bool flag[15];

int list[15],cnt;

int n,N;

int len[15];

int dp[1<<15][15];



int gao(int x,int y){

    int lenx = strlen(s[x]) , leny = strlen(s[y]);

    int ret=0;

    for (int i=1; lenx-i>=0 && i-1 < leny ; i++){

        bool flag=true;

        for (int j=0;j<=i-1;j++)

            if (s[y][j]!=s[x][lenx-i+j]) flag=false;

        if (flag) ret=max(ret,i);

    }

    return ret;



}



bool inside(int x,int y){

    int lenx = strlen(s[x]) , leny = strlen(s[y]);

    if (lenx > leny) return false;

    bool flag=false;

    for (int i = 0 ; i <= leny - lenx ; i++){

        bool same=true;

        for (int j = 0 ; j < lenx ; j++)

            if (s[x][j]!=s[y][j+i]) same=false;

        if (same) flag=true;

    }

    return flag;

}



void prework(){

    // s[i]s[j]

    for (int i=0;i<n;i++)

        for (int j=0;j<n;j++)

            if (i!=j) calc[i][j] = gao(i,j);

}



int main(){



    //freopen("input.txt","r",stdin);



    while (~scanf("%d",&n) && n){

        for (int i=0;i<n;i++) scanf("%s",s[i]),flag[i]=true;



        for (int i=0;i<n;i++)

            for (int j=0;j<n;j++)

                if (i!=j && inside(i,j)) flag[i]=false;



        N=0;

        for (int i=0;i<n;i++)

            if (flag[i]) list[N++]=i;



        for (int i=0;i<n;i++) len[i]=strlen(s[i]);

        prework();



        for (int i=0;i<(1<<N);i++)

            for (int j=0;j<N;j++)

                dp[i][j]=0x3F3F3F3F ;



        for (int i=0;i<N;i++) dp[1<<i][i] = len[list[i]];

        for (int i=1;i<(1<<N);i++){

            for (int j=0;j<N;j++)

                if ((i>>j)&1)

                    for (int k=0;k<N;k++)

                        if (!((i>>k)&1))

                            dp[i|(1<<k)][k] = min(dp[i|(1<<k)][k] , dp[i][j] + len[list[k]] - calc[list[k]][list[j]]);

        }



        int ans=0x3F3F3F3F;

        for (int i=0;i<N;i++)

            ans = min(dp[(1<<N)-1][i],ans);

        printf("%d\n",ans);

    }

    return 0;

}