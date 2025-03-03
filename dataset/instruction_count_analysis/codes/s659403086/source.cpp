#include "stdc++.h"

using namespace std;

#define ll long long

#ifdef PAPITAS

	#define DEBUG 1

#else

	#define DEBUG 0

#endif

#define _DO_(x) if(DEBUG) x



int main()

{

	ios::sync_with_stdio(false);cin.tie(NULL);

	int n;

	cin >> n;

	int arr[n];

	ll a = 0, b = 0, sa = 0, sb = 0;

	for(int i = 0; i< n; i++){

		cin >> arr[i];

	}

	for(int i = 0; i < n; i++){

		sa += arr[i];

		sb += arr[i];

		if(i%2 == 0){

			if(sa <= 0){

				a += 1 - sa;

				sa = 1;

			}

			if(sb >= 0){

				b += sb + 1;

				sb = -1;

			}

		}else{

			if(sa >= 0){

				a += sa + 1;

				sa = -1;

			}

			if(sb <= 0){

				b += 1 - sb;

				sb = 1;

			}

		}

	}

	cout << min(a, b);

	return 0;

}


