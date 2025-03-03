#include<stdio.h> 

using namespace std;



int main() {

	int n,d[100];

	scanf("%d", &n);

	int i0 = 0; long result = 0;

	for(; i0<n; i0++) {scanf("%d", &d[i0]);}

	for(int i = 0; i < i0-1;i++){

		for(int j = i+1; j < i0;j++){

			result += d[i]*d[j];

		}

	}

	printf("%d", result);

	return 0;

} 