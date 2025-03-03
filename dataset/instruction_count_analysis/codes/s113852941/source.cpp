#include"stdc++.h"

using namespace std;



int bs(vector<int> &arr, int l,int r,int x){

	int ans = -1;

	while(l <= r){

		int m = (l + r) / 2;

		if(arr[m] <= x){

			ans = m;

      l = m + 1;

		}

		else{

			r = m - 1;

		}

	}

	return ans;

}



int main() {

	int l, r, d;

	cin >> l >> r >> d;

	

	vector<int>cr;

	for(int i = l; i <= r;i++){

		cr.push_back(i);

	}

	int cnt = 0;

	for(int t = 1; t < 100000; t++){

		if(t * d > r){

			break;

		} 

		else if (bs(cr, 0, (cr.size() - 1), t * d) != -1){

			cnt++;

		}

	}

	cout << cnt << endl;

	return 0; 

}