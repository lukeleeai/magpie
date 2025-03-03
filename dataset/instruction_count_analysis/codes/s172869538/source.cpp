#include <stdio.h>



int main(){

	int a,b,c;

	int sum=0;

	scanf ("%d %d %d", &c,&a,&b);

	for(int i=1;i<=c;i++){

        int x = 0;

        int y = i;

        while(y != 0){

            x += (y%10);

            y = y / 10;

        }

        if(x >= a && x <= b){

        sum += i;

    }

}

	printf("%d",sum);  

    return 0;

}