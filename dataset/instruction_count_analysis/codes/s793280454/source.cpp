#include <stdio.h>



using namespace std;



int main(){

	int n,q,tmp,left,right,count = 0;

	scanf("%d",&n);

	int S[n];

	for(int i = 0; i < n; i++){

		scanf("%d",&S[i]);

	}

	scanf("%d",&q);

	for(int i = 0; i < q; i++){

		scanf("%d",&tmp);

		left = 0;

		right = n-1;

		if(tmp == S[right]){

			count++;

		}else if(tmp == S[left]){

			count++;

		}else{

			if(tmp < S[right] && tmp > S[left]){

				while(left+1 < right){

					if(S[(left+right)/2] == tmp){

						count++;

						break;

					}else if(S[(left+right)/2] > tmp){

						right = (left+right)/2;

					}else{

						left = (left+right)/2;

					}

				}

			}

		}

	}

	printf("%d\n",count);

}