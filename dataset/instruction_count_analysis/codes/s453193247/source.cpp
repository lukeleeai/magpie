#include <stdio.h>

#define N 13

#define M 1000000007

#define L 10



char s[111111];

int g[N][L];



int main()

{		

	long long d[2][N] = {1};

	int i, j, x, p0, p1;

	

	for(i = x = 0; i < N; i++, x += L){

		for(j = 0; j < L; j++){

			g[i][j] = (x + j) % N;

		}

	}

	

	scanf("%s", s);

	for(i = 0, p0 = 0, p1 = 1; s[i]; i++, p0 = !p0, p1 = !p1){

		if(s[i] != '?'){

			x = s[i] - 48;

			for(j = 0; j < N; j++){

				d[p1][g[j][x]] = d[p0][j];

			}

		}

		else{

			for(j = 0; j < N; j++) d[p1][j] = 0;

			for(x = 0; x < L; x++){

				for(j = 0; j < N; j++) d[p1][g[j][x]] += d[p0][j]; 

			}

			for(j = 0; j < N; j++) d[p1][j] %= M;

		}

	}

	printf("%lld\n", d[p0][5]);

		

				

	return 0;

}