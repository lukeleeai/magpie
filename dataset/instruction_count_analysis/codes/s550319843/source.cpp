#include<stdio.h>

int main()

{

    int n, m, i, count, j;

    char arr[100][100];

    scanf("%d%d", &n, &m);

    for (i=0; i<n; i++){

        for (j=0; j<m; j++){

            scanf(" %c", &arr[i][j]);

        }

    }

    for (i=0; i<n; i++){

        for (j=0; j<m; j++){

                count = 0;

            if (arr[i][j] == '.'){

                if (i-1 >= 0 && arr[i-1][j] == '#') count ++; ///

                if (i-1 >= 0 && j-1 >= 0 && arr[i-1][j-1] == '#') count ++;

                if (i-1 >= 0 && j+1 < m && arr[i-1][j+1] == '#') count ++; ///

                if (j-1 >= 0 && arr[i][j-1] == '#') count ++; ///

                if (j+1 < m && arr[i][j+1] == '#') count ++;///

                if (i+1 < n && arr[i+1][j] == '#') count ++;///

                if (i+1 < n && j-1 >= 0 && arr[i+1][j-1] == '#') count ++;

                if (i+1 < n && j+1 < m && arr[i+1][j+1] == '#') count ++;



                arr[i][j] = count + '0' ;

            }

        }

    }





    for (i=0; i<n; i++){

        for (j=0; j<m; j++){

            printf("%c", arr[i][j]);

        }

        printf("\n");

    }



    return 0;

}
