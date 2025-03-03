//#include "pch.h"

#include <stdio.h>

#include <string.h>

#include <algorithm>

#include <iostream>

#include <string>

#include <vector>

#include <functional>

#include <map>

#include <iomanip>

#include <math.h> 

#include <stack>

#include <queue>

#include <bitset>

#include <cstdlib>

#include <tuple>

#include <cctype>

#include <ctype.h>

#include <set>

#include <sstream>

#include <time.h>

#include <numeric>

using namespace std;

//#define int long long

#define rep(i,s,n) for(int i = s;i<n;i++)

#define repe(i,s,n) for(int i = s;i<=n;i++)

#define rrep(i,s,n) for(int i = (n)-1;i>=(s);i--)

#define all(v) (v).begin(),(v).end()

#define pb push_back

#define fi first

#define se second

#define chmin(a,b) a=min((a),(b))

#define chmax(a,b) a=max((a),(b))

#define l1 list[index]

#define l2 list[index - 1]

#define l3 list[index + 1]

#define iif(i,j) ((i<0 && j<0) || (i>0 && j>0)) ? true : false 

typedef long long ll;

typedef pair<int, int>pint;

typedef vector<int>vint;

typedef vector<pint>vpint;

typedef pair<pint, int> P1;

typedef pair<int, pint> P2;

typedef pair<pint, pint> PP;

static const ll maxLL = (ll)1 << 62;

const ll MOD = 1000000007;

const ll INF = 1e18;

const double PI = 3.14159265359;

int ca[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };













signed main() {

	int n;

	vector<double>list;

	double m, sum=0;

	cin >> n >> m;



	for (int i = 0; i < n; i++) {

		double num;

		cin >> num;

		list.push_back(num);

		sum += num;

	}



	double jyo = sum / (4 * m);

	int cnt = 0;



	for (int i = 0; i < n; i++) {

		if (jyo <= list[i])cnt++;

	}



	if (cnt >= (int)m) {

		cout << "Yes" << endl;

	}

	else {

		cout << "No" << endl;

	}







	return 0;

}