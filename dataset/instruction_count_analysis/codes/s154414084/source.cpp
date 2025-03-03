#include<iostream>

#include<algorithm>

#define DIV 100000

using namespace std;



long long d,S[100010];



int main(){

	long long n, m, k, t = 0;

	long long ans = 0;

	cin >> n >> m; S[0] = 0;

	for (int i = 1; i < n; i++){

		cin >> d; S[i] = S[i - 1] + d;

	}

	while (m--){

		cin >> k;

		ans += abs(S[t] - S[t + k]);

		ans = ans%DIV;

		t += k;

	}

	cout << ans << endl;

}