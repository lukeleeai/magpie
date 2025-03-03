#include <algorithm>

#include <iostream>

#include <queue>



using namespace std;



int main()

{

	int n, m;

	cin >> n >> m;

	

	priority_queue<long> que;

	long a[100000] = {};

	for (int i = 0; i < n; i++) {

		cin >> a[i];

		que.push(a[i]);

	}

	

	long temp;

	while(m--) {

		temp = que.top();

		que.pop();

		temp /= 2;

		que.push(temp);

	}

	

	long long sum = 0;

	for (int i = 0; i < n; i++) {

		sum += que.top();

		que.pop();

	}

	

	cout << sum;

}
