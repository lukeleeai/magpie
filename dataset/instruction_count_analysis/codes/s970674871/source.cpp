#include <stdio.h>







int main()

{

	

	int A,B,sum,mult,sub;

	

	scanf("%d %d", &A, &B);

	

	sum = A + B;

	mult = A * B;

	sub = A - B;

	

	if (sum > mult && sum > sub){

		printf("%d", sum);

	}

	else if(mult > sum && mult > sub){

		printf("%d", mult);

	}

	else if(sub > sum && sub > mult){

		printf("%d", sub);

	}

	else{

		printf("%d", sum);

	}



	

	return 0;

}