#include "stdc++.h"



const int MAX_N = 300000;



int main() {

	int N;

	std::string S;

	std::cin >> N >> S;



	std::vector<int> left(MAX_N), right(MAX_N), cost(MAX_N);

	int cnt;



	cnt = 0;

	for(int i = 0; i < N; ++i) {

		left[i] = cnt;

		if(S[i] == 'W') ++cnt;

	}



	cnt = 0;

	for(int i = N - 1; i >= 0; --i) {

		right[i] = cnt;

		cost[i] = left[i] + right[i];

		if(S[i] == 'E') ++cnt;

	}



	std::sort(cost.begin(), cost.begin() + N);



	std::cout << cost[0] << std::endl;

 }
