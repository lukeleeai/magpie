#include <iostream>

#include <vector>

using namespace std;



typedef long long int ll;

template<typename T> void chmin(T &a, T b) {a = min(a, b);}

const ll INF = 1LL << 50;



int N, M, R;

ll z[1010];

ll dl[210][210], ds[210][210], dist[1010][210];



int main() {

    while(cin >> N >> M, N || M) {

        for(int i=0; i<N; i++) {

            for(int j=0; j<N; j++) {

                if(i == j) continue;

                dl[i][j] = ds[i][j] = INF;

            }

        }

        for(int i=0; i<M; i++) {

            ll x, y, t; string sl; cin >> x >> y >> t >> sl;

            x--; y--;

            if(sl == "L") {

                chmin(dl[x][y], t);

                chmin(dl[y][x], t);

            }

            else {

                chmin(ds[x][y], t);

                chmin(ds[y][x], t);

            }

        }



        cin >> R;

        for(int i=0; i<R; i++) cin >> z[i], z[i]--;

        for(int i=0; i<R; i++) {

            for(int j=0; j<N; j++) {

                dist[i][j] = INF;

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



        dist[0][z[0]] = 0;

        for(int i=0; i<R-1; i++) {

            int cur = z[i], to = z[i+1];

            for(int j=0; j<N; j++) {

                if(dist[i][j] == INF) continue;



                // land only

                chmin(dist[i+1][j], dist[i][j] + dl[cur][to]);



                // sea

                for(int k=0; k<N; k++) {

                    chmin(dist[i+1][k], dist[i][j] + dl[cur][j] + ds[j][k] + dl[k][to]);

                }

            }

        }



        ll ans = INF;

        for(int i=0; i<N; i++) chmin(ans, dist[R-1][i]);

        cout << ans << endl;

    }

    return 0;

}