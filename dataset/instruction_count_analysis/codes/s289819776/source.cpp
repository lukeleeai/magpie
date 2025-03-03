#include <stdio.h>

#include <string.h>



int main() {

	int n;

	char s[10005];



	scanf("%d", &n);

	scanf("%s", s);



	for(int i = 0; s[i] != '\0'; i++) {

		s[i] = 'A' + (s[i] - 'A' + n) % 26;

	}



	puts(s);



	return 0;

}