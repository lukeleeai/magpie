#include <iostream>

#include <algorithm>



using namespace std;



int c[6] = {1, 5, 10, 50, 100, 500};



int getNum(int t){

	int res = 0;

	for(int i=5;i>=0;i--){

		res += t/c[i];

		t %= c[i];

	}

	return res;

}



int main(){

	int P, N[6];

	while(cin >> P, P){

		int end = 0;

		for(int i=0;i<6;i++){

			cin >> N[i];

			end += c[i]*N[i];

		}

		int ans = 10000000;

		for(int i=P;i<=end;i++){

			int cur = getNum(i-P);

			int l = i;

			for(int j=5;j>=0;j--){

				int tmp = l/c[j];

				cur += min(N[j], tmp);

				l -= min(N[j], tmp)*c[j];

			}

			if(l != 0) continue;

			ans = min(ans, cur); 

		}

		cout << ans << endl;

	}

}