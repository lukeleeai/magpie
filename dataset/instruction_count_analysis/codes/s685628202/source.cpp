#include"stdc++.h"

using namespace std;

int const nax = 2e5 + 10;



vector<int> a[nax];

int node[2][nax];

int top[2];



int n , ct[3], c[3], col[nax];

int  ptr1 = -2, ptr2 = -1, ptr3  = 0;



void dfs (int nod,  int pa, int lv) {

    ct[lv % 2] ++;

    node[lv % 2][top[lv % 2] ++] = nod;

    for (int i : a[nod])

        if (i != pa)

            dfs(i, nod, lv + 1);

}



int main () {

    scanf("%d", &n);

    for (int i = 1 ; i < n ; ++ i) {

        int u, v;

        scanf("%d %d", &u, &v);

        a[u].emplace_back(v);

        a[v].emplace_back(u);

    }



    c[0] = n / 3 ;

    c[1] = n / 3 + (n % 3 > 0);

    c[2] = n / 3 + (n % 3 > 1);



    dfs(1, 0, 0);



    if (max(ct[0], ct[1]) >= c[1] + c[2]) {

        int toCol = ct[0] >= ct[1] ? 0 : 1;

        for (int i = 0 ;i < c[1] ; ++ i)

            col[node[toCol][i]] = (ptr1 += 3);



        for (int i = 0 ; i < c[2] ; ++ i)

            col[node[toCol][i + c[1]]] = (ptr2 += 3);

    }

    else if (max(ct[0], ct[1]) >= c[1] && min(ct[0], ct[1]) >= c[2]) {

        int maxCol = ct[0] >= ct[1] ? 0 : 1;

        int minCol = (maxCol ^ 1);

        for (int i = 0 ; i < c[1] ; ++ i)

            col[node[maxCol][i]] = (ptr1 += 3);



        for (int i = 0 ; i < c[2] ; ++ i)

            col[node[minCol][i]] = (ptr2 += 3);

    }



    for (int i = 1 ; i <= n ; ++ i)

        printf("%d ", col[i] ? col[i] : ptr3 += 3);





}

/*

    Good Luck

        -Lucina

*/
