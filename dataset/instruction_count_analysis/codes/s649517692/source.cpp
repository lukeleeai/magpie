#include "stdc++.h"

using namespace std;



const int maxn = 1005;



char c3[10][10]={

	{'a','a','.'},

	{'.','.','a'},

	{'.','.','a'} 

};

char c4[10][10]={

    {'a','a','b','c'},

    {'d','d','b','c'},

    {'b','c','a','a'},

    {'b','c','d','d'}

};

char c5[10][10]={

    {'a','a','b','b','a'},

    {'b','c','c','.','a'},

    {'b','.','.','c','b'},

    {'a','.','.','c','b'},

    {'a','b','b','a','a'}

};

char c6[10][10] = {

	"aabc..",

	"ddbc..",

	"..aabc",

	"..ddbc",

	"bc..aa",

	"bc..dd"

};

char c7[10][10]={

    {'a','a','b','b','c','c','.'},

    {'d','d','.','d','d','.','a'},

    {'.','.','d','.','.','d','a'},

	{'.','.','d','.','.','d','b'},

	{'d','d','.','d','d','.','b'},

	{'.','.','d','.','.','d','c'},

	{'.','.','d','.','.','d','c'} 

};



char ans[maxn][maxn];



void print3(int x, int n)

{

	if (!n) return ;

	for (int i = 0; i < 3; ++i)

		for (int j = 0; j < 3; ++j)

			ans[x + i][x + j] = c3[i][j];

	return print3(x + 3, n - 3);

}



void print(int x, int n)

{

	if (!n) return ;

	if (n >= 8 || n == 4) {

		for (int i = 0; i < 4; ++i)

			for (int j = 0; j < 4; ++j)

				ans[x + i][x + j] = c4[i][j];

		return print(x + 4, n - 4);

	}

	if (n == 5) {

		for (int i = 0; i < 5; ++i)

			for (int j = 0; j < 5; ++j)

				ans[x + i][x + j] = c5[i][j];

		return print(x + 5, n - 5);

	}

	if (n == 6) {

		for (int i = 0; i < 6; ++i)

			for (int j = 0; j < 6; ++j)

				ans[x + i][x + j] = c6[i][j];

		return print(x + 6, n - 6);



	}

	if (n == 7) {

		for (int i = 0; i < 7; ++i)

			for (int j = 0; j < 7; ++j)

				ans[x + i][x + j] = c7[i][j];

		return print(x + 7, n - 7);

	}



}



int main()

{

	int n;

	scanf("%d", &n);

	if (n <= 2) return puts("-1"), 0;

	for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) ans[i][j] = '.';

	if (n % 3 == 0) print3(1, n);

	else print(1, n);

	for (int i = 1; i <= n; ++i) printf("%s\n", ans[i] + 1);

	return 0;

}
