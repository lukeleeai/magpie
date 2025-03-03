#define _CRT_SECURE_NO_WARNINGS

#include<iostream>

#pragma GCC optimize("Ofast")



int main() {

	std::cin.tie(0);

	std::ios::sync_with_stdio(false);



	long int n, max = 2000000000;

	std::cin >> n;

	for(int i = 0; i < n; i++){

		long int a, b;

		std::cin >> a >> b;

		if(a+b < max) {

			max = a+b;

		}

	}

	std::cout << max  << "\n";

	return 0;

}
