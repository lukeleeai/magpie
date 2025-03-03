#include <cstdio>

#include <cstring>



int main() {

	char str[1010];

	scanf("%s", str);

	puts(strstr(str, "AC") ? "Yes" : "No");

	return 0;

}
