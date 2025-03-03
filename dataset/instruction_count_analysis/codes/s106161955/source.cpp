#include "stdc++.h"

using namespace std;



const int N = 300000;

#define debug(a) cout << #a << " = " << a << endl;

#define pii pair<int,int>



int A[1000000];

int B[1000000];





int main(int argc, char const *argv[])

{

	int n;

	scanf("%d",&n);

	long long  ans = 0;

	for(int i = 0; i <= n;i++)scanf("%d",&A[i]);

	for(int i = 0; i < n;i++)scanf("%d",&B[i]);

	for(int i = 0; i < n;i++){

		int hala = min(A[i],B[i]);

		ans += hala;

		B[i] -= hala;

		A[i] -= hala;



		hala = min(A[i+1],B[i]);

		ans += hala;

		B[i] -= hala;

		A[i+1] -= hala;

	}

	printf("%lld\n",ans );

	

	

	return 0;

}