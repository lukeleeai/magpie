#include<iostream>

#include<cmath>

#include<iomanip>



using namespace std;



typedef long long ll;

typedef long double ld;



int main(){

	int N, K; cin >> N >> K;

	double ans = 0;



	for(int i = 1; i <= N; ++i){

		double tmp = 1.0/N;

		int now = i, m = 0;

		while(now<K){

			now*=2;

			tmp/=2;

		}

		// tmp = 1.0 / pow(2, m) / (double)N;



		ans += tmp;

	}



	cout << fixed << setprecision(12) << ans << endl;



	return 0;

}
