#include <cmath>

#include <cstdio>

#include <algorithm>

using namespace std;

typedef long long ll;

const double pi = acos(-1);

struct data

{

	ll x , y;

	double ang;

	bool operator<(const data &a)const {return ang < a.ang;}

} a[400010];

int main()

{

	int n , i , p;

	ll sx = 0 , sy = 0 , ans = 0;

	scanf("%d" , &n);

	for (i = 1 ; i <= n ; i ++ ) scanf("%lld%lld" , &a[i].x , &a[i].y) , a[i].ang = atan2(a[i].y , a[i].x);

	sort(a + 1 , a + n + 1);

	for (p = i = 1 ; i <= n ; i ++ )

	{

		while (p < i + n && a[p].ang - a[i].ang < pi) sx += a[p].x , sy += a[p ++ ].y , ans = max(ans , sx * sx + sy * sy);

		sx -= a[i].x , sy -= a[i].y , ans = max(ans , sx * sx + sy * sy);;

		a[i + n].x = a[i].x , a[i + n].y = a[i].y , a[i + n].ang = a[i].ang + 2 * pi;

	}

	printf("%.18f\n" , sqrt(1.0 * ans));

	return 0;

}