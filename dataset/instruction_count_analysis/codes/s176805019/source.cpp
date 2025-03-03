#include <stdio.h>





int main(){

	int n;

	char str[50010];

	int x = 0;

	int ctr = 0;

	scanf("%d", &n);

	scanf("%s", str);



for(int i = 0;i < 10;i++){

	for(int j = 0;j<10;j++){

		for(int k = 0;k<10;k++){

			char test[] = {i,j,k};

		    x = 0;

			for(int a = 0;a <n;a++){

				if(str[a] - '0' == test[x]){

					x++;

				}

				if(x == 3){

					ctr++;

					break;

				}

			}

			

		}

	}

}

printf("%d", ctr);

	return 0;

}