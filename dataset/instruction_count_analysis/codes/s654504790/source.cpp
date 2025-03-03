#include<cstdio>

#include<math.h>

#include <stdlib.h>

#define M 100000

using namespace std;





int n, m,l, p = 0 , result = 0;

int x[100010];



int main(){

	scanf("%d %d",&n,&m);

	x[0] = 0;

	for (int i = 1; i < n; i++){

		scanf("%d", &x[i]);

		x[i] += x[i - 1];

	}

	while (m--){

		scanf("%d", &l);

		result += abs(x[p + l] - x[p]);

		result %= M;

		p += l;

	}

	printf("%d\n", result);

}