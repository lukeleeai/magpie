#include <stdio.h>



int main () {

	int n; 

	scanf("%d", &n);

	char string[10005];

	scanf("%s", string);

	for(int i = 0; string[i] != '\0'; i++) {

		string[i] += n;

		if(string[i] > 'Z') {

			string[i] = 64 + (string[i] - 'Z');

		}

	}

	printf("%s", string);

	

	return 0;

}