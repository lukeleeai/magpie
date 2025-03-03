#include <cstdio>

#include <algorithm>



using namespace std;



int main()

{

	long long P, Q, C, A[500000];



	int N;



	scanf("%d", &N);



	scanf("%lld", &P);

	scanf("%lld", &Q);



	long long zenbugaishoku = 0;



	for (int i = 0; i < N; i++)

	{

		scanf("%lld", &C);



		zenbugaishoku += C;



		A[i] = C - (Q - i) * P;

	}



	sort(A, A + N);



	long long Answer = zenbugaishoku;



	long long sum = zenbugaishoku;



	for (int i = 0; i < N; i++)

	{

		sum -= A[i];



		sum += 2 * i * P;



		Answer = max(sum, Answer);

	}



	printf("%lld\n", Answer);



	return 0;

}