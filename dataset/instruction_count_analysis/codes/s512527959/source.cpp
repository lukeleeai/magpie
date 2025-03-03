//看题解了，重做 

#include <cstdio>

#include <cstring>

#include <algorithm>

using namespace std;

const int NN = 700;

int x, y, ans, n, m, q, a[NN][NN], b[NN][NN], c[NN][NN];



int main(){

	//freopen("atcoderabc106d.in", "r", stdin);

	

	scanf("%d%d%d", &n, &m, &q);

	for (int i=1; i<=m; i++) {

		scanf("%d%d", &x, &y);

		a[x][y]++;

	}

	

	for (int i=1; i<=n; i++)

		for (int j=i; j<=n; j++)

			for (int k=i; k<=j; k++) b[i][j] += a[i][k];  //b[i][j]表示以i为起点，终点在j及j之前的边的个数 

	

	for (int i=1; i<=n; i++)

		for (int j=i; j<=n; j++)

			for (int k=i; k<=j; k++) c[i][j] += b[k][j];  //c[i][j]即为所求 

	

	

	while (q--){

		scanf("%d%d", &x, &y);

		printf("%d\n", c[x][y]);

		//printf("%d %d %d\n", r[y] - l[x-1], r[y], l[x-1]);

	} 

	

	return 0;

} 