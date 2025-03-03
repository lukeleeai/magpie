//#include"stdc++.h"

#include<cstdio>

#include<algorithm>

using namespace std;

 

 

const int cm = 1 << 17;

char cn[cm], * ci = cn + cm, ct;

inline char getcha() {

	if (ci - cn == cm) { fread_unlocked(cn, 1, cm, stdin); ci = cn; }

	return *ci++;

}

inline int getint() {

	int A = 0;

	if (ci - cn + 16 > cm) while ((ct = getcha()) >= '0') A = A * 10 + ct - '0';

	else while ((ct = *ci++) >= '0') A = A * 10 + ct - '0';

	return A;

}



int main() {



	int max = 2000000000;

	int n = getint();

	for(int i = 0; i < n; i++){

		int a = getint();

        int b = getint();

		if(a+b < max) {

			max = a+b;

		}

	}

	printf("%lld", max);

	return 0;

}
