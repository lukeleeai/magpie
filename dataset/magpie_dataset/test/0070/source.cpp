#include"stdc++.h"

using namespace std;

int main(){

	string A;

	int k,n;

	cin >>k;

	cin >> A;

	n=A.length();

	k=min(k,n);

	for(int i=0;i<k;i++)

		cout << A[i];

	if(min(k,n)-n){

		cout << "...";

	}

	cout << endl;

}
