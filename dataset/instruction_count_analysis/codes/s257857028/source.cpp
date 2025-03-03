#include "stdc++.h"

using namespace std;



long long int N, K, A[364364], B, L;



int main(){

    scanf("%lld%lld", &K, &N);

    if(K == 1){

        for(int i = 0; i < (N + 1) / 2; ++i)cout << "1 ";

        return 0;

    }

    if(K & 1){

        fill(A, A + 364364, K / 2 + 1);

        B = N / 2;

        L = N;

        for(int i = 0; i < B; ++i){

            if(--A[L - 1]){

                for(; L < N; ++L){

                    A[L] = K;

                }

            }else{

                --L;

            }

        }

        for(int i = 0; i < N; ++i){

            if(A[i] == 0)return 0 & puts("");

            cout << A[i] << " ";

        }

    }else{

        cout << (K >> 1) << " ";

        for(int i = 0; ++i < N;)cout << K << " ";

    }

    return 0;

}
