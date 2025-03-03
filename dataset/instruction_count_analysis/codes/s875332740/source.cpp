#include "stdc++.h"

#include <cmath>

using namespace std;

typedef long long ll;



ll tc, bil, r;





int main(){

	scanf("%lld", &tc);

	map<string, int> m;

	ll jaw = 0;

	for(int k = 1; k<= tc; k++){

		string s;

		cin >> s;

		if(m[s] == 0){

			jaw++;

			m[s]++;

		}

	}

	printf("%lld\n",jaw);

}