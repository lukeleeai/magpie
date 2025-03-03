#include"stdc++.h"

using namespace std;

int main()

{

	int a; cin >> a;

	int arr[a + 50], n = 0, m = 0, now = 999999999;

	for(int i=0; i<a; i++)

	{

		cin >> arr[i];

		n = max(n, arr[i]);

	}

	for(int i=0; i<a; i++)

	{

		if(arr[i] == n) continue;

		int tmp = abs(arr[i] - n / 2);

		if(m % 2) tmp = min(abs(arr[i] - n / 2), abs(arr[i] - (n + 1) / 2));

		if(tmp < now)

		{

			now = tmp;

			m = arr[i];

		}

	}

	cout << n << ' ' << m << '\n';

	return 0;

}