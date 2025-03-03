// #define _GLIBCXX_DEBUG

#include "stdc++.h"

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

#define all(v) v.begin(), v.end()

#define Graph vector<vector<int>>

typedef long long ll;

typedef pair<int, int> P;

const int INF = 1000000007;



int main(){

    int H, W;

    cin >> H >> W;

    vector<string> S(H);

    rep(i, H) cin >> S[i];

    Graph U(H, vector<int>(W, 0)), L(H, vector<int>(W, 0));



    rep(i, H){

        rep(j, W){

            if(S[i][j] == '#') continue;

            

            if(j == 0) L[i][j] = 1;

            else L[i][j] = L[i][j - 1] + 1;



            if(i == 0) U[i][j] = 1;

            else U[i][j] = U[i - 1][j] + 1;

        }

    }



    Graph D(H, vector<int>(W)), R(H, vector<int>(W));





    for(int i = H - 1; i >= 0; i--){

        for(int j = W - 1; j >= 0; j--){

            if(S[i][j] == '#') continue;

            

            if(j == W - 1) R[i][j] = 1;

            else R[i][j] = R[i][j + 1] + 1;



            if(i == H - 1) D[i][j] = 1;

            else D[i][j] = D[i + 1][j] + 1;

        }

    }



    int ans = 0;



    rep(i, H){

        rep(j, W){

            if(S[i][j] == '#') continue;

            int tmp = U[i][j] + D[i][j] + L[i][j] + R[i][j] - 3;

            ans = max(ans, tmp);

        }

    }



    cout << ans << endl;

    

}