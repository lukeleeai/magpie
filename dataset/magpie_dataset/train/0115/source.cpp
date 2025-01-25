#include<iostream>

#include<cmath>

using namespace std;



int main(){



	long long a, n, m, R_ans, L_sum;

	int ans = 0, i = 1;



	cin >> a >> n >> m;



	R_ans = powl(i + a, n);



	while(R_ans <= m) {

		int  num = R_ans;

		L_sum = 0;



		//  各桁数の合計値を求める

		while(num > 0){

			L_sum += num % 10;

			num /=10;

		}



		//  左辺と右辺の式を比較

		if(R_ans == powl(L_sum+a,n)) ans++; 

		i++;

		R_ans = powl(i + a, n);

	}



	cout << ans << endl;



	return 0;

}
