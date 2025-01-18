#include "stdc++.h"

using namespace std;



int n;

int k;

vector<int> arr(100004, 0);

vector<int> memo(100004, -1);



int cost(int i) {

	if(i>=n-1) return 0;

	if(i==n-2) return abs(arr[n-2]-arr[n-1]);



	if(memo[i]==-1) 

	{

		for(int j=1; j<=k; ++j)

		{

			if(i+j>n-1) break;

			int temp = abs(arr[i+j]-arr[i]) + cost(i+j);

			memo[i] = (memo[i]==-1) ? temp : min(memo[i], temp);

		}

	}

	return memo[i]; 

}





int main() {



	cin >> n >> k;

	for(int i=0; i<n; ++i) cin >> arr[i];



	cout << cost(0) << endl;

	return 0;

}