#include "stdc++.h"



using namespace std;



int a, b, c;



int main(){

	cin >> a >> b >> c;

	if(c >= a && c <= b){

		cout << "Yes" << endl;

		return 0;

	}

	cout << "No" << endl;

	return 0;

}