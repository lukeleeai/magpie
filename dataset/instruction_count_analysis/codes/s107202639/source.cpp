#include <stdio.h>



int main(){

	char A, B;

	

	scanf("%c\n %c", &A, &B);

	

	if (A== '1'&&B=='2'){

		printf("3");

	}else if (A=='1'&&B=='3'){

		printf("2");

	}else if(A=='3'&&B=='1'){

		printf("2");

	}else if (A=='3'&&B=='2'){

		printf("1");

	}else if (A=='2'&&B=='1'){

		printf("3");

	}else if (A=='2'&&B=='3'){

		printf("1");

	}

	

	

	

	

	return 0;

}