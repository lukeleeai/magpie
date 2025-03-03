#include <cstdio>



void ToOctalNumber(int n){

	if(n){

		ToOctalNumber(n >> 3);

		printf("%d",(n&7)<4?n&7:(n&7)==4?5:(n&7)+2);

	}

}



int main(){

	int n;

	while(scanf("%d",&n),n){

		ToOctalNumber(n);

		puts("");

	}

}