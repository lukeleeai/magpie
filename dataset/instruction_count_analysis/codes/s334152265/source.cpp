#include"stdc++.h"



using namespace std;



int main()

{

	double w, h, c, d;

	cin >> w >> h >> c >> d;

	double ans;

	ans = (w * h) / 2.0;

	printf("%.6f ", ans);

	if(c * 2 == w && d * 2 == h)

		puts("1");

	else

		puts("0");

		

	return 0;

}