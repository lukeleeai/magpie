#include<iostream>

#include<string>

#include<iomanip>

#include<cmath>

#include<vector>

#include<algorithm>



using namespace std;



constexpr long long INF = (long long)1e18;



#define x first

#define y second



struct fast_io {

	fast_io(){

		std::cin.tie(nullptr);

		std::ios::sync_with_stdio(false);

	};

} fio;





vector<pair<long double,long double>> in;

	

long double cal(long double X, long double Y){

	long double maximum = 0;

	

	for(int i = 0; i < in.size(); i++){

		maximum = max(maximum, (in[i].x - X) * (in[i].x - X) + (in[i].y - Y) * (in[i].y - Y));

	}

	

	return sqrt(maximum);

}

	

long double ternary_search2(long double X, long double l = -100, long double h = 1100){

	long double y1, y2, minimum = INF;

	

	for(int i = 0; i < 50; i++){

		y1 = (2 * l + h) / 3;

		y2 = (l + 2 * h) / 3;

		

		long double f1 = cal(X, y1);

		long double f2 = cal(X, y2);

		

		minimum = min(minimum, f1);

		minimum = min(minimum, f2);

		

		if(f1 < f2) {

			h = y2;

		} else {

			l = y1;

		}

	}

	

	return minimum;

}



long double ternary_search(long double l = -100, long double h = 1100){

	long double x1, x2, minimum = INF;

	

	for(int i = 0; i < 50; i++){

		x1 = (2 * l + h) / 3;

		x2 = (l + 2 * h) / 3;

		

		long double f1 = ternary_search2(x1);

		long double f2 = ternary_search2(x2);



		minimum = min(minimum, f1);

		minimum = min(minimum, f2);

		

		if(f1 < f2) {

			h = x2;

		} else {

			l = x1;

		}

	}

	

	return minimum;

}



signed main(){

	cout<<fixed<<setprecision(10);

	

	int N;

	

	cin>>N;

	

	in.resize(N);

	

	for(int i = 0; i < N; i++){

		cin>>in[i].x>>in[i].y;

	}

	

	cout<<ternary_search()<<endl;

	

	return 0;

}