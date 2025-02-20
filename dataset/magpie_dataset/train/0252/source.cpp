#include <cstdio>

#include <algorithm>

#include <cmath>

using namespace std;



// 入力

int N;

double x[101], y[101], v[101];



// 2点間の距離

double dist(double x1, double y1, double x2, double y2){

	return sqrt( (x1-x2) * (x1-x2) + (y1-y2) * (y1-y2) );

}



// (x_,y_) => (x[i],y[i]) (0 <= i < N)の移動時間で最大のものを返す.

double g(double x_, double y_){

	double t = 0;

	for(int i=0 ; i < N ; i++ ){

		double d = dist( x_ , y_ , x[i] , y[i]);

		t = max( t , d / v[i] );

	}

	return t;

}



// x が与えられた時, y について三分探索 (0 <= y <= 100)

double f(double x, double low=0, double high=100){

	for (int i = 0 ; i < 100 ; i++ ){

		double a = (low * 2 + high) / 3;

		double b = (low + high * 2) / 3;

		if( g(x, a) < g(x, b) ){

			high = b;

		}else{

			low = a;

		}

	}

	return g(x, (low + high) / 2);

}



// x について三分探索 (0 <= x <= 100)

double search(double low=0, double high=100){

	for (int i = 0 ; i < 100 ; i++ ){

		double a = (low * 2 + high) / 3;

		double b = (low + high * 2) / 3;

		if( f(a) < f(b) ){

			high = b;

		}else{

			low = a;

		}

	}

	return f((low + high) / 2) ;

}



int main(){

	while( scanf("%d", &N) ){

		if( N == 0 ) break;

		

		for(int i=0 ; i <N ; i++ ){

			scanf("%lf %lf %lf", &x[i], &y[i], &v[i]);

		}

		double ans = search();

		printf("%.8f\n", ans);

	}

}