/*

 *  低知能マン

 */



#include <stdio.h>

#include <stdlib.h>



int dp[11][2001];

int books[10][2001];

int book_nums[10];

int sell_prices[10][2001];



int greater_int(const void *a, const void *b) {

    return *(int*)b - *(int*)a;

}



int main() {

    int a, b, c, d;

    int n, k;

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



    for (a=0; a<10; a++) {

        for (b=0; b<k; b++) {

            int num;



            num = book_nums[a];

            if (num > k-b) {

                num = k-b;

            }



            for (c=0; c<=num; c++) {

                int val = dp[a][b] + sell_prices[a][c];

                int *p = &dp[a+1][b+c];



                if (*p < val) *p = val;

            }

        }

    }



    max = 0;

    for (a=0; a<=10; a++) {

        if (max < dp[a][k]) {

            max = dp[a][k];

        }

    }



    printf("%d\n", max);

}