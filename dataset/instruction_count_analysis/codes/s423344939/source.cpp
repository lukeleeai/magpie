#include <stdio.h>



int main (){

	int input;

	int temp=0;

	scanf ("%d",&input);

	int cek=input;

	while(input>0){

		temp+=input%10;

		input/=10;

	}

	//printf ("%d",temp);

	if(cek%temp==0){

		printf ("Yes\n");

	}else printf ("No\n");

}