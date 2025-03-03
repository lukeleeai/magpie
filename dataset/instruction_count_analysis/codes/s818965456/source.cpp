#include<iostream>

#include<string.h>

#include<algorithm>

#include<stdio.h>

#include<math.h>

#include<vector>

#include<map>

#include<set>

#include<time.h> 

#define debug(a) cout << "*" << a << "*" << endl

#define ls	(k << 1)

#define rs	((k << 1) | 1)

#define mid	((l + r) >> 1)

using namespace std;

typedef long long ll;

ll a[100005], n, sum;

int main()

{

	scanf("%lld", &n);

	for (int i = 1; i <= n; i++)	

	{

		scanf("%lld", a + i);

		sum += abs(a[i] - a[i - 1]);

	}

	sum += abs(a[n]);

	for (int i = 1; i <= n; i++)

	{

		printf("%lld\n", sum + abs(a[i - 1] - a[i + 1]) - abs(a[i - 1] - a[i]) - abs(a[i] - a[i + 1]));

	}

}