#include "stdc++.h"

using namespace std;



int main(){

	

	int n;

	long long k;

	cin >> n >> k;

	

	vector<long long> v(101010);

	for(int i = 0 ; i < n ; i ++){

		int x;

		long long f;

		cin >> x >> f;

		v[x] += f;

	}

	

	long long s = 0;

	for(int i = 0 ; i < 101010 ; i ++){

		s += v[i];

		if(s >= k){

			cout << i << "\n";

			break;

		}

	}

	

	return 0;

}