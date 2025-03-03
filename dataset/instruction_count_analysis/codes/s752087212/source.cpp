#include<stdio.h>



int main()

{

	char s[10];

	scanf("%s", &s);

//ex : coffee berarti f pertama = berindeks 2

					//f kedua = index 3

					//e pertama= index 4

					//e kedua = index ke 5

					//c adalah index ke 0

	if (s[2]==s[3]&& s[4]==s[5]){

		puts("Yes");

		

	}	else

		puts("No");

	

	return 0;



}