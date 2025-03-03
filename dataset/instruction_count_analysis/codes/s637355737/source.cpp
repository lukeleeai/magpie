

#include<iostream>

#include<map>

#include<algorithm>

#include <iomanip>

#include <cmath>

#include <sstream>

#include <unordered_map>

#include <unordered_set>

#include <deque>

#include <vector>

#include <bitset>

#include <queue>

#include <set>

#include <stack>

#include <string>

#include <cstring>



#define INF 1050000000

#define MOD 1000000007



int n, a, b, c;

int l[10];



using namespace std;



int dfs(int depth, int x, int y, int z) {

	if (depth == n) {

		if (x == 0 || y == 0 || z == 0) {//答えから除外する。無に魔法は使えない。

			return 1e9;

		}

		return abs(x - a) + abs(y - b) + abs(z - c) - 30;

	}



	int mu = dfs(depth + 1, x, y, z);

	int entyou = dfs(depth + 1, x + l[depth], y, z)+10;

	int tansyuku = dfs(depth + 1, x, y + l[depth], z)+10;

	int gousei = dfs(depth + 1, x, y, z + l[depth])+10;



	return min({ mu,entyou,tansyuku,gousei });



}





int main() {

	cin >> n >> a >> b >> c;



	for (int i = 0; i < n; i++) {

		cin >> l[i];

	}



	cout << dfs(0, 0, 0, 0) << endl;

















}