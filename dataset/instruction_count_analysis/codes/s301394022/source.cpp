#include "stdc++.h"

using namespace std;



const int C=100010, N=200010;

int a[N], b[N];



int main()

{

	int n;

	scanf ("%d", &n);

	a[C]++, b[C]++;

	

	while (n--){

		int l, r;

		scanf ("%d%d", &l, &r);

		l += C, r += C;

		a[l]++, b[r]++;

	}

	

	for (int i=N-2; i>=0; i--)

		a[i] += a[i+1];

		

	for (int i=1; i<N; i++)

		b[i] += b[i-1];

		

	long long ans=0;

	for (int i=0; i<N-1; i++)

		ans += min (b[i], a[i+1]);

		

		

	printf ("%lld\n", ans*2);

	return 0;

}