#include <cstdio>

#include <cstring>

#include <cmath>

#include <algorithm>

#include <iostream>

#include <sstream>

#include <queue>

#include <map>

#include <vector>

#include <set>

#include <cstdlib>

#include <stack>



using namespace std;



typedef long long LL;

typedef double db;

#define FAST ios::sync_with_stdio(false);

const int MaxN = 105;

int main()

{

	int n , m;

	char mp[MaxN][MaxN];

	cin >> n >> m;

	for(int i = 1 ; i <= n ; i++)

		for(int j = 1 ; j <= m ; j++)

			cin >> mp[i][j];

	for(int i = 0 ; i <= n + 1; i++)

		for(int j = 0 ; j <= m + 1; j++)

			{

				if(i == 0 || j == 0 || j == m + 1 || i == n + 1)

					cout << "#";

				else cout << mp[i][j];

				if(j == m + 1)cout << endl;

			}

	return 0;

	}