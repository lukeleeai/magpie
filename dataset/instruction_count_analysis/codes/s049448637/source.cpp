#include <iostream>

#include <algorithm>

using namespace std;



double mysqrt(double x){

	double l = 0 , r = x ;

	for(int i = 0 ; i < 64 ; i++){

		double m = (l+r)/2.0;

		if(m * m < x){

			l = m;

		}else{

			r = m;

		}

	}

	return l;

}





int main(){

	int p,n;

	while(cin >> p >> n , n){

		double sp = mysqrt(p);

		int a1 = 0 , b1 = 1 , a2 = p , b2 = 1;

		

		for(int i = 1 ; i <= n ; i++){

			int o = (int)(sp * i);

			for(int j = 0 ; j <= 1 ; j++){

				int w = o + j;

				if(__gcd(i,w) == 1 && w >= 0 && w <= n){

					if( (double)w/i < sp &&  a1*i < w*b1){

						a1 = w;

						b1 = i;

					}

					if((double)w/i > sp && a2*i > w*b2){

						a2 = w;

						b2 = i;

					}

				}

			}

		}



		cout << a2<< "/" << b2 << " " << a1 << "/" << b1 << endl;

	}

}