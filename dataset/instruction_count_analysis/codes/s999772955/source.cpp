#include <map>

#include <set>

#include <queue>

#include <stack>

#include <cmath>

#include <cstdio>

#include <string>

#include <cstring>

#include <iostream>

#include <algorithm>

using namespace std;



#define ls st<<1

#define rs st<<1|1

#define LL long long

#define CLR(a,b) memset(a,(b),sizeof(a))



const int MAXN = 1e5+11;

const int mod = 1e9+7;

const int INF = 0x3f3f3f3f;



/* ------------------------基本函数-------------------------*/





LL pow_mod(LL a, LL b) {

	LL ans = 1;

	while(b) {

		if(b&1)

			ans = (ans*a) % mod;

		a = (a*a) % mod;

		b /= 2;

	}

	return ans;

}



int arr[MAXN];

int main() {

	int n;

	cin >> n;

	for(int i = 1; i <= n; i++) {

		cin >>arr[i];

	}

	bool flag = true;

	sort(arr+1,arr+1+n);

	if(n&1) {

		if(arr[1]!=0) flag = false;

		for(int i = 2,j=2; i <= n-1; i+=2,j+=2) {

			//cout<<arr[i]<<' '<<j<< endl;

			if(arr[i] != j) {

				flag = false; break;

			}

		}

	}

	else {

		for(int i = 2,j=1; i<=n; i+=2,j+=2) {

			if(arr[i] != j) {

				flag = false; break;

			}

		}

	}

	if(flag) {

		LL xx = (LL)(n/2);

		//cout << xx<< endl;

		cout << pow_mod(2,xx) << endl;

	}

	else cout << 0 << endl;



return 0;

}
