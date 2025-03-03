#include<iostream>

#include<cstring>

#include<algorithm>

#include<cstdio>

#include<cstdlib>

#include<queue>

#include<cmath>

#include<cctype>

#include<stack>

using namespace std;

const int INF = 0x3f3f3f3f;

const int maxn = 1000 + 10;

int main()

{

	ios::sync_with_stdio(false);

	int a, b, c;

	while (cin >> a >> b >> c)

	{

		if (a == 5 && b == 5 && c == 7)

			cout << "YES" << endl;

		else if (a == 5 && b == 7 && c == 5)

			cout << "YES" << endl;

		else if (a == 7 && b == 5 && c == 5)

			cout << "YES" << endl;

		else

			cout << "NO" << endl;

	}

	return 0;

}