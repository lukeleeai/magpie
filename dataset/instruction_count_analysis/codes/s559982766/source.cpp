#include "stdc++.h"

using namespace std;



#define int long long

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }

template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }



signed main(){

	int n;

	cin >> n;



	int a[110];

	int sum = 0;



	for(int i = 0;i < n;i++){

		cin >> a[i];

		sum += a[i];

	}



	if(sum % 10 != 0){

		cout << sum << endl;

	}else{

		sort(a, a+n);

		for(int i = 0;i < n;i++){

			if(a[i] % 10 != 0){

				sum -= a[i];

				break;

			}

		}

		cout << (sum % 10 != 0 ? sum : 0) << endl;

	}



	return 0;

}
