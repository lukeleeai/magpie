#include <stdio.h>



int main(){

	int jamb;

	int menitb;

	int jamt;

	int menitt;

	int belajar;

	int rumus;

	scanf("%d %d %d %d %d", &jamb,&menitb,&jamt,&menitt,&belajar);

	rumus=((jamt*60)+menitt)-((jamb*60)+menitb)-belajar;

	printf("%d", rumus);

	

	

	return 0;

}