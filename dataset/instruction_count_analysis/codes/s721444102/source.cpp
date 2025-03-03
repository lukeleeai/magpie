#include<stdio.h>

	int main(){

		int n;

		

		scanf("%d",&n);

		char str[n];

		

		scanf("%s",str);

		int counter =0;

		int max = 0;

		for(int j =0 ; j<n ;j++){



			if(str[j]=='I'){

				counter++;

				if(counter>= max){

				max=counter;

				}

			}

			else {

				counter--;

			}

		}

		printf("%d",max);

	

	return 0;

}