#include <iostream>

#include <cstdio>

#include <iomanip>

#include <cmath>

#include <string>

#include <cstring>

#include <algorithm>

#include <vector>

#include <sstream>

#include <set>

#include <queue>

#include <stack>

#include <cctype>

#include <map>

#include <climits>

#include <bitset>

using namespace std;

#define MATH_PI 3.14159265358979323846

int main(){

	ios::sync_with_stdio(false);

	int nCount,iStart,iEnd;

	register int i,nTotal=0;

	cin >> nCount;

	for (i = 1; i <= nCount; ++i){

		cin >> iStart >> iEnd;

		nTotal += iEnd - iStart + 1;

	}

	cout << nTotal << endl;

endapp:

	//system("pause > nul");

	return 0;

}