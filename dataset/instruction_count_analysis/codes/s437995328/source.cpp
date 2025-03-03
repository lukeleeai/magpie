#include<cstdio>

#include<algorithm>



using namespace std;



int n,mon;



int main()

{

	scanf("%d %d",&n,&mon);

	mon /= 1000;//10 5 1

	for(int i = 0;i <= mon / 10; i++){//10

		for(int j = 0;j <= mon / 5; j++){//5

			if((mon - (i * 10 + j * 5)) >= 0 && (mon - (i * 10 + j * 5)) + i + j == n) {

				printf("%d %d %d\n",i,j,mon - (i * 10 + j * 5));

				return 0;

			}

		}

	}

	printf("-1 -1 -1\n");

}