/*

 * Author:heroming

 * File:heroming.cpp

 * Time:2012-7-19 9:33:45

 */

#include <iostream>

#include <cstdio>

#include <string>

#include <cstring>

#include <cmath>

#include <algorithm>

#include <vector>

#include <queue>

using namespace std;



#define SZ(v) ((int)(v).size())

const int INFI = 1<<30;

const int MAXN = 102, MAXC = 22, MAXP = 52;



bool inQ[MAXN];

int n, m, c, s, g;

int maps[MAXN][MAXN][MAXC], dis[MAXN];

int P[MAXC], Q[MAXP][MAXP], R[MAXP][MAXP];



int get_cost(int k, int d)

{

        int x = 0;

        for (int i = 1; i < P[k]; ++ i)

        {

                if (d > Q[k][i])

                        x += (Q[k][i] - Q[k][i - 1]) * R[k][i];

                else

                {

                        x += (d - Q[k][i - 1]) * R[k][i];

                        return x;

                }

        }

        return x + R[k][P[k]] * (d - Q[k][P[k] - 1]);

}



void SPFA()

{

        memset(inQ, 0, sizeof(inQ));

        for (int i = 1; i <= n; ++ i)

                dis[i] = INFI;

        dis[s] = 0;

        queue<int> Q;

        Q.push(s);

        inQ[s] = 1;

        while (! Q.empty())

        {

                int u = Q.front();

                Q.pop();

                inQ[u] = 0;

                for (int i = 1; i <= n; ++ i)

                        for (int j = 1; j <= c; ++ j)

                                if (maps[u][i][j] != -1)

                                {

                                        int p = get_cost(j, maps[u][i][j]);

                                        if (dis[u] + p < dis[i])

                                        {

                                                dis[i] = dis[u] + p;

                                                if (! inQ[i])

                                                {

                                                        Q.push(i);

                                                        inQ[i] = 1;

                                                }

                                        }

                                }

        }

}



int main()

{

        while (scanf("%d%d%d%d%d", &n, &m, &c, &s, &g) != EOF && n)

        {

                memset(maps, -1, sizeof(maps));

                int x, y, w, e;

                for (int i = 0; i < m; ++ i)

                {

                        scanf("%d%d%d%d", &x, &y, &w, &e);

                        if (maps[x][y][e] != -1)

                                maps[x][y][e] = maps[y][x][e] = min(maps[x][y][e], w);

                        else

                                maps[x][y][e] = maps[y][x][e] = w;

                }

                for (int i = 1; i <= c; ++ i)

                        scanf("%d", &P[i]);

                for (int i = 1; i <= c; ++ i)

                {

                        for (int j = 1; j < P[i]; ++ j)

                                scanf("%d", &Q[i][j]);

                        for (int j = 1; j <= P[i]; ++ j)

                                scanf("%d", &R[i][j]);

                }

                for (int l = 1; l <= c; ++ l)

                        for (int k = 1; k <= n; ++ k)

                                for (int i = 1; i <= n; ++ i)

                                        for (int j = 1; j <= n; ++ j)

                                        {

                                                if (i == j || i == k || j == k || maps[i][k][l] == -1 || maps[k][j][l] == -1)

                                                        continue;

                                                if (maps[i][j][l] == -1 || maps[i][k][l] + maps[k][j][l] < maps[i][j][l])

                                                        maps[i][j][l] = maps[j][i][l] = maps[i][k][l] + maps[k][j][l];

                                        }



                SPFA();

                if (dis[g] == INFI)

                        printf("-1\n");

                else

                        printf("%d\n", dis[g]);

        }

        return 0;

}