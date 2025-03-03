#include<stdio.h>



int main(){

	

	int l,r,d,x;

	int count=0;

	scanf("%d %d %d",&l,&r,&d);



	for(int i=0;i<=r;i++){

		x = d*i;

		if(x>=l && x<=r){

			count++;

		}

	}



	printf("%d",count);





	

	return 0;

}
