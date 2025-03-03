#include<iostream>

#include<vector>

#include<algorithm>

using namespace std;

long long x[200000], y[200000], n, H, W;

vector<long long>X, Y; vector<pair<long long, long long>>candidate;

long long dists(long long px, long long py) {

	vector<long long>RR; long long sum = 0;

	for (int i = 0; i < n; i++) {

		long long TT = abs(px - x[i]) + abs(py - y[i]);

		RR.push_back(TT); sum += TT;

	}

	sort(RR.begin(), RR.end());

	return sum * 2 - RR[RR.size() - 1];

}

int main() {

	cin >> H >> W >> n; for (int i = 0; i < n; i++) { cin >> x[i] >> y[i]; X.push_back(x[i]); Y.push_back(y[i]); }

	sort(X.begin(), X.end()); sort(Y.begin(), Y.end());

	vector<long long>HH, WW;

	if (n % 2 == 1) { HH.push_back(X[X.size() / 2]); WW.push_back(Y[Y.size() / 2]); }

	if (n % 2 == 0) {

		HH.push_back(X[X.size() / 2 - 1]); HH.push_back(X[X.size() / 2]);

		WW.push_back(Y[Y.size() / 2 - 1]); WW.push_back(Y[Y.size() / 2]);

	}

	unique(X.begin(), X.end()); unique(Y.begin(), Y.end());

	int pos1 = lower_bound(X.begin(), X.end(), HH[0]) - X.begin();

	int pos2 = lower_bound(Y.begin(), Y.end(), WW[0]) - Y.begin();

	int pos3 = 0, pos4 = 0;

	if (n % 2 == 0) {

		int pos1 = lower_bound(X.begin(), X.end(), HH[1]) - X.begin();

		int pos2 = lower_bound(Y.begin(), Y.end(), WW[1]) - Y.begin();

	}

	if (pos1 >= 1) { HH.push_back(X[pos1 - 1]); }

	if (pos1 < X.size() - 1 && n % 2 == 1) { HH.push_back(X[pos1 + 1]); }

	if (pos3 < X.size() - 1 && n % 2 == 0) { HH.push_back(X[pos3 + 1]); }

	if (pos2 >= 1) { WW.push_back(Y[pos2 - 1]); }

	if (pos2 < Y.size() - 1 && n % 2 == 1) { WW.push_back(Y[pos2 + 1]); }

	if (pos4 < Y.size() - 1 && n % 2 == 0) { WW.push_back(Y[pos4 + 1]); }

	for (int i = 0; i < HH.size(); i++) { for (int j = 0; j < WW.size(); j++)candidate.push_back(make_pair(HH[i], WW[j])); }

	long long minx = 999999999999999999LL, mx = 0, my = 0; sort(candidate.begin(), candidate.end());

	for (int i = 0; i < candidate.size(); i++) {

		long long UU = dists(candidate[i].first, candidate[i].second);

		if (minx > UU) { minx = UU; mx = candidate[i].first; my = candidate[i].second; }

	}

	cout << minx << endl << mx << ' ' << my << endl;

	return 0;

}