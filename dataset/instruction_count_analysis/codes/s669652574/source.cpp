#include <cstdio>

#include <cstdint>



using namespace std;



int main()

{

	int32_t n, k, x, y;

	int32_t payment;

	

	scanf("%d\n%d\n%d\n%d\n", &n, &k, &x, &y);



	payment = n >= k ? k * x : n * x;

	payment += n >= k ? (n - k) * y : 0;



	printf("%d\n", payment);

}
