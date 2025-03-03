#include"stdc++.h"

using namespace std;

int main(void){

	int n;

	int t,a;

	int h[1001];

	cin>>n;

	cin>>t>>a;

	for(int i=1;i<=n;i++){

		cin>>h[i];

	}

	int MIN;

	int x=INT_MAX;

	int z;

	a*=1000;

	for(int i=1;i<=n;i++){

		MIN=t*1000-h[i]*6;

		if(x>abs(MIN-a)){

			x=abs(MIN-a);

			z=i;

		}

	}

	cout<<z<<endl;

	return 0;

}