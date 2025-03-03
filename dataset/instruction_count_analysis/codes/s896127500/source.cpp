#include<iostream>

#include<algorithm>

using namespace std;

int a[100005];

int main()

{

	int n;

	cin >> n;

	for (int i = 1; i <= n; i++)

		cin >> a[i];

	int now = 1, cnt = 0;

	for (int i = 1; i <= n; i++)

	{

		now = a[now]; cnt++;

		if (now == 2)break;

	}

	if (now == 2)cout << cnt << endl;

	else cout << -1 << endl;

	return 0;

}