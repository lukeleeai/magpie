#include <cstdio>

#include <algorithm>

using namespace std;



int main(){

	int N,ant[200000],i;

	scanf("%d",&N);

	for(i=0;i<N;i++){

		scanf("%d",&ant[i]);

	}

	sort(ant,ant+N);

	for(i=1;i<N;i++){

		if(ant[i]==ant[i-1]){

			printf("NO\n");

			return 0;

		}

	}

	printf("YES\n");

	return 0;

}
