#include <cstdio>

#include <algorithm>

using namespace std;

struct Node {

    int l, r;

}node[100005];

bool cmp(Node a, Node b) {

    if (a.l == b.l)

        return a.r < b.r;

    return a.l < b.l;

}

int main() {

    int N, M;

    scanf("%d%d",&N,&M);

    for (int i = 0; i < M; i++) {

        int l, r;

        scanf("%d%d",&l,&r);

        node[i].l = l;

        node[i].r = r;

    }

    sort(node, node+M, cmp);

    int curl, curr;

    curl = curr = 0;

    int ans = 0;

    curl = node[0].l;

    curr = node[0].r;

    for (int i = 1; i < M; i++) {

        if (node[i].l >= curl && node[i].r <= curr) {

            curl = node[i].l;

            curr = node[i].r;

        } else if (node[i].l >= curl && node[i].r > curr && node[i].l < curr) {

            curl = node[i].l;

            curr = curr;

        } else {

            if (i !=0 )

                ans++;

            curl = node[i].l;

            curr = node[i].r;

        }

    }

    ans++;

    printf("%d\n",ans);

    return 0;

}
