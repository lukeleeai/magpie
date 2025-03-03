#include <stdio.h>

#include <string.h>



int main(){

	int H1, M1, H2, M2, K; 

	scanf ("%d %d %d %d %d", &H1, &M1, &H2, &M2, &K);

	int Tot1 = (H1*60)+M1;

	int Tot2 = (H2*60)+M2;

	int Time = (Tot2 - Tot1) - K;

	printf ("%d", Time); 







return 0;

}