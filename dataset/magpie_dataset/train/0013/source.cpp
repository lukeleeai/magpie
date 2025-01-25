#include <cstdio>

using namespace std;



int a[4];

int c[8];

int k;



int calc(){

	int op = c[k++];

	int ret = 0;

	if(op >= 0){

		ret = op;

	}

	else if(op >= -3){

		int x = calc();

		int y = calc();

		if(op == -1){

			ret = x + y;

		}

		else if(op == -2){

			ret = x - y;

		}

		else{

			ret = x * y;

		}

	}

	else{

		throw 0;

	}

	return ret;

}



void print(){

	int op = c[k++];

	if(op >= 0){

		printf("%d", op);

	}

	else{

		char ch;

		if(op == -1){ ch = '+'; }

		else if(op == -2){ ch = '-'; }

		else{ ch = '*'; }



		putchar('(');

		print();

		printf(" %c ", ch);

		print();

		putchar(')');

	}

}



void solve(int i, int S, int oprem){

	if(i == 7){

		try{

			if(S == 0){

				k = 0;

				if(calc() == 10 && k == 7){

					k = 0;

					print();

					puts("");

					throw "";

				}

			}

		}catch(int){}

		return;

	}



	if(oprem > 0){

		for(int op = -1; op >= -3; --op){

			c[i] = op;

			solve(i + 1, S, oprem - 1);

		}

	}

	for(int j = 0; j < 4; ++j){

		if(S >> j & 1){

			c[i] = a[j];

			solve(i + 1, S ^ 1 << j, oprem);

		}

	}

}



int main(){

	while(1){

		for(int i = 0; i < 8; ++i){

			c[i] = -9;

		}

		for(int i = 0; i < 4; ++i){

			scanf("%d", &a[i]);

		}

		if(a[0] == 0){ break; }

		try{

			solve(0, 15, 3);

			puts("0");

		}catch(...){}

	}

}