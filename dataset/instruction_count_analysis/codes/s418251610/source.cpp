#include<iostream>

#include<cmath>

#include<iomanip>

using namespace std;



int main(){

	int N, K; cin >> N >> K;

	long double ans = 0;

	long double bunsu = 0, bunsi = 0;

	int p1 = 0;



	for(int i = 1; i <= N; ++i){

		int p = 1, tmp = i*2;

		for(int j = 0; j < 20; ++j){

			if(tmp >= K) break;

			tmp *= 2;

			p++;

		}



		if(i > K-1) p = 0;

		if(i ==1) p1 = p;

		

		// cout << p << endl;



		bunsu += (long double)pow(10, 13) / pow(2, p);

		bunsi += pow(2, p1-p);

	}



	// cout << bunsi << endl;



	bunsi /= (long double)pow(2, p1);

	bunsi /= (long double)N;



	// bunsu /= (long double)N;

	// ans = (long double)bunsu / pow(10, 13);



	cout << fixed << setprecision(10) << bunsi << endl;



	return 0;

}
