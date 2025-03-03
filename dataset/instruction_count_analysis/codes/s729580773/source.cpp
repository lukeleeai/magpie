#include<iostream>

using namespace std;



#define justinlaiorz ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int N = 1e5 + 2;

int n, a[N], pre[N], suf[N];



inline int abs(int a){

	return a < 0 ? -a : a;

}

int main(){

	justinlaiorz

	cin >> n;

	for(int i = 1; i <= n; ++i) cin >> a[i];

	for(int i = 1; i <= n; ++i) pre[i] = pre[i-1] + abs(a[i] - a[i-1]);

	for(int i = n; i >= 1; --i) suf[i] = suf[i+1] + abs(a[i] - a[i+1]);

	for(int i = 1; i <= n; ++i){

		cout << pre[i-1] + suf[i+1] + abs(a[i-1] - a[i+1]) << '\n';

	}

	return 0;

}