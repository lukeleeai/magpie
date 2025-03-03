#include <iostream>

#include <cstdio>

#include <cstring>

#include <vector>

#include <string>

#include <algorithm>

using namespace std;



struct Rest {

	int score;

	string name;

	int id;

} rest[10000];



int n;



bool cmp(const Rest& a, const Rest& b) {

	if(a.name == b.name) return a.score > b.score;

	return a.name < b.name;

}



void in() {

	cin >> n;

	for(int i = 0;i < n;i ++) {

		cin >> rest[i].name >> rest[i].score;

		rest[i].id = i+1;

	}

}



void solve() {

	sort(rest, rest+n, cmp);

	for(int i = 0;i < n;i ++) {

		cout << rest[i].id << endl;

	}

}



int main() {

	in();

	solve();

	return 0;

}
