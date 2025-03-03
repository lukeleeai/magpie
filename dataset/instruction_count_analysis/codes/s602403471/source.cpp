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

    int h, w;

    cin >> h >> w;

    vector<vector<char>> S(2010, vector<char>(2010, '#'));

    for(int i = 1; i <= h; i++){

        for(int j = 1; j <= w; j++){

            cin >> S[i][j];

        }

    }



    Graph H(2010), W(2010);

    for(int i = 0; i <= h + 1; i++){

        for(int j = 0; j <= w + 1; j++){

            if(S[i][j] == '#'){

                H[i].push_back(j);

                W[j].push_back(i);

            }

        }

    }



    int ans = 0;



    for(int i = 1; i <= h; i++){

        for(int j = 1; j <= w; j++){

            if(S[i][j] == '#') continue;

            auto itr1 = lower_bound(all(H[i]), j), itr2 = lower_bound(all(W[j]), i);

            int tmp = *itr1 + *itr2 - 3;

            itr1--;

            itr2--;

            tmp -= *itr1 + *itr2;

            ans = max(ans, tmp);

        }

    }



    cout << ans << endl;

}