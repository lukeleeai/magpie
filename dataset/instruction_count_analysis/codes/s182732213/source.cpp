#include <stdio.h>



int main(){

	int n;

	scanf("%d", &n);

	char inp[10001];

	scanf("%s", inp);



	for(int i=0; inp[i]!='\0';i++){

		if(inp[i]+n>'Z'){

			inp[i]=inp[i]+n-26;

		}else{

			inp[i]+=n;

		}

	}

	printf("%s", inp);

	return 0;

}