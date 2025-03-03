#include<stdio.h>

int main(){

	int na;

	int a[10];

	int angka[3][3];

	int tanda[3][3];

	

	for(int i=0;i<3;i++){

		for(int j=0;j<3;j++){

			scanf("%d", &angka[i][j]);

		}

	}

	scanf("%d", &na);

	for(int c=0;c<na;c++){

		scanf("%d", &a[c]);

	for(int  l = 0 ; l < 3 ; l++ ) {

        for(int k = 0 ; k < 3 ; k++ ){

            if( a[c] == angka[l][k] ){

                tanda[l][k] = 1;

                }

            }

        }

    }



    if( (tanda[1][1] == 1 && tanda[2][2] == 1 && tanda[0][0] == 1  )

    || (tanda[2][0] == 1 && tanda[1][1] == 1 && tanda[0][2] == 1  )

    || (tanda[0][0] == 1 && tanda[0][1] == 1 && tanda[0][2] == 1  )

    || (tanda[1][0] == 1 && tanda[1][1] == 1 && tanda[1][2] == 1  )

    || (tanda[2][0] == 1 && tanda[2][1] == 1 && tanda[2][2] == 1  )

    || (tanda[0][0] == 1 && tanda[1][0] == 1 && tanda[2][0] == 1  )

    || (tanda[0][1] == 1 && tanda[1][1] == 1 && tanda[2][1] == 1  )

    || (tanda[0][2] == 1 && tanda[1][2] == 1 && tanda[2][2] == 1  )

    ) {

        printf("Yes\n");

    } else {

        printf("No\n");

    }

	return 0;

}