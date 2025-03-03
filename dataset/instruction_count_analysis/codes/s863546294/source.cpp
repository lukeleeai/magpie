#include<cstdio>

#include<algorithm>

using namespace std;

const int MAXN = 100000;

struct node{

    int R, C, A;

    friend bool operator < (node a, node b) {

        return a.A < b.A;

    }

}nd[MAXN + 5];

int fa[2*MAXN + 5], key[2*MAXN + 5], siz[2*MAXN + 5];

int find(int x) {

    return fa[x] = (fa[x] == x ? x : find(fa[x]));

}

int N, H, W;

int main() {

    long long ans = 0;

    scanf("%d%d%d", &N, &H, &W);

    for(int i=1;i<=H;i++) fa[i] = i, siz[i] = 1, key[i] = 0;

    for(int i=1;i<=W;i++) fa[i + H] = i + H, siz[i + H] = 1, key[i + H] = 0;

    for(int i=1;i<=N;i++)

        scanf("%d%d%d", &nd[i].R, &nd[i].C, &nd[i].A);

    sort(nd + 1, nd + N + 1);

    for(int i=N;i>=1;i--) {

        int fx = find(nd[i].R), fy = find(nd[i].C + H);

        if( fx == fy ) {

            if( siz[fx] >= key[fx] + 1 ) {

                key[fx]++;

                ans += nd[i].A;

            }

        }

        else {

            if( siz[fx] + siz[fy] >= key[fx] + key[fy] + 1 ) {

                siz[fx] += siz[fy], key[fx] += key[fy] + 1, fa[fy] = fx;

                ans += nd[i].A;

            }

        }

    }

    printf("%lld\n", ans);

}