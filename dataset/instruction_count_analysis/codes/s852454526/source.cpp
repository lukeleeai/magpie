#include<cstdio>

int main(){

	int n,m;

	int cot = 0;

	scanf("%d %d",&n,&m);

	m /= 1000;

	if(n > m || n * 10 < m) printf("-1 -1 -1");

	else {

		if(n * 10 == m) printf("%d 0 0\n",n);

		else if(n * 5 == m) printf("0 %d 0\n",n);

		else if(n == m) printf("0 0 %d\n",n);

		else {

			for(int x = 0; x <= n; x++){

				for(int y = 0; y <= n; y++){

					if((10 * x + 5 * y + (n - x - y) == m) && ((n - x - y) >= 0)) {printf("%d %d %d\n",x,y,n-x-y); return 0;}

					else cot++;

				}

			}

			if(cot == (n + 1) * (n + 1)) printf("-1 -1 -1");

		}

	}

}
