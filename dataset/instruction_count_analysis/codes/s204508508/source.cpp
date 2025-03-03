#include <iostream>

#include <cstdio>

using namespace std;



inline int read() {

	int res = 0, flag = 1;

	char c = getchar();

	for(; !isdigit(c); c = getchar()) if(c == '-') flag = -1;

	for(; isdigit(c); c = getchar()) res = (res<<3) + (res<<1) + (c^48);

	return res * flag;

}



int h, w, d;

char s[4] = { 'R', 'Y', 'G', 'B' };



int main() {

	h = read(); w = read(); d = read();

	for(int i = 1; i <= h; i++, printf("\n"))

		for(int j = 1; j <= w; j++) {

			int x = i + j + w, y = i - j + w;

			printf("%c", s[(((x / d) & 1) * 2 + ((y / d) & 1))]);

		}

	return 0;

}