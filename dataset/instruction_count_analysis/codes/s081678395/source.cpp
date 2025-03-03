#include<stdio.h>



int main(){

	

	char board[5][5];

	

	for(int i=0;i<2;i++){

		for(int j=0;j<3;j++){

			scanf("%c",&board[i][j]);

		}

		getchar();

	}

	

	if(board[0][0] == board[1][2] && board[1][0] == board[0][2] && board[0][1] == board[1][1]){

		printf("YES\n");

	}else{

		printf("NO\n");

	}

	

}