#include <cstdio>

#include <cmath>

#include <algorithm>

using namespace std;

const int maxn = 1e5 + 5;

typedef struct Node {

    int id, p, y, s;

} Node;

Node node[maxn] = { 0 };

bool cmp(Node &a, Node &b) {

    if (a.p == b.p) return a.y < b.y;

    return a.p < b.p;

}

bool cov(Node &a, Node &b) {

    return a.id < b.id;

}



int main() {

    int n, m;

    scanf("%d%d", &m, &n);

    for (int i = 1; i <= n; i++) {

        scanf("%d%d", &node[i].p, &node[i].y);

        node[i].id = i;

    }

    sort(node + 1, node + n + 1, cmp);

    int cnt = 1;

    for (int i = 1; i <= n; i++)

        if (node[i].p == node[i - 1].p) node[i].s = ++cnt;

        else node[i].s = cnt = 1;

    sort(node + 1, node + n + 1, cov);

    for (int i = 1; i <= n; i++)

        printf("%06d%06d\n", node[i].p, node[i].s);

    return 0;

}
