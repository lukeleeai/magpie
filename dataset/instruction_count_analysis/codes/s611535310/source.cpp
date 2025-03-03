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



struct PrimeList

{

	PrimeList()

	{

		prime.clear();

	};

	~PrimeList() {};



	void init(int n)

	{

		std::vector<bool> isComposite(n + 1);

		for (int i = 2; i <= n; ++i)

		{

			if (isComposite[i])continue;

			prime.push_back(i);

			for (int j = i; j <= n; j += i)

			{

				isComposite[j] = true;

			}

		}

	}



	std::vector<int> prime;

};





int main()

{



	int N;

	cin >> N;

	PrimeList prime;

	prime.init(55555);



	vector<int> ans;

	REP(i, prime.prime.size())

	{

		if (prime.prime[i] % 10 == 1)ans.push_back(prime.prime[i]);

		if (ans.size() == N)break;

	}



	REP(i, N)

	{

		cout << ans[i] << " ";

	}

	cout << endl;

	return 0;

}