#include<cstdio>

#include<algorithm>



using namespace std;



int main(){

	int n; scanf("%d", &n);

	for(int k = 1; k * (k + 1) / 2 <= n; k++) if(k * (k + 1) / 2 == n){

		int s[500][500] = {};

		for(int i = 0, p = 1; i < k; i++) for(int j = 0; j < k - i; j++) s[i][j + i] = p++;

		for(int i = 0; i < k; i++) for(int j = 0; j < k - i; j++) s[j + i + 1][i] = s[i][j + i];

		puts("Yes");

		printf("%d\n", k + 1);

		for(int i = 0; i < k + 1; i++){

			printf("%d ", k);

			for(int j = 0; j < k; j++) printf("%d%c", s[i][j], j + 1 == k ? '\n' : ' ');

		}

		return 0;

	}

	puts("No");

	return 0;

}