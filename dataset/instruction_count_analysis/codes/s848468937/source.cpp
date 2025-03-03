#include <stdio.h>

#include <math.h>

int main(){

	

	int H, W, N;

	int max, min;

    scanf("%d%d%d", &H, &W, &N);



	if(H>W){

		printf("%.0f", ceil(N*1.0/H));

	} else {

		printf("%.0f", ceil(N*1.0/W));

	}

	return 0;	

}