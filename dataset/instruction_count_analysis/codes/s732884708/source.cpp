#include "stdc++.h"



using namespace std;



#define MXN 20005

// #define debug



int mx[MXN], t[MXN], v[MXN], en;

double memo[MXN][105]; 

bool visited[MXN][105];

const int inf = 0x3f3f3f3f;



double dfs(int cur, int speed) {

    if (cur == en+1) {

        if (speed) return -inf;

        else return 0;

    }

    if (visited[cur][speed]) return memo[cur][speed];

    visited[cur][speed] = 1;

    double res = -inf;

    if (speed < mx[cur]) {

        res = max(res, dfs(cur+1, speed) + speed);

        res = max(res, dfs(cur+1, speed) + speed+0.25);

        res = max(res, dfs(cur+1, speed+1) + speed+0.5);

        if (speed) 

            res = max(res, dfs(cur+1, speed-1) + speed-0.5);

    } else if (speed == mx[cur]) {

        res = max(res, dfs(cur+1, speed) + speed);

        res = max(res, dfs(cur+1, speed-1) + speed-0.5);

    } 

    return memo[cur][speed] = res;

}



int main() { 

    int n;

    while (cin >> n) {

        en = 0;

        for (int i = 0; i < n; ++i) {

            cin >> t[i];

            en += t[i];

        }

        for (int i = 0; i < n; ++i) cin >> v[i];

        int cur = 1, tmp;

        for (int i = 0; i < n; ++i) {

            tmp = t[i];

            while (tmp--) {

                mx[cur++] = v[i];

            }

        }

#ifdef debug

        for (int i = 1; i <= en; ++i) {

            cout << mx[i] << " ";

        }

        cout << "\n";

#endif

        memset(visited, 0, sizeof(visited));

        printf("%.9lf\n", dfs(1, 0));

    }



    return 0;

}
