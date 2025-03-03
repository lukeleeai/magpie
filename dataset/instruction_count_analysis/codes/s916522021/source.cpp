#include "stdc++.h"

#define watch(x) cout << (#x) << " is " << (x) << endl

const int mod = 998244353;



using namespace std;



int s, n;



void knapsackSubset()		//coeff x^s du polynome Pi(2+x^ai)

{	

	scanf("%d%d", &n, &s);

	int x;

	vector<long long> coeff(3000, 0);

	cin >> x;

	coeff[0] = 2, coeff[x] = 1;

	for(int i = 1; i < n; i++)

	{

		scanf("%d", &x);

		vector<long long>oldCo = coeff; //ancient coordonnes, (ne pas oublier qu'on mulitplie par 2, on doit se rappeler des ancierts coo, quitte a diviser par 2 aussi)

		for (int j = 0; j <= s; j++)

		{

			coeff[j] = (2*coeff[j])%mod;

			if (j >= x)

				coeff[j] += oldCo[j-x];

			coeff[j] %= mod;

		}

	} 

	cout << coeff[s] << endl;	

}



int main()

{

	#ifdef ME

		freopen("input.txt", "r", stdin);

		freopen("output.txt", "w", stdout);

	#endif



	knapsackSubset();

	return 0;

}




