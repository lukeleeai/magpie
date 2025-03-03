#include<cstdio>

#include<algorithm>



using namespace std;



int N;

int A[300005];



int main(){

	scanf("%d", &N);

	for(int i=0;i<3*N;i++){

		scanf("%d", &A[i]);

	}

	sort(A, A+3*N);

	long long tot = 0;

	for(int i=N;i<3*N;i+=2){

		tot += (long long)A[i];

	}

	printf("%lld\n", tot);

	return 0;

}