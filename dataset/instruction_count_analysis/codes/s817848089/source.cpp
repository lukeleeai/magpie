#include <vector>

#include <iostream>

#include <algorithm>



using namespace std;



int main()

{

	long long N, P, Q; vector<long long> C;



	cin >> N >> P >> Q;



	C = vector<long long>(N);



	long long zenbugaishoku = 0;



	for (int i = 0; i < N; i++)

	{

		cin >> C[i];



		zenbugaishoku += C[i];

	}

	

	vector<long long> A(N);



	for (int i = 0; i < N; i++)

	{

		A[i] = C[i] - (Q - i) * P;

	}



	sort(A.begin(), A.end());



	long long Answer = zenbugaishoku;



	long long sum = zenbugaishoku;



	for (int i = 0; i < N; i++)

	{

		sum -= A[i];



		sum += 2 * i * P;



		Answer = max(sum, Answer);

	}



	cout << Answer << endl;



	return 0;

}