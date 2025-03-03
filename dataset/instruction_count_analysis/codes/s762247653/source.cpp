#include <stdio.h>

int main (){

	

	int health,damage,attacks;

	scanf ("%d",&health);



	scanf ("%d",&damage);

	

	attacks= health/damage; 

	



 	(attacks * damage>=health)?  printf("%d", attacks):printf ("%d",++attacks );

	



	

	return 0;

}
