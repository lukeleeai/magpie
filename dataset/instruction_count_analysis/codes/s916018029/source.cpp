#include<cstdio>

#include<iostream>

using namespace std;



int n, k;

int a[100050];

long long ans;





bool find(long long p)

{

	long long cnt = 1, l = p;

	for (int i = 0; i < n; i++)

	{

		if (a[i] <= l)

			l -= a[i];

		else

			if (a[i] > p) return 0;

			else

				l = p - a[i], cnt++;

		if (cnt > k) return 0;

	}

	return 1;

}



int main()

{

	scanf("%d%d", &n, &k);

	long long tot = 0;

	for (int i = 0; i < n; i++)

		cin >> a[i], tot += a[i];

	long long l = 0, r = tot;

	while (l<=r)

	{

		long long mid = (l + r) / 2;

		if (find(mid))

			ans = mid, r = mid - 1;

		else

			l = mid + 1;

	}

	cout << ans << endl;

	return 0;

}