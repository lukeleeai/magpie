#include <algorithm>

#include <cmath>

#include <deque>

#include <iostream>

#include <numeric>

#include <sstream>

#include <string>

#include <string.h>

#include <vector>



#define REP(i,x) for(int i{ 0 }; i < (int)(x); i++)

#define REPC(i,x) for(int i{ 0 }; i <= (int)(x); i++)

#define RREP(i,x) for(int i{ (int)(x) - 1 }; i >= 0 ;i--)

#define RREPC(i,x) for(int i{ (int)(x)}; i >= 0; i--)

#define REP1O(i,x) for(int i{ 1 }; i < (int)(x); i++)

#define REP1C(i,x) for(int i{ 1 }; i <= (int)(x); i++)



#define PB push_back

#define MP make_pair

#define F first

#define S second

#define SZ(x) ((int)(x).size())

#define ALL(x) (x).begin(),(x).end()



using namespace std;



typedef int64_t ll;

typedef pair<int, int> pii;



const int dx[4] = { 1, 0, -1,  0 };

const int dy[4] = { 0, 1,  0, -1 };

const int INTMAX = 2147483647;

const ll LLMAX = 9223372036854775807;



template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }

template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

void SWAP(ll& a, ll& b) { a ^= b; b ^= a; a ^= b; }

void SWAP(int& a, int& b) { a ^= b; b ^= a; a ^= b; }



class D {

	string s;

	int x, y;

	vector<vector<bool>> dpx, dpy;

	static const int offset{ 8001 };

	static const int MAX{ 2 * offset + 1 };



public:

	D()

	{

		cin >> s >> x >> y;



		dpx.resize(1, vector<bool>(MAX, 0));

		dpy.resize(1, vector<bool>(MAX, 0));



		dpx[0][offset] = 1;

		dpy[0][offset] = 1;



	}

	void solve()

	{



		bool xmove{ true };

		int d{ 0 };

		int nx{ 0 }, ny{ 0 };

		int i{ 0 };



		if (s[0] == 'F')

		{

			while (s[i] == 'F')

			{

				++i;

				++d;

			}

			nx++;

			dpx.emplace_back(vector<bool>(MAX, 0));

			dpx[1][d + offset] = 1;

			d = 0;

			xmove = false;

			++i;

		}



		for (; i < SZ(s); i++)

		{

			if (s[i] == 'F')

				++d;



			if (s[i] == 'T' || (i == SZ(s) - 1))

			{

				if (d)

				{

					if (xmove)

					{

						dpx.emplace_back(vector<bool>(MAX, 0));

						REP(i, MAX)

						{

							if (dpx[nx][i])

							{

								if (i - d >= 0 && i - d < MAX)

									dpx[nx + 1][i - d] = 1;

								if (i + d >= 0 && i + d < MAX)

									dpx[nx + 1][i + d] = 1;

							}

						}

						++nx;

					}



					else

					{

						dpy.emplace_back(vector<bool>(MAX, 0));

						REP(i, MAX)

						{

							if (dpy[ny][i])

							{

								if (i - d >= 0 && i - d < MAX)

									dpy[ny + 1][i - d] = 1;

								if (i + d >= 0 && i + d < MAX)

									dpy[ny + 1][i + d] = 1;

							}

						}

						++ny;

					}

				}



				xmove = !xmove;

				d = 0;

			}

		}



		//

		//REPC(i, nx)

		//{

		//	for (int j{ offset - 7 }; j < offset + 7; j++)

		//	{

		//		if (j == offset)

		//			cout << "   " <<  dpx[i][j] << "   ";

		//		else

		//			cout << dpx[i][j] << " ";

		//	}

		//	cout << endl;

		//}

		//

		

		if (dpx[nx][x + offset] && dpy[ny][y + offset])

			cout << "Yes";

		else

			cout << "No";

		cout << endl;



	}

};





int main()

{

	D solution;

	solution.solve();



	return 0;

}