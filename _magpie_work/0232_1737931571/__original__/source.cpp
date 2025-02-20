#include <iostream>

#include <cstdio>

#include <cstring>

#include <cmath>

#include <cstdlib>

#include <climits>

#include <algorithm>

#include <vector>

#include <map>

#include <set>

#include <queue>

#include <numeric>

#include <sstream>

#include <string>

using namespace std;

typedef long long lint;

int cn[20];

int main()

{

	lint L;

	while(cin>>L,L){

		int k = 0;

		for(int i = 2; (lint)i*i <= L; i++){

			if(L%i == 0){

				cn[k] = 0;

				while(L%i == 0){

					L /= i;

					cn[k]++;

				}

				k++;

			}

		}

		if(L>1) cn[k++] = 1;

		lint ans = 1;

		for(int i = 0; i < k; i++){

			ans *= (2*cn[i]+1);

		}

		cout<<(ans/2+1)<<endl;

	}

	return 0;

}