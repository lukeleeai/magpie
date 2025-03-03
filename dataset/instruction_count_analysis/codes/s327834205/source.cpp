#include<stdio.h>



int main(){

	int n[3][3];

	int bing[9];

	int ctr[3][3]={0};

	for(int i=0; i<3; i++){

		for(int j=0; j<3; j++){

			scanf("%d", &n[i][j]);

		}

	}

	int tc;

	scanf("%d", &tc);

	for(int i; i<tc; i++){

		scanf("%d", &bing[i]);

		if(bing[i] == n[0][0]){

			ctr[0][0]++;

		}

		else if(bing[i] == n[0][1]){

			ctr[0][1]++;

		}

		else if(bing[i] == n[0][2]){

			ctr[0][2]++;

		}

		else if(bing[i] == n[1][0]){

			ctr[1][0]++;

		}

		else if(bing[i] == n[1][1]){

			ctr[1][1]++;

		}

		else if(bing[i] == n[1][2]){

			ctr[1][2]++;

		}

		else if(bing[i] == n[2][0]){

			ctr[2][0]++;

		}

		else if(bing[i] == n[2][1]){

			ctr[2][1]++;

		}

		else if(bing[i] == n[2][2]){

			ctr[2][2]++;

		}

	}

	if(ctr[0][0]>0 && ctr[0][1]>0 && ctr[0][2]>0){

		printf("Yes\n");

	}

	else if(ctr[1][0]>0 && ctr[1][1]>0 && ctr[1][2]>0){

		printf("Yes\n");

	}

	else if(ctr[2][0]>0 && ctr[2][1]>0 && ctr[2][2]>0){

		printf("Yes\n");

	}

	else if(ctr[0][0]>0 && ctr[1][0]>0 && ctr[2][0]>0){

		printf("Yes\n");

	}

	else if(ctr[0][1]>0 && ctr[1][1]>0 && ctr[2][1]>0){

		printf("Yes\n");

	}

	else if(ctr[0][2]>0 && ctr[1][2]>0 && ctr[2][2]>0){

		printf("Yes\n");

	}

	else if(ctr[0][0]>0 && ctr[1][1]>0 && ctr[2][2]>0){

		printf("Yes\n");

	}

	else if(ctr[0][2]>0 && ctr[1][1]>0 && ctr[2][0]>0){

		printf("Yes\n");

	}

	else{

		printf("No\n");

	}

	return 0;

}