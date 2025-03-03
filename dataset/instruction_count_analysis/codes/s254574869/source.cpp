#include <iostream>



using namespace std;



int main()

{

	int32_t n, k, x, y;

	int32_t payment;

	

	cin >> n >> k >> x >> y;



	payment = n >= k ? k * x : n * x;

	payment += n >= k ? (n - k) * y : 0;



	cout << payment << endl;

}
