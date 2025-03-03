#include"stdc++.h"

using namespace std;

int const nax = 3e5 + 10;

vector<int> a[nax];

int n , md[nax], ct[3];

vector<int> node[2];

void dfs (int nod,  int pa, int lv) {

    ct[lv % 2] ++;

    node[lv % 2].emplace_back(nod);

    for (int i : a[nod]) {

        if (i != pa) dfs(i, nod, lv + 1);

    }

}

vector<int> laz[3];

int col[nax];

int ptr3;

int c[3];

void reCol3 () {

    for (int i = 1 ;i  <= n ; ++ i) {

        if (col[i] == 0) {

            col[i] = laz[0][ptr3 ++];

        }

    }

}



int main () {

    scanf("%d", &n);

    for (int i = 1 ; i < n ; ++ i) {

        int u, v;

        scanf("%d %d", &u, &v);

        a[u].emplace_back(v);

        a[v].emplace_back(u);

    }

    for (int i = 1 ; i <= n; ++ i) {

        laz[i % 3].emplace_back(i);

    }

    c[0] = n / 3 ;

    c[1] = n / 3 + (n % 3 > 0);

    c[2] = n / 3 + (n % 3 > 1);

    dfs(1, 0, 0);

    if (max(ct[0], ct[1]) >= c[1] + c[2]) {

        int toCol = ct[0] >= ct[1] ? 0 : 1;

        for (int i = 0 ;i < (int)laz[1].size() ; ++ i) {

            col[node[toCol][i]] = laz[1][i];

        }

        for (int i = 0 ; i < (int) laz[2].size() ; ++ i) {

            col[node[toCol][i + (laz[1].size())]] = laz[2][i];

        }

        reCol3();

        for (int i = 1 ; i <= n ; ++ i) {

            printf("%d ", col[i]);

        }

    }

    else if (max(ct[0], ct[1]) >= c[1] && min(ct[0], ct[1]) >= c[2]) {

        int maxCol = ct[0] >= ct[1] ? 0 : 1;

        int minCol = (maxCol ^ 1);

        for (int i = 0 ; i < (int) laz[1].size() ; ++ i) {

            col[node[maxCol][i]] = laz[1][i];

        }

        for (int i = 0 ; i < (int) laz[2].size() ; ++ i)

            col[node[minCol][i]] = laz[2][i];

        reCol3();

        for (int i = 1 ; i <= n ; ++ i)

            printf("%d ", col[i]);

    }

    else throw;

}

/*

    Good Luck

        -Lucina

*/
