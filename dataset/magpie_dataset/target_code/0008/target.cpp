#include<stdio.h>

#include<stdlib.h>

#include<math.h>





typedef long long ll;





ll *mem, *inp, dist, min_dist, N;

int k;



int main()

{

    ll i, j;

    scanf("%lld%d", &N, &k);



    mem =(ll*) malloc(N * sizeof(ll));

    inp =(ll*) malloc(N * sizeof(ll));



    for(i = 0; i<N; ++i){

        scanf("%lld", inp+i);

    }



    *(mem+N-2) = llabs(*(inp+N-2) - *(inp+N-1));



    for(i = 3; i<=k+1 && i<=N; ++i)

        *(mem+N-i) = llabs(*(inp+N-i) - *(inp+N-1));



    for(i = N-(k+2); i>=0; --i){



        min_dist = llabs(*(inp+i) - *(inp+i+1)) + *(mem+i+1);

        for(j = 2; j<=k && i+j<N; ++j){

            dist = llabs(*(inp+i) - *(inp+i+j)) + *(mem+i+j);

            if (dist < min_dist) min_dist = dist;

        }



        *(mem+i) = min_dist;

    }



    printf("%lld\n", *mem);



    return 0;

}






