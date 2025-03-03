#include "stdc++.h"

using namespace std;

#define H 200000

int v[H+1];



int main(void){

    for(size_t i=0; i<H+1; i++){ v[i] = INT_MAX; }

    int h, w, n, x, y;

    scanf("%d %d %d\n", &h, &w, &n);

    for(int i=0; i<n; i++){

        scanf("%d %d\n", &x, &y);

        v[x] = y<v[x] ? y : v[x];

    }

    int right = 1;

    for(int x=1; x<h; x++){

        if(v[x+1]<right+1){

            printf("%d\n", x);

            return 0;

        }else if(v[x+1]>right+1){

            right++;

        }

    }

    printf("%d\n", h);

    return 0;

}
