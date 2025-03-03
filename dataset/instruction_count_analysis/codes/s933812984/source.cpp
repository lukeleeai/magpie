#include <cstdio>

#include <algorithm>

using namespace std;



void chmin(int &a, int b) {

     a = min(a, b);

}



const int INF = 1 << 25;

int N, M, R;

int dl[210][210], ds[210][210], dist[1010][210], op[1010];



int main() {

    while(scanf("%d%d", &N, &M)) {

        if(N == M && M == 0) break;

        for(int i=0; i<N; i++) {

            fill(dl[i], dl[i] + N, INF);

            fill(ds[i], ds[i] + N, INF);

            dl[i][i] = ds[i][i] = 0;

        }



        for(int i=0; i<M; i++) {

            int x, y, t; char s;

            scanf(" %d%d%d %c", &x, &y, &t, &s);

            x--; y--;

            if(s == 'L') {

                chmin(dl[x][y], t);

                chmin(dl[y][x], t);

            }

            else {

                chmin(ds[x][y], t);

                chmin(ds[y][x], t);

            }

        }



        for(int k=0; k<N; k++) {

            for(int i=0; i<N; i++) {

                for(int j=0; j<N; j++) {

                    chmin(dl[i][j], dl[i][k] + dl[k][j]);

                    chmin(ds[i][j], ds[i][k] + ds[k][j]);

                }

            }

        }



        scanf("%d", &R);

        for(int i=0; i<R; i++) {

            scanf("%d", &op[i]); op[i]--;

            fill(dist[i], dist[i] + N, INF);

        }



        dist[0][op[0]] = 0;

        for(int i=0; i<R-1; i++) {

            for(int j=0; j<N; j++) {

                if(dist[i][j] == INF) continue;

                int cur = op[i], nxt = op[i+1];



                // land only

                chmin(dist[i+1][j], dist[i][j] + dl[cur][nxt]);



                // land + sea

                for(int k=0; k<N; k++) {

                    chmin(dist[i+1][k], dist[i][j] + dl[cur][j] + ds[j][k] + dl[k][nxt]);

                }

            }

        }



        printf("%d\n", *min_element(dist[R-1], dist[R-1] + N));

    }

    return 0;

}
