#include<iostream>

using namespace std;

int main()

{

	int n;

	while(cin>>n){

		int sum=0;

		int f=n;

		if(n>1000000000||n<1){

			break;

		}

		while(n){

			sum+=n%10;

			n/=10;

		}

		//cout<<sum<<endl;

		if(f%sum==0){

			cout<<"Yes"<<endl; 

		}

		else {

			cout<<"No"<<endl;

		}

	}

	return 0;

}