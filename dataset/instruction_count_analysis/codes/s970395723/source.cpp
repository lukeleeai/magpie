#include "stdc++.h"



using namespace std;



const int N = 200005;



struct vec {

	int x, y;

	int operator*(const vec &o) const {

		return x * o.x + y * o.y;

	}

	int dist(const vec &o) const {

		return abs(x - o.x) + abs(y - o.y);

	}

} pt[N];



int n;



int main() {

	scanf("%d", &n);

	

	for(int i = 0; i < n; i++) {

		scanf("%d %d", &pt[i].x, &pt[i].y);

	}



	array<vec, 4> best{pt[0], pt[0], pt[0], pt[0]};



	for(int i = 0; i < n; i++) {

		int id = 0;

		for(int j : {-1, 1}) for(int k : {-1, 1}) {

			vec tmp{j, k};

			if(tmp * pt[i] > tmp * best[id]) best[id] = pt[i];

			id++;

		}

	}



	int ans = 0;

	for(int i = 0; i < 4; i++) for(int j = i + 1; j < 4; j++) {

		ans = max(ans, best[i].dist(best[j]));

	}



	printf("%d\n", ans);

}
