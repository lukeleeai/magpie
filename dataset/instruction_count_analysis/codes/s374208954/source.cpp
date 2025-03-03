/*

 *  ん？今何でもするって

 *  言ってないね

 */



#include <stdio.h>

#include <stdlib.h>



int dp[2 << 10][2001];

int books[10][2001];

int book_nums[10];

int sell_prices[10][2001];



int greater_int(const void *a, const void *b) {

    return *(int*)b - *(int*)a;

}



int main() {

    int a, b, c, d;

    int n, k;

    int book_bits;

    int max;



    scanf("%d %d", &n, &k);

    for (a=0; a<n; a++) {

        int c, g;

        int ind;



        scanf("%d %d", &c, &g);

        --g;

        ind = book_nums[g];

        books[g][ind] = c;

        ++book_nums[g];

    }

        

    for (a=0; a<10; a++) {

        qsort(books[a], book_nums[a], sizeof(int), greater_int);



        sell_prices[a][1] = books[a][0];

        for (b=2; b<=book_nums[a]; b++) {

            sell_prices[a][b] = sell_prices[a][b-1] + books[a][b-1] + (b-1)*2;

        }

    }



    book_bits = 1 << 10;

    for (a=0; a<k; a++) {

        for (b=0; b < book_bits; b++) {

            for (c=0; c<10; c++) {

                int num;



                if ((b >> c) & 1) continue;



                num = book_nums[c];

                if (num > k-a) {

                    num = k-a;

                }



                for (d=1; d<=num; d++) {

                    int val = dp[b][a] + sell_prices[c][d];

                    int *p = &dp[b | 1 << c][a+d];



                    if (*p < val) *p = val;

                }

            }

        }

    }



    max = 0;

    for (a=0; a < book_bits; a++) {

        if (max < dp[a][k]) {

            max = dp[a][k];

        }

    }



    printf("%d\n", max);

}