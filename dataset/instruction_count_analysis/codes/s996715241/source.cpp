#include <iostream>

#include <algorithm>

#include <iomanip>

#include <string>

#include <vector>

#include <math.h>

#include <queue>

#include <deque>

#include <stack>

#include <map>

const int MOD = 1e9+7;

#define PI 3.14159265359

typedef long long ll;

using namespace std;



ll par[100001];

ll ran[100001];

ll siz[100001];

vector<int> id[100001];

vector<int> num[100001];

 

void init(int n){

	for (int i = 0; i <= n; i++){

		par[i] = i;

		ran[i] = 0;

		siz[i] = 1;

	}

}

int find(int x){

	if (par[x] == x){

		return x;

	}else{

		par[x] = find(par[x]);

		return par[x];

	}

}

void unite(int x, int y){

	x = find(x);

	y = find(y);

	if (x == y) return;

 

	if (ran[x] < ran[y]){

		par[x] = y;

		siz[y] += siz[x];

	}else{

		par[y] = x;

		siz[x] += siz[y];

		if (ran[x] == ran[y]) ran[x]++;

	}

}

bool same(int x, int y){

	return find(x) == find(y);

}

int size(int x){

	return siz[find(x)];

}



int main(){

	int n, m;

	cin >> n >> m;

	init(n);

	vector<int> p(n+1);

	vector<pair<int, int> > vec(m);

	for (int i = 1; i <= n; i++){

		cin >> p[i];

	}

	for (int i = 0; i < m; i++){

		int x, y;

		cin >> x >> y;

		unite(x, y);

	}

	for (int i = 1; i <= n; i++){

		id[find(i)].push_back(i);

		num[find(i)].push_back(p[i]);

	}

	int ans = 0;

	for (int i = 1; i <= n; i++){

		if (id[i].size()){

			sort(num[i].begin(), num[i].end());

			int coun = 0;

			for (auto x : id[i]){

				coun += binary_search(num[i].begin(), num[i].end(), x);

			}

			ans += coun;

		}

	}

	cout << ans << endl;

	return 0;

}