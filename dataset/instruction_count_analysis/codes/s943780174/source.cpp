#include"stdc++.h"

using namespace std;



#define M 1000000



bool isTrue(int val, vector<int> list) {

	

	for(int x: list) {

		if(val%x != x-1) {

			return false;

		}

	}

	return true;

}





void solve()

{	

	int n,num,m = INT_MIN,val;

	vector<int> list;

	cin >> n;

	while(n-- && cin >> num) {

		list.emplace_back(num);

		m = max(m,num);

	}

	//cout << m << endl;

	val = m-1;

	while(1) {

		if(isTrue(val, list)) {

			cout << val << endl;

			break;

		} 

		val += m;

	}

}



bool perfectSquare(long long int n) {

	double long s = sqrt(n);

	

	if(s == floor(s)) {

		return true;

	}

	return false;

}



void answer() {

	long long int len,num;

	vector<long long int> list;

	cin >> len;

	

	while(len-- && cin >> num) {

		list.emplace_back(num);

	}

	

	bool prime[M+1];

	

	memset(prime, true, sizeof(prime));

	

	for(int i=2;i<=sqrt(M);i++) {

		if(prime[i]) {

			for(int j=i*i;j<=M;j+=i) {

				prime[j] = false;

			}

		}

	}

	

	for(long long int x: list) {

		if(perfectSquare(x)) {

			long long int p = sqrt(x);

			if(prime[p]) {

				cout << "YES" << endl;

			} else {

				cout << "NO" << endl;

			}

		} else {

			cout << "NO" << endl;

		}

	}

}



void result() {

	long long int n,res=0,num;

	cin >> n;

	while(n-- && cin >> num) {

		res += num-1;

	}

	

	cout << res << endl;

}

			

		



int main() {

	ios::sync_with_stdio(0);

	cin.tie(0);

	result();

	return 0;

}
