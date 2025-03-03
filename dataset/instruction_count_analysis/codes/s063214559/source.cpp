#include "stdc++.h"

using namespace std;



#define FOR(i,a,b) for(int i = (a); i < (b); i++)

#define RFOR(i,b,a) for(int i = (b)-1; i >= (a); i--)

#define ITER(it, a) for (__typeof(a.begin()) it = a.begin(); it != a.end(); it++)

#define FILL(a,value) memset(a, value, sizeof(a))



#define SZ(a) (int)a.size()

#define ALL(a) a.begin(), a.end()

#define PB push_back

#define MP make_pair



typedef long long LL;

typedef vector<LL> VI;

typedef pair<int, int> PII;



const double PI = acos(-1.0);

const int INF = 1000 * 1000 * 1000 + 7;

const LL LINF = INF * (LL) INF;



const int MAX = 100100;



int A[MAX];

LL A2[MAX];



LL D[MAX];



VI ADD[MAX];

VI REM[MAX];



LL ST[MAX];



multiset<LL> S;



int main()

{

	//freopen("in.txt", "r", stdin);

	//ios::sync_with_stdio(false); cin.tie(0);



	int n, e, t;

	scanf("%d%d%d", &n, &e, &t);

	FOR (i, 0, n)

	{

		scanf("%d", &A[i]);

		A2[i] = A[i] * 2;

	}



	FOR (i, 0, n + 7)

	{

		ST[i] = LINF;

	}





	LL res = e;



	D[0] = 0;

	LL mn = LINF;



	FOR (i, 0, n + 1)

	{

		FOR (j, 0, SZ(ADD[i]))

		{

			S.insert(ADD[i][j]);

		}



		FOR (j, 0, SZ(REM[i]))

		{

			S.erase(S.find(REM[i][j]));

		}



		mn = min(mn, ST[i]);



		if (i == 0) D[i] = 0;

		else

		{

			D[i] = LINF;

			if (SZ(S))D[i] = *S.begin();



			D[i] = min(D[i], 2 * A[i - 1] + mn);



	//		cout<<i<<' '<<mn<<endl;

	//		if (SZ(S)) cout<<"** "<<*S.begin()<<endl;



			if (i == n) break;

		}



		int pos = upper_bound(A2, A2 + n, A2[i] + t) - A2;



	//	cout<<i<<": "<<pos<<endl;



		ADD[i+1].PB(D[i] + t);

		REM[pos + 1].PB(D[i] + t);



		ST[pos + 1] = min(ST[pos + 1], D[i] - 2 * A[i]);

		//mn = min(mn, D[i] - 2 * A[i]);

	}





/*	FOR (i, 0, n + 1)

	{

		cout<<D[i]<<' ';

	}

	cout<<endl;*/



	res += D[n];



	cout<<res<<endl;





}




