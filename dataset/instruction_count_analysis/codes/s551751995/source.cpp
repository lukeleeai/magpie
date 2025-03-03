#include<iostream>

using namespace std;



const int MAX = 100000;



int main() {

	int N;

	int64_t K;

	cin >> N >> K;



	int64_t num[MAX+1] = {0};



	for (int i = 0; i < N; i++) {

		int a, b;

		cin >> a >> b;



		num[a] += b;

	}



	for (int i = 1; i <= MAX; i++) {

		K -= num[i];



		if (K <= 0) {

			cout << i << endl;

			break;

		}

	}

}

		
