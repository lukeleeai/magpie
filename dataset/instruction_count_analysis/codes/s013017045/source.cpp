#include "stdc++.h"

#define N 1805

using namespace std;



const int fx[] = { 0, 1, 0,-1};

const int fy[] = { 1, 0,-1, 0};



int n,m,k,sx,sy;

char s[N];

bool vis[N][N],mp[N][N],flag;

queue<int> qx,qy,qs;

int main() {

    scanf("%d%d%d",&n,&m,&k);

    for (int i=1;i<=n;i++) {

        scanf("%s",s+1);

        for (int j=1;j<=m;j++) mp[i][j] = s[j]!='#';

        for (int j=1;j<=m;j++) if (s[j]=='S') sx=i, sy=j;

    }



    if (sx == 1 || sx == n || sy == 1 || sy == m) return puts("0"), 0;



    vis[sx][sy] = 1;

    qx.push(sx), qy.push(sy), qs.push(0);

    while (!qx.empty()) {

        int ux = qx.front(); qx.pop();

        int uy = qy.front(); qy.pop();

        int us = qs.front(); qs.pop();

        if (us == k) continue;

        if (ux == 1 || ux == n || uy == 1 || uy == m) flag = 1;



        for (int i=0;i<4;i++) {

            int vx = ux + fx[i], vy = uy + fy[i];

            if (vx<1 || vx>n || vy<1 || vy>m) continue;

            if (!vis[vx][vy] && mp[vx][vy]) {

                vis[vx][vy] = 1;

                qx.push(vx), qy.push(vy), qs.push(us+1);

            }

        }

    }



    if (flag) return puts("1"), 0;



    int ans = 2147483647;   

    for (int i=1;i<=n;i++)

        for (int j=1;j<=m;j++) if (vis[i][j]) {

            int t = min( min(i-1,j-1) , min(n-i,m-j) );

            int cur = (t+k-1) / k;

            ans = min(ans, cur+1);

        }

    cout << ans << endl;

    return 0;

}