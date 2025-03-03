#include "stdc++.h"

using namespace std;

int n; double bx, by; pair<double, double> p[100009];

int main() {

	scanf("%d", &n);

	double sq = sin(1.234), cq = cos(1.234);

	for(int i = 0; i < n; i++) {

		scanf("%lf%lf", &bx, &by);

		double ex = bx * cq - by * sq;

		double ey = bx * sq + by * cq;

		p[i] = make_pair(ex, ey);

	}

	sort(p, p + n);

	double ret = 1.0e+10;

	for(int i = 0; i < n; i++) {

		for(int j = i + 1; j < n; j++) {

			double dx = p[i].first - p[j].first;

			if(dx * dx > ret) break;

			double dy = p[i].second - p[j].second;

			double dist = dx * dx + dy * dy;

			if(ret > dist) ret = dist;

		}

	}

	printf("%.15lf\n", sqrt(ret));

	return 0;

}