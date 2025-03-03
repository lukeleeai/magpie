#include<iostream>

#include<utility>

#include<iomanip>

#include<cmath>

#include<algorithm>

#include<cfloat>

#include<functional>

#include<string>

#include<numeric>

#include<vector>

#include<stack>

#include<queue>

#include<set>

#include<map>

#include<cctype>

#include<iterator>

#include <stdio.h>

#include <string.h>

//#include<conio.h>

#define MEGA_MIND ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);

using namespace std;

using ll = long long;

using ld = long double;





int main()

{

	MEGA_MIND

			ll n, k,arr[200005],sum=0;

		cin >> n >> k;

		for (int i = 0; i < n; i++)

		{

			cin >> arr[i];

		}

		sort(arr, arr + n);

		for (int i = n-1; i >= 0; i--)

		{

			if (k>0)

			{

				k--;

			}

			else

			{

				sum += arr[i];

			}

		}

		cout << sum << endl;

	

	return  0;

}


