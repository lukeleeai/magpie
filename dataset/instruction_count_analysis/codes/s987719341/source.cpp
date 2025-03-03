#include<stdio.h>

using namespace std;



const int MAX = 100000;



int parent(int table[], int child) {

	if (table[child] == -1)return child;

	return table[child] = parent(table, table[child]);

}



int main() {

	int n, m, q;

	int table[MAX];



	scanf("%d %d", &n, &m);



	for (int i = 0; i < n; i++)table[i] = -1;

	for (int i = 0; i < m; i++) {

		int s, t;

		scanf("%d %d", &s, &t);

		

		int ps = parent(table, s);

		int pt = parent(table, t);

		if (ps != pt) {

			table[ps] = pt;

		}

	}



	scanf("%d", &q);



	for (int i = 0; i < q; i++) {

		int s, t;

		

		scanf("%d %d", &s, &t);



		int ps = parent(table, s);

		int pt = parent(table, t);



		if (ps == pt) {

			printf("yes\n");

		}

		else {

			printf("no\n");

		}

	}

	return 0;

}