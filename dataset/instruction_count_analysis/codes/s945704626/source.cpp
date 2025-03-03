#include <cstdio>



#define NMAX 200010



int a[NMAX];

int imos[NMAX];



void reset(int n) {

    for(int i = 0; i < n; i++) imos[i] = 0;

}



int max(int a, int b) {

    if(a > b) return a;

    else return b;

}



int min(int a, int b) {

    if(a > b) return b;

    else return a;

}



int main(){

    int n, k;

    scanf("%d %d", &n, &k);

    for(int i = 0; i < n; i++) scanf("%d", &a[i]);



    for(int itr = 0; itr < k; itr++) {

        bool f = false;

        reset(n+1);

        for(int i = 0; i < n; i++){

            if(a[i] != n) f = true;

            imos[max(0, i - a[i])]++;

            imos[min(n, i + a[i] + 1)]--;

        }

        int acc = 0;

        for(int i = 0; i < n; i++){

            acc += imos[i];

            a[i] = acc;

        }

        if(!f) break;

    }



    for(int i = 0; i < n; i++) printf("%d\n", a[i]);

    return 0;

}
