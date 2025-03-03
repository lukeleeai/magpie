#include <cstdio>



int main() {

	char ch;

	scanf("%c", &ch);

	if (ch == 'a' || ch == 'o' || ch == 'e' || ch == 'i' || ch == 'u')

		puts("vowel");

	else puts("consonant");

	return 0;

}
