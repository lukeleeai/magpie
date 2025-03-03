#include <iostream>

#include <vector>

#include <algorithm>

#include <string.h>

#include <iomanip>

#include <math.h>



typedef long long int ll;



#define FOR(i,n,m) for(ll i=(ll)(m);i<(ll)(n);++i)

#define REP(i,n) FOR(i,n,0)

#define IREP(i,n) for(ll i=(ll)(n);i>=0;--i)

#define OF64 std::setprecision(10)



const ll MOD = 1000000007;



using namespace std;



const int MAX = 300000;



int Prime[55555];

bool isPrime[MAX];





int main()

{

	int N;

	cin >> N;

	REP(i, MAX)

	{

		isPrime[i] = true;

	}



	int num = 0;

	isPrime[0] = isPrime[1] = false;

	for (int i = 2; i < MAX; ++i)

	{

		if (!isPrime[i])continue;

		if (i <= 55555)

		{

			Prime[num++] = i;

		}

		for (int j = 2 * i; j < MAX; j += i)

		{

			isPrime[j] = false;

		}

	}



	vector<int> ans;

	REP(i, num)

	{

		if (Prime[i] % 10 == 1)

		{

			ans.push_back(Prime[i]);

		}

		if (ans.size() == N)break;

	}



	cout << ans[0];

	REP(i, N-1)

	{

		cout << " " << ans[i + 1];

	}

	cout<<endl;



	return 0;

}