#include <iostream>

#include <string.h>

#define MAXN 100005

using namespace std;



int n, ps[MAXN];

string s;

bool valid(int k){

	memset(ps, 0, sizeof ps);

	int tmp = 0;

	for(int i = 0; i <= n - k; i++){

		tmp += ps[i];

		int now = (s[i]	- '0') ^ (tmp % 2);

//		cout << i << " # " << tmp << " \n";

		if(!now) continue;

		ps[i+1]++;

		ps[min(i+k, n)]--;

	}

	int r = n - k;

	for(int i = n - k + 1; i < n; i++){

		tmp += ps[i];

		int now = (s[i]	- '0') ^ (tmp % 2);

		if(now) break;

		r = i;

	}

//	cout << k << " -> " << r << "\n";

	return r + 1 >= k;

}

int main(){

	ios_base::sync_with_stdio(0);

	cin.tie();

	

	cin >> s;

	n = s.length();

	int l = 1;

	int r = s.length();

	int k = (l + r + 1) / 2;

	while(l < r){

		if(valid(k)) l = k;

		else r = k - 1;

		k = (l + r + 1) / 2;

	}

	cout << l << "\n";

	return 0;

}