#include<stdio.h>

int h,w;

char a[105][105];

int main(){

	scanf("%d %d ",&h, &w);

	if(h == 0 && w == 0){

		printf("#");

		return 0;

	}

	for( int i = 1 ; i <= h ; i++){

		scanf("%s",a[i] + 1);

		a[i][0] = '#';

		a[i][w + 1] = '#';

		a[i][w + 2] = '\0';

	}

	for( int i = 0 ; i <= h+1 ; i++){

		if(i != 0 && i != h+1)

			for(int j = 0 ; a[i][j] != '\0'; j++)

			printf("%c",a[i][j]);

		else

			for(int j = 0 ; j <= w+1 ; j++)printf("#");



		if(i != h+1)printf("\n");

	}

}
