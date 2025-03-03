#include"stdio.h"

using namespace std;

int main(){

	int i;char c;

	for(i=1;i<=19;i++){

		c=getchar();

		if(c!=',') printf("%c",c);

		else printf(" ");

	}

	printf("\n");

	return 0;

}