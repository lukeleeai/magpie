#include <iostream>

using namespace std;





int main() {



	int judge[1000000];

	for(int k=0;k<1000000;k++)judge[k]=1;

	int n,sum;

	

	while(cin>>n){

		if(n==0||n==1){

			sum = 0;

		}else{

			sum = 1;

			for(int i=3;i<n+1;i+=2){

				if (judge[i]==1){

					sum++;

					for(int j=2;j<=n/i;j++)

						judge[i*j] = 0;

				}	

			}

		}

		

		cout << sum <<endl;

	}



	return 0;

}