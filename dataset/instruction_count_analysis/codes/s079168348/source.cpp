#include<stdio.h>



int main(){

	int a,b;

	char str[20];

	bool valids = true;

	

	scanf("%d %d", &a,&b);

	scanf("%s",str);

	

	if(str[a]!='-'){

	 valids = false;	

	}

	

	for (int i=0;str[i] !='\0';i++){

		if(i != a){

			if(str[i]<'0'){

				valids = false;

				break;

			}

		}

	}

	(valids) ? puts("Yes") : puts ("No");

	

	

	return 0;

}