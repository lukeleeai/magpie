#include <stdio.h>

#include <string.h>



int main(){

	char str[25];

	scanf("%s", &str);

	

	str[5] = ' ';

	str[13] = ' ';

	

	printf("%s", str);

	

	return 0;

}