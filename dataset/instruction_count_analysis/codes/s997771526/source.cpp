#include <cstdio>

char s[100009];

int main() {

	scanf("%s", s);

	int l = -1, r = -1;

	for(int i = 1; s[i]; i++) if(s[i - 1] == s[i]) l = i, r = i + 1;

	for(int i = 2; s[i]; i++) if(s[i - 2] == s[i]) l = i - 1, r = i + 1;

	printf("%d %d\n", l, r);

	return 0;

}