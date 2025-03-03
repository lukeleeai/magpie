#include "stdc++.h"



using namespace std;



int n, d1, d2;

vector<pair<int, int> > v[2], a[2];



int main(){

	scanf("%d%d%d", &n, &d1, &d2);

	int x = 0, y;

	while(d1 / (1 << (2 * x)) % 4 == 0) x++;

	y = d1 / (1 << (2 * x)) % 4;

	x = 1 << x;

	for(int i = 0;i < n * 2;i++){

		for(int j = 0;j < n * 2;j++){

			int ii = i / x, jj = j / x;

			if(y == 1){

				v[(ii + jj) & 1].push_back({i, j});

			}else if(y == 2){

				v[ii & 1].push_back({i, j});

			}else{

				v[0].push_back({i, j});

			}

		}

	}

	if(v[0].size() < v[1].size()) swap(v[0], v[1]);

	x = 0;

	while(d2 / (1 << (2 * x)) % 4 == 0) x++;

	y = d2 / (1 << (2 * x)) % 4;

	x = 1 << x;

	for(int k = 0;k < v[0].size();k++){

		int i = v[0][k].first, j = v[0][k].second;

		int ii = i / x, jj = j / x;

		if(y == 1){

			a[(ii + jj) & 1].push_back({i, j});

		}else if(y == 2){

			a[ii & 1].push_back({i, j});

		}else{

			a[0].push_back({i, j});

		}

	}

	if(a[0].size() < a[1].size()) swap(a[0], a[1]);

	for(int i = 1;i <= n * n;i++) printf("%d %d\n", a[0].back().first, a[0].back().second), a[0].pop_back();

}
