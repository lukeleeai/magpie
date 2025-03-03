#include "stdc++.h"

using namespace std;

const long long mod = 1e9 + 7;

map<char , int>m;

char c;

int n;

long long sum;

int main(){

	cin >> n;

	for(int i = 1 ; i <= n ; i++){

		cin >> c;

		m[c]++; 

	}

	sum = 1;

	for(char i = 'a' ; i <= 'z' ; i++){

		sum *= (m[i] + 1);

		sum %= mod;

	}

	cout << sum - 1 << endl;

}