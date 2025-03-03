#include<cstdio>

int main()

{

	char a, b;

	scanf("%c %c", &a, &b);

	a == b ? puts("=") : (a < b ? puts("<") : puts(">"));

}