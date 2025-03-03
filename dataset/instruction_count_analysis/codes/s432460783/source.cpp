#include <iostream>

#include <cstdio>

#include <cstring>

#include <algorithm>

#include <vector>

#include <map>

#include <cmath>

#include <queue>

#include <set>

#include <ctime>

#define rep(i,j,k) for(int i = j; i <= k; i++)

#define dow(i,j,k) for(int i = j; i >= k; i--)

#define ez(i,x) for(int i = h[x]; i; i = e[i].next)

#define fi first

#define se second

#define MS(x) memset(x, 0, sizeof(x))

using namespace std;



int main() {

	int n, k;

	cin >> n >> k;

	vector<int> a(n);

	rep(i,1,n) scanf("%d", &a[i-1]);

	sort(a.begin(),a.end());

	long long b = 0;

	rep(i,0,k-1) b += a[i];

	cout << b << endl;

}