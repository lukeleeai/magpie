#include <cstdio>



char str[200010];



int main() {

	scanf("%s", str);

	for (int i = 0; str[i]; ++i)

		if (str[i] == '?')

			str[i] = 'D';

	puts(str);

	return 0;

}
