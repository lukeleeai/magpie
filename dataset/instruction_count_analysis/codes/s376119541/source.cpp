#include <iostream>

#include <stdio.h>



#define S_SIZE 100000



using namespace std;



int S[S_SIZE];



bool isContain(int left,int right,int number){

	int m = (left + right)/2;

	if(left == right){

		if(S[m] == number){

			return true;

		}else{

			return false;

		}

	}else if(S[m] == number){

		return true;

	}else if(S[m] < number){

		return isContain(m + 1,right,number);

	}else{	//S[m] > number

		if(right - left == 1){

			return isContain(left,m,number);

		}else{

			return isContain(left,m-1,number);

		}

	}

}



int main(){



	int tmp;

	int n,q,count = 0;



	scanf("%d",&n);

	for(int i = 0; i < n; i++){

		scanf("%d",&S[i]);

	}



	int left,right;

	scanf("%d",&q);

	for(int i = 0; i < q; i++){

		scanf("%d",&tmp);

		left = 0;

		right = n-1;

		if(isContain(left,right,tmp))

		{

			count++;

		}

	}

	printf("%d\n",count);

}