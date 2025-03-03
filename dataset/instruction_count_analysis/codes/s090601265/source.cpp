#include <cstdio>

#include <cstring>

#include <bitset>

#include <iostream>

#include <cmath>



using namespace std;



int n, m, D;

int a[30][30];

bitset <650> G[650];



inline int id(int x, int y) {

    return x * m + y;

}



bool Gauss(int equ, int var) {

    int col = 0, k;

    for(k = 0; k < equ && col < var; ++k, ++col) {

        if(!G[k][col]) {

            for(int i = k + 1; i < equ; ++i) if(G[i][col]) {

                G[k] ^= G[i];

                break;

            }

        }

        if(!G[k][col]) {

            k--;

            continue;

        }

        for(int i = k + 1; i < equ; ++i) 

			if(G[i][col]) 

				G[i] ^= G[k];

    }

    for(int i = k; i < equ; ++i) 

		if(G[i][var]) 

			return 0;

    return 1;

}



int main() {

    while(scanf("%d%d%d", &m, &n, &D)) {

        if(n == 0) break;

        for(int i = 0; i < n; ++i) 

			for(int j = 0; j < m; ++j) 

				scanf("%d", &a[i][j]);

        int U = n * m;

        for(int i = 0; i < U; ++i) G[i].reset();

        for(int i = 0; i < n; ++i) 

			for(int j = 0; j < m; ++j) {

	            int u = id(i, j);

	            G[u][u] = 1;

	            for(int x = 0; x < n; ++x) 

					for(int y = 0; y < m; ++y) {

		                if(abs(x - i) + abs(y - j) != D) continue;

		                G[id(x, y)][u] = 1;

		            }

        }

        for(int i = 0; i < n; ++i) 

			for(int j = 0; j < m; ++j) {

            if(!a[i][j]) continue;

            G[id(i, j)][n * m] = 1;

        }

        puts(Gauss(n * m, n * m) ? "1" : "0");

    }

    return 0;

}