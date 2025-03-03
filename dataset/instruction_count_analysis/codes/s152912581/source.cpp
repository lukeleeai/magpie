#include"stdc++.h"

using namespace std;

using ll = long long;



int N, M, R;

int r[8];

const int MAX_N = 202;

int mp[MAX_N][MAX_N];

int P[8];

bool used[8];

int res = 1e9 + 7;



void warshall_floyd() {

    for(int k = 0; k < N; ++k)

        for(int i = 0; i < N; ++i) 

            for(int j = 0; j < N; ++j)

                mp[i][j] = min(mp[i][j], mp[i][k] + mp[k][j]);

}



void perm(int cur) {

    if(cur >= R) {

        int tmp = 0;

        for(int i = 1; i < R; ++i) {

            int j = r[P[i-1]], k = r[P[i]];

            tmp += mp[j][k];

        }

        /*

        for(int i = 0; i < R; ++i) cout << r[P[i]] << " ";

        cout << endl;

        cout << "tmp : " << tmp << endl;

        */

        res = min(res, tmp);

    }

    else {

        for(int i = 0; i < R; ++i) {

            if(!used[i]) {

                used[i] = true;

                P[i] = cur;

                perm(cur + 1);

                used[i] = false;

            }

        }

    }

}



void solve() {

    warshall_floyd();

    /*

    for(int i = 0; i < N; ++i){

        for(int j = 0; j < N; ++j) cout << mp[i][j] << " ";

        cout << endl;

    }

    cout << endl;

    */

    perm(0);

    cout << res << endl;

}



int main()

{

    cin >> N >> M >> R;

    for(int i = 0; i < N; ++i) 

        for(int j = 0; j < N; ++j) 

            if(i != j) mp[i][j] = 1e8;



    for(int i = 0; i < R; ++i) { cin >> r[i]; --r[i]; }

    for(int i = 0; i < M; ++i) {

        int a, b, c;

        cin >> a >> b >> c;

        --a, --b;

        mp[a][b] = mp[b][a] = c;

    }



    solve();

    return 0;

}