#include <iostream>

#include<cstdio>

using namespace std;



int main() {

	int n;

	while(scanf("%d",&n),n!=0){

		int x=0;

		for(int i=0;i<n*(n-1)/2;i=i+1){

			int c;

			cin >> c;

			x = x + c;

		}

		cout << x/(n-1) << endl;

	}

	// your code goes here

	return 0;

}