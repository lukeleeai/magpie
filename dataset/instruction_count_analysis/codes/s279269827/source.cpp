#include <iostream>

#include <vector>

#include <algorithm>



void ToOctalNumber(int n){

	if(!n)return;

	ToOctalNumber(n >> 3);

	std::cout << ((n&7)<4?n&7:(n&7)==4?5:(n&7)+2);

}



int main(){

	int n;

	while(std::cin >> n, n){

		ToOctalNumber(n);

		std::cout << "\n";

	}

}