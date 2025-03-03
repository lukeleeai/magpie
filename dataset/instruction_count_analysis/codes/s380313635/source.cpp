#include "stdc++.h"

using namespace std;



int A[55];

bool boleh[55];

int B[55];

int C[55];

int indx[55];

long long ncr[55][55];



long long ncrUpTo[55][55];

vector<int> s[(1<<18)+5];



int cnt2[(1<<18)+5];



int main(){

    int N, K, S, T;

    scanf("%d%d%d%d", &N, &K, &S, &T);



    if( ((S&T) == S) && ((S|T) == T) ){

    }else{

        printf("0");

        return 0;

    }



    memset(ncr, 0, sizeof(ncr));

    ncr[0][0] = 1;

    for(int i = 1; i <= N; i ++){

        ncr[i][0] = 1;

        for(int j = 1; j <= i; j ++){

            ncr[i][j] = ncr[i-1][j] + ncr[i-1][j-1];

        }

    }



    ncrUpTo[0][0] = 0;

    for(int i = 1; i <= N; i ++){

        ncrUpTo[i][0] = 0;

        for(int j = 1; j <= N; j ++){

            ncrUpTo[i][j] = ncrUpTo[i][j-1] + ncr[i][j];

        }

    }



    for(int i = 0; i < N; i ++){

        scanf("%d", &A[i]);

        boleh[i] = true;

        //printf("A[%d]=%d\n", i, A[i]);

    }



    int L = 0;

    for(int i = 0; i < 20; i ++){

        if( (S&(1<<i)) == (T&(1<<i)) ){

            for(int j = 0; j < N; j ++){

                if( (S&(1<<i)) != (A[j]&(1<<i)) ){

                    boleh[j] = false;

                    //printf("boleh[%d]=false\n", j);

                }

            }

        }else{

            indx[L ++] = i;

        }

    }



    for(int i = 0; i < L; i ++){

        for(int j = 0; j < N; j ++){

            if(A[j]&(1<<indx[i])){

                B[j] |= (1<<i);

            }

        }

    }



    int M = 0;

    for(int i = 0; i < N; i ++){

        if(boleh[i]){

            C[M ++] = B[i];

        }

    }



    for(int i = 0; i < M; i ++){

        //printf("C[%d]=%d\n", i, C[i]);

    }



    memset(cnt2, 0, sizeof(cnt2));

    long long ans = 0;

    for(int U = 0; U < (1<<L); U ++){

        long long f = 0;



        for(int i = 0; i < M; i ++){

            if(!cnt2[U&C[i]]){s[U].emplace_back(U&C[i]);}

            cnt2[U&C[i]] ++;

        }



        for(int j: s[U]){

            int cnt = cnt2[j];

            f += ncrUpTo[cnt][K];

            cnt2[j] = 0;

        }



        int temp = __builtin_popcount(U);

        if(temp&1){

            ans -= f;

        }else{

            ans += f;

        }

    }



    printf("%lld", ans);

    return 0;

}
