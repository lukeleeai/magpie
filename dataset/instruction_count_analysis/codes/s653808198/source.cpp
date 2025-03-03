#include <iostream>

#include <string>

#include <algorithm>

#include <cmath>

#include <cstdlib>

#include <vector>



using namespace std;

#define rep(i, s, e) for (int(i) = (s); (i) < (e); (i)++)



int main()

{

	int a, b, c, x, y, cost, ans;

	cin >> a >> b >> c >> x >> y;

	ans = a*x + b*y;

	rep(i, 0, 100001)

	{

		cost = c * i * 2 + a * max(0, x - i) + b * max(0, y - i);

		ans = min(ans, cost);

	}

	cout << ans << endl;

}
