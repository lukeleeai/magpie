#include<iostream>

#include<algorithm>

#include<cmath>

bool cmp(int a, int b){

	return a > b;

}

using namespace std;

int main(){

	int n;

	long long mid = 0;

	long long a[100010];

	cin >> n;

	for(int i = 0; i < n; i ++)cin >> a[i];

	sort(a, a + n, cmp);

	for(int i = 1; i < n; i ++){

		if(abs(a[0] - 2 * a[i]) <= abs(a[0] - 2 * mid))mid = a[i];

		else break;

	}

	cout << a[0] << ' ' << mid; 

}