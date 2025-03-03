#include <stdio.h>



int main()

{

	char w[1000];

	scanf("%s", w);

	int alp[26];

	for(int i=0; i<26; i++){

		alp[i]=0;

	}

	for(int i=0; w[i]!='\0'; i++){

		for(int j=97; j<123; j++){

			if(w[i]==j)

				alp[j-97]++;

		}

	}

	for(int i=0; i<26; i++){

		if(alp[i]%2!=0){

			printf("No\n");	return 0;

		}

	}



	printf("Yes\n");



	return 0;

}