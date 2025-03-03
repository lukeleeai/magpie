#include "stdc++.h"

using namespace std;



typedef long long llt;



const int MaxN = 100000 + 5;



int N;

llt A[MaxN];

llt ans1, ans2;

deque <llt> que1, que2;



inline llt llAbs(llt x) {

    if (x < 0) return -x;

    return x;

}



int main() {

    scanf("%d", &N);

    for (int i = 1; i <= N; ++i) scanf("%lld", &A[i]);



    sort(A + 1, A + 1 + N);



    que1.push_back(A[1]);

    que2.push_back(A[N]);



    llt Max = A[N], Min = A[2];

    int Maxi = N, Mini = 2;

    for (int i = 2; i <= N; ++i) {

        llt F = que1.front(), L = que1.back();

        llt ValF = max(llAbs(F - Max), llAbs(F - Min)),

            ValL = max(llAbs(L - Max), llAbs(L - Min));

        if (ValF > ValL) {

            ans1 += ValF;

            // printf("ans1 += %lld\n", ValF);

            if (llAbs(F - Max) == ValF) que1.push_front(Max), Maxi--;

            else que1.push_front(Min), Mini++;

        } else {

            ans1 += ValL;

            // printf("ans1 += %lld\n", ValL);

            if (llAbs(L - Max) == ValL) que1.push_back(Max), Maxi--;

            else que1.push_back(Min), Mini++;

        }

        Max = A[Maxi]; Min = A[Mini];

    }



    Max = A[N - 1], Min = A[1];

    Maxi = N - 1, Mini = 1;

    for (int i = 2; i <= N; ++i) {

        llt F = que2.front(), L = que2.back();

        llt ValF = max(llAbs(F - Max), llAbs(F - Min)),

            ValL = max(llAbs(L - Max), llAbs(L - Min));

        if (ValF > ValL) {

            ans2 += ValF;

            // printf("ans2 += %lld\n", ValF);

            if (llAbs(F - Max) == ValF) que2.push_front(Max), Maxi--;

            else que2.push_front(Min), Mini++;

        } else {

            ans2 += ValL;

            // printf("ans2 += %lld\n", ValL);

            if (llAbs(L - Max) == ValL) que2.push_back(Max), Maxi--;

            else que2.push_back(Min), Mini++;

        }

        Max = A[Maxi]; Min = A[Mini];

    }



    cout << max(ans1, ans2) << endl;

    return 0;

}