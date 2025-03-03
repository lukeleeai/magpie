#include "stdc++.h"

#define ll long long

#define omar main

#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

//push_back make_pair emplace vector double float _unordered_map unodered_set queue stack sort begin end clear second first

using namespace std;



int omar() { fastIO

	int n; cin >> n;

	vector<int> arr, piv; 

	for (int i = 0 ; i < n ; i ++){

		int e; cin >> e;

		arr.push_back(e);

		piv.push_back(e);

	}

	int dif = 0;

	sort(arr.begin(), arr.end());

	for (int i = 0 ; i < n ; i++){

		if (arr[i] != piv[i])dif++;

	} cout << ((dif <= 2)? "YES" : "NO") << endl;

}
