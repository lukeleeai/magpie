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

	unsigned long long arrAns[50] = { 2 };

	register int i;

	for (i = 1; i <= 45; ++i){

		arrAns[i] = arrAns[i - 1] * 2 + 2;

	}

	cin >> i;

	cout << arrAns[i] << endl;

endapp:

	//system("pause > nul");

	return 0;

}