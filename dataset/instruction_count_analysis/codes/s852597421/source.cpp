#include "stdc++.h"

#define _GLIBCXX_DEBUG

#define rep(i, n) for(int i = 0; i < (int)(n); i++)

using namespace std;

using ll = long long;

const int INF = 1001001001;

const int MOD = 1000000007;

typedef long long ll;





int main(){

    int N, K;

    cin >> N >> K;

    int R, S, P;

    cin >> R >> S >> P;

    string T;

    cin >> T;



    int total = 0;

    for(int i = 0; i < N; i++){

        if(T[i] == 'r') total += P;

        if(T[i] == 's') total += R;

        if(T[i] == 'p') total += S;

    }



    for(int i = 0; i < K; i++){

        char before = 'x';

        int cnt = 1;

        for(int j = 0; j < (N+K-1)/ K; j++){

            if(j*K+i >= N) continue;

//            cout << ":" << j * K + i << endl;

            char now = T[j*K+i];

            if(before == now){

                cnt++;

            }else{

                // 精算処理

                int kake = cnt / 2;

                if(before == 'r') total -= P * kake;

                if(before == 'p') total -= S * kake;

                if(before == 's') total -= R * kake;



                // 初期化処理

                before = now;

                cnt = 1;

            }

        }

        // 精算処理

        int kake = cnt / 2;

        if(before == 'r') total -= P * kake;

        if(before == 'p') total -= S * kake;

        if(before == 's') total -= R * kake;



    }

    cout << total << endl;

    return 0;

}
