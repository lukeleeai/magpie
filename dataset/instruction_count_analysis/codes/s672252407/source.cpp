#include <iostream>



int main(){

	int n;

	while(std::cin >> n, n){

		int max_p, max_d = 0;

		for(;n;n--){

			int p, d1, d2;

			std::cin >> p >> d1 >> d2;

			if(d1 + d2 > max_d)

				max_p = p, max_d = d1 + d2;

		}

		std::cout << max_p << " " << max_d << std::endl;

	}

}