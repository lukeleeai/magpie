#include <cstdio>

#include <algorithm>

#include <vector>



using namespace std;



typedef long long lint;



int main()

{

	int n;

	int a[100000];

	int t[300000];

	

	lint sum = 0;

	

	scanf("%d", &n);

	

	for (int i = 0; i < n; i++){

		scanf("%d", a + i);

		sum += a[i];

	}

	

	lint left = 0, right = sum / 3;

	

	while (left != right){

		lint mid = (left + right + 1) >> 1;

		lint sum2 = 0;

		

		int head = 0, tail = 0;

		for (; head < n; head++){

			while (sum2 < mid){

				sum2 += a[tail % n];

				tail++;

			}

			t[head] = tail - 1;

			t[head + n] = tail - 1 + n;

			t[head + n + n] = tail - 1 + n + n;

			sum2 -= a[head];

		}

		

		bool ok = false;

		for (head = 0; head < n; head++){

			if (t[t[t[head] + 1] + 1] - head + 1 <= n){

				ok = true;

				break;

			}

		}

		

		if (ok) left = mid;

		else right = mid - 1;

	}

	

	printf("%lld\n", left);

	

	return (0);

}