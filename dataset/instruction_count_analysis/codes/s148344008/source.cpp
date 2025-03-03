#include"stdc++.h"

using namespace std;



long long int K, N, A[303030], L, R;



int main(){

    scanf("%lld%lld", &K, &N);

    if(K ^ 1){

        if(K & 1){

            fill(A, A + N, (K + 1) / 2);

            L = N;

            for(R = N / 2 + 1; --R;)if(--A[--L])for(; L < N; A[++L] = K);

            for(int i = 0; i < N; cout << A[i++] << " ")if(!A[i])return 0 & puts("");

        }else{

            cout << K / 2 << " ";

            for(; --N; cout << K << " ");

        }

    }else for(N = (N + 3) / 2; --N; cout << "1 ");

    return 0;

}
