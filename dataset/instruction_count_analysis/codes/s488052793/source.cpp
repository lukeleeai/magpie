#include"stdc++.h"



using namespace std;

#define repeat(i, n) for(int i = 0; i < (n); i++)





int main()

{

	int N,M;

	cin >> N >> M;



	int A[100001] = {};

	long long B[100001] = {};

	map<int, int> MAP;



	repeat(i, N) {

		cin >> A[i];

		B[i + 1] = B[i] + A[i];



		B[i + 1] %= M;



		MAP[(int)B[i + 1]]++;

	}

	MAP[0]++;



	long long result = 0;



	for (auto ITR : MAP){

		result += 1ll * ITR.second * (ITR.second - 1) / 2;

	}





	//出力

	cout << result << endl;













	return 0;

}