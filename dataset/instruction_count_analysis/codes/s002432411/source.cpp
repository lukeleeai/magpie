#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <iostream>

#include <string>

using namespace std;



int main(int argc, char* argv[]){

	int N, M;

	cin >> N >> M;

	for(int i=1, j=0; j < M; i++){

		cout << i << " " << (M + 2 - i) << endl ;

		if(++j < M){

			cout << (M + i + 1) << " " <<  ((2 * M) + 2 - i) << endl;

			j++;

		}

	}

	return 0;

}