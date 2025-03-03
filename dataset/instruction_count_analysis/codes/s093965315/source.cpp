#include <stdio.h>



int main (){

	char kalimat1[255];	// rng

	char kalimat2 [255]; // gorila

	char kalimat3 [255]; // apple

	scanf("%s", &kalimat1);

	scanf("%s", &kalimat2);

	scanf("%s", &kalimat3);	

	int lenght1=0;

	for (int i=0; kalimat1[i]!='\0'; i++){

		lenght1++;

	}

	int lenght2=0;

	for (int i=0; kalimat2[i]!='\0'; i++){

		lenght2++;

	}

	if (kalimat1[lenght1-1]==kalimat2[0]){

		if (kalimat2[lenght2-1]== kalimat3[0]){

			printf("YES");

		}

		else {

			printf("NO");

		}

	}

	else {

		printf("NO");

	}

	return 0;

}