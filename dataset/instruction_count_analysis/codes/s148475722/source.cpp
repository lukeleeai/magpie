#include "stdc++.h"

using namespace std;



template<typename T>

class BIT

{

//bit[x]

//manage range of bit[x] is (x & -x)

//

public:

	static const int n = 2*110000;

	T bit[n] = {};

	void add(int a, T w)

	{

		for (int x = a; x <= n; x += x & -x)

		{

			bit[x] += w;

		}

	}

	T sum(int a)

	{

		T ret = 0;

		for (int x = a; x > 0; x -= x & -x)

		{

			ret += bit[x];

		}

		return ret;

	}



};



int main()

{

	string s;

	cin >> s;

	int hairetsu[2*110000];

	int n = s.size();

	for (int i = 1; i <= n; ++i)

	{

		hairetsu[i] = (s[i-1] == 'B'?1:0);

	}

	long long int ans = 0;

	BIT<long long int> BT;

	for (int i = 1; i <= n; ++i)

	{

		BT.add(i, hairetsu[i]);

		if (hairetsu[i] == 0)

		{

			ans += BT.sum(i);

		}

		// cout << i - BT.sum(hairetsu[i]) << " ";

	}

	cout << ans << endl;

	return 0;

}