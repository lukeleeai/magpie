#include <cstdio>

#include <iostream>

using namespace std;



int main()

{

	int InArray[200000] = {0};		// end is linked to start (Baumkuchen is round)

	int N;							// total data input

	int i;							// for counter

	int inputBuffer;				// buffer for input data

	int a1, a2, a3;					// the start index of each region

	long long sum;					// buffer for sum

	long long average, average2;	// sum / 3, (sum - region1) / 2

	long long a1_sum, a2_sum;		// sum of region1, region2

	long long MaxMin;				// final result

	

	scanf("%d", &N);

	for(i = 0; i < N; i++){

		scanf("%d", &inputBuffer);

		InArray[i] = inputBuffer;

		InArray[i + N] = inputBuffer;

	}



	

	// Calculate sum and average

	sum = 0;

	for(i = 0; i < N; i++){

		sum += InArray[i];

	}

	if(sum % 3 == 0){

		average = sum / 3;

	}else{

		average = sum / 3 + 1;

	}

	

	MaxMin = 0;

	for(a1 = 0; a1 < N; a1++){

		a1_sum = 0;

		for(a2 = a1 + 1; a2 < (a1 + N); a2++){

			a1_sum += InArray[a2 - 1];

			if(a1_sum < average) continue;

			

			if((sum - a1_sum) % 2 == 0){

				average2 = (sum - a1_sum) / 2;

			}else{

				average2 = (sum - a1_sum + 1) / 2;

			}

			

			a2_sum = 0;

			for(a3 = a2 + 1; a3 < (a1 + N); a3++){	// left 1 for a3_sum

				a2_sum += InArray[a3 -1];

				if(a2_sum < average2) continue;

								

				if(a2_sum - InArray[a3 -1] > MaxMin){

					MaxMin = a2_sum - InArray[a3 -1];

				}

				if(sum - a1_sum - a2_sum   > MaxMin){

					MaxMin = sum - a1_sum - a2_sum;

				}

				break;

			}

			break;

		}

	}

	

	printf("%lld\n", MaxMin);

	

	return 0;

}