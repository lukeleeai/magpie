#define _CRT_SECURE_NO_WARNINGS

#include <iostream>	

#include <time.h>

#include <vector>

#include <stdio.h>

#include <memory.h>

#include <string>

#include <string.h>

#include <map>

#include <algorithm>

#include <bitset>

#include <queue>

#include <set>

#include <time.h>

#include <assert.h>

#include <sstream>

//#include <unordered_map>

#include <bitset>

#include <utility>

#include <iomanip>

#include <climits>

#include <cstdio>

#include <cstdlib>

#include <ctime>

#include <numeric>

#include <math.h>

#include <cmath>

#include <complex>

using namespace std;

typedef long long ll;





int main() {





	int n, a, b;

	scanf("%d%d%d", &n, &a, &b);

	int x = abs(a - b) - 1;

	if(x % 2 == 1)

		puts("Alice");

	else

		puts("Borys");



	return 0;

}