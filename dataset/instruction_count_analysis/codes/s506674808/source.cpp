/*

 * ARC097_C.cpp

 *

 *  Created on: May 12, 2018

 *      Author: 13743

 */



#include<iostream>

#include<vector>

#include<algorithm>

#include<queue>

#include<stack>

#include<cmath>



using namespace std;



int seq[30000] = {0};

int seq2[30000];



int powI(int x, int n) {

	int ans = 1;

	while(n--) {

		ans *= x;

	}

	return ans;

}



void quickSort(int l, int r, int* a, int* b) {

	if(l >= r) return;

	int piv = a[r];

	int i = l - 1;

	for(int j=l; j<r; j++) {

		if(a[j] <= piv) {

			i++;

			swap(a[i], a[j]);

			swap(b[i], b[j]);

		}

	}

	swap(a[i+1], a[r]);

	swap(b[i+1], b[r]);

	quickSort(l, i, a, b);

	quickSort(i+2, r, a, b);

}



int main() {

	int k;

	char s[5010];

	cin >> s;

	cin >> k;



	int n=0;

	for(int i=0; s[i]!='\0'; i++) {

		n++;

	}

	for(int i=0; i<5; i++) {

		s[n+i] = 'a'-1;

	}



	for(int i=0; i<n; i++) {

		for(int j=0; j<5; j++) {

			for(int k=0; k<=j; k++) {

				seq[5*i+j] += (s[i+k]-'a'+1)*powI(50, 4-k);

			}

		}

	}



	for(int i=0; i<=29000; i++) {

		seq2[i] = i;

	}



	quickSort(0, 5*n-1, seq, seq2);



	int ii=0;

	int num = -1;

	while(k > 0) {

//		cout << seq[ii] << endl;

		if(num != seq[ii]) {

			k--;

			num = seq[ii];

		}

		ii++;

	}

	ii--;

	int he = seq2[ii] / 5;

	int rem = seq2[ii] - he*5;

	for(int i=0; i<=rem; i++) {

		if(he+i < n)

			cout << s[he + i];

	}

	cout << endl;

}




