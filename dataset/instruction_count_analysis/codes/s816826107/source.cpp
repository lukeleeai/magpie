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

	char a , b;

	cin >> a >> b;

	if(a == 'H')cout << b << endl;

	else {

		if(b == 'H')cout << "D" << endl;

		else cout << "H" << endl;

		}

	return 0;

	}