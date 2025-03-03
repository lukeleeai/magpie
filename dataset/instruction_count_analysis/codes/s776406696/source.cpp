#include<stdio.h>



int main(){

	int arr[3][3], flag[3][3] = {0};

	for(int i = 0; i < 3; i++){

		for(int j = 0; j < 3; j++){

			scanf("%d", &arr[i][j]);

		}

	}

	int n;

	scanf("%d", &n);

	int brr[n];

	for(int i = 0; i < n; i++){

		scanf("%d", &brr[i]);

		for(int j = 0; j < 3; j++){

			for(int k = 0; k < 3; k++){

				if(arr[j][k] == brr[i]){

					flag[j][k] = 1;

				}

			}

		}

	}

	int check = 0;

	for(int i = 0; i < 3; i++){

		if(flag[i][0] && flag[i][1] && flag[i][2]){

			check = 1;

		}

	}

	for(int i = 0; i < 3; i++){

		if(flag[0][i] && flag[1][i] && flag[2][i]){

			check = 1;

		}

	}

	if(flag[0][0] && flag[1][1] && flag[2][2]){

		check = 1;

	}

	if(flag[0][2] && flag[1][1] && flag[2][0]){

		check = 1;

	}

	(check) ? puts("Yes") : puts("No");

	return 0;

}
