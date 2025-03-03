#include<iostream>

#include<algorithm>

#include<limits>



#ifndef  LLONG_MAX

#define LLONG_MAX 9223372036854775807

#endif



using namespace std;

typedef long long llong;



int N;

llong *v_list;

double tripartition;

	

llong BaumukuchenGetAnswer();

llong searchOne(int n0);

llong getMinV(int n0, int n1, int n2);

int findIndex(int from_n, int to_n, double target);



int main(){

	/*

	ifstream fin("input.txt");

	fin >> N;

	v_list = new llong[N+1];

	v_list[0] = 0;

	for(int n=1; n<N+1; n++){

		llong A;

		fin >> A;

		v_list[n] = v_list[n-1] + A;

	}

	fin.close();

	/*/

	cin >> N;

	v_list = new llong[N+1];

	v_list[0] = 0;

	for(int n=1; n<N+1; n++){

		llong A;

		cin >> A;

		v_list[n] = v_list[n-1] + A;

	}

	//*/

	cout << BaumukuchenGetAnswer() <<endl;

	delete[] v_list;

}





llong BaumukuchenGetAnswer(){

	tripartition = v_list[N] / 3.0;

	llong interm_maxV = -1;

	int n0_max = findIndex(0, N, tripartition);

	for (int n0 = 0; n0 <= n0_max; n0++){

		llong tmp = searchOne(n0);

		if (tmp > interm_maxV) interm_maxV = tmp;

	}

	return interm_maxV;

}



llong searchOne(int n0){

	int n1_left = findIndex(n0, N, tripartition + v_list[n0]);

	int n2_left = findIndex(n1_left, N, 2 * tripartition + v_list[n0]);

	llong V_ll = getMinV(n0, n1_left, n2_left);

	llong V_lr = getMinV(n0, n1_left, n2_left+1);

	llong V_rl = getMinV(n0, n1_left+1, n2_left);

	llong V_rr = getMinV(n0, n1_left+1, n2_left+1);

	return max( max(V_ll,V_lr), max(V_rl, V_rr));

}



llong getMinV(int n0, int n1, int n2){

	if (n1 == -1 || n2 == -1) return LLONG_MAX;

	else {

		llong V0 = v_list[n1] - v_list[n0];

		llong V1 = v_list[n2] - v_list[n1];

		llong V2 = v_list[n0] - v_list[n2] + v_list[N];

		return min(min(V0,V1),V2);

	}

}



int findIndex(int from_n, int to_n, double target){

	int n_left = from_n;

	int n_right = to_n;

	while (n_right - n_left != 1) {

		int n_mid = (n_right + n_left) / 2;

		if (v_list[n_mid] <= target) n_left = n_mid;

		else n_right = n_mid;

	}

	return n_left;

}