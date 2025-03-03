#include<iostream>

#include<math.h>

using namespace std;

int a[105];

int main(){

	int n;

	cin>>n;

	int tot = 0;

	for(int i = 0;i<n;i++){

		cin>>a[i]; tot+=a[i];

	}

	int temp = 0;

	int minim = 1e9;

	for(int i = 0;i<n;i++){

		temp+=a[i];

		if(abs(temp - (tot-temp)) < minim){

			minim = abs(temp - (tot-temp));

		}

	}

	cout<<minim<<"\n";

	return 0;

}