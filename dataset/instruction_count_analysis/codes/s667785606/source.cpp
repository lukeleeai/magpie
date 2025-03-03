

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



long long f[100];



int main() {

	f[1] = 1;

	f[2] = 26;

	rep(i,3,80) f[i] = f[i-1] * 26;

	rep(i,2,80) f[i] += f[i-1];

	long long a;

	string s;

	cin >> a;

	int b = 0;

	rep(i,1,50) {

		//cout << a << " " << f[i] << endl;

        if (a < f[i]) {

        a -= f[i-1], b= i-1;;

       

        break;

        }

	}

	rep(i,1,b) {

		s.push_back(a % 26 + 'a');

		a /= 26;

	}

	reverse(s.begin(), s.end());

	cout << s << endl;

}