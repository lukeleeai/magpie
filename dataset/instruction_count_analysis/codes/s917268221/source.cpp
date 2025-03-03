#include <cstdio>

#include <cstring>

#include <vector>

using namespace std;

vector<int> G[200005];

vector<int> second;

bool vis[200005];

int main() {

    int N, M;

    scanf("%d%d",&N,&M);

    memset(vis, false, sizeof(vis));

    for (int i = 0; i < M; i++) {

        int a, b;

        scanf("%d%d",&a,&b);

        G[a].push_back(b);

        G[b].push_back(a);

    }

    for (int i = 0; i < G[1].size(); i++) {

        int v = G[1][i];

        if (!vis[v]) {

            second.push_back(v);

            vis[v] = true;

        }

    }

    for (int i = 0; i < second.size(); i++) {

        int v = second[i];

        for (int j = 0; j < G[v].size(); j++) {

            if (G[v][j] == N) {

                printf("POSSIBLE\n");

                return 0;

            }

        }

    }

    printf("IMPOSSIBLE\n");

    return 0;

}
