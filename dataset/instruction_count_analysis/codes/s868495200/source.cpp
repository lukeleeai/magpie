#include<cstdio>

#include<algorithm>



using namespace std;

typedef long long llong;



int N;

llong v_list[100001];

double tripartition;

	

llong BaumukuchenGetAnswer();

inline llong searchOne(int n0, int n1_left, int n2_left);

inline llong getMinV(int n0, int n1_left, int n2_left);

inline int findIndexBinary(int from_n, int to_n, double target);

inline int findIndexSequential(int from_n, double target);





int main(){

	/*

	FILE* fp = fopen("input.txt", "r");

	fscanf(fp, "%lld", &N);

	v_list[0] = 0;

	for(int n=1; n<N+1; n++){

		llong A;

		fscanf(fp, "%lld", &A);

		v_list[n] = v_list[n-1] + A;

	}

	fclose(fp);



	/*/

	scanf("%lld", &N);

	v_list[0] = 0;

	for(int n=1; n<N+1; n++){

		llong A;

		scanf("%lld", &A);

		v_list[n] = v_list[n-1] + A;

	}

	//*/

	printf("%lld\n", BaumukuchenGetAnswer());

}



llong BaumukuchenGetAnswer(){

	tripartition = v_list[N] / 3.0;

	int n0_max = findIndexBinary(0, N, tripartition);



	int n1_left = n0_max;

	int	n2_left = findIndexBinary(n1_left, N,  2*tripartition);

	llong interm_maxV = searchOne(0, n1_left, n2_left);

	for (int n0 = 1; n0 <= n0_max; n0++){

		n1_left = findIndexSequential(n1_left,   tripartition + v_list[n0]);

		n2_left = findIndexSequential(n2_left, 2*tripartition + v_list[n0]);

		

		llong tmp = searchOne(n0, n1_left, n2_left);

		if (tmp > interm_maxV) interm_maxV = tmp;

	}

	return interm_maxV;

}



llong searchOne(int n0, int n1_left, int n2_left){

	llong V_ll = getMinV(n0, n1_left  , n2_left  );

	llong V_lr = getMinV(n0, n1_left  , n2_left+1);

	llong V_rl = getMinV(n0, n1_left+1, n2_left  );

	llong V_rr = getMinV(n0, n1_left+1, n2_left+1);

	return max( max(V_ll,V_lr), max(V_rl, V_rr));

}



llong getMinV(int n0, int n1, int n2){

	llong V0 = v_list[n1] - v_list[n0];

	llong V1 = v_list[n2] - v_list[n1];

	llong V2 = v_list[n0] - v_list[n2] + v_list[N];

	return min(min(V0,V1),V2);

}



int findIndexBinary(int from_n, int to_n, double target){

	while (to_n - from_n != 1) {

		int n_mid = (to_n + from_n) / 2;

		if (v_list[n_mid] > target) to_n = n_mid;

		else from_n = n_mid;

	}

	return from_n;

}



int findIndexSequential(int from_n, double target){

	for(int n=from_n; n<= N; n++)if(v_list[n] > target) return n-1;

	return N-1;

}