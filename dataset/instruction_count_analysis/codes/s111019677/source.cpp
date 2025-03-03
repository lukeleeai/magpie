#include <cstdio>

#include <cstring>

#include <iostream>

#include <string>

#include <cmath>

#include <bitset>

#include <vector>

#include <map>

#include <set>

#include <queue>

#include <deque>

#include <algorithm>

#include <complex>

#include <unordered_map>

#include <unordered_set>

#include <random>

#include <cassert>

#include <fstream>

#include <utility>

#include <functional>

#define popcount __builtin_popcount

using namespace std;

typedef long long int ll;

typedef pair<int, int> P;

int main()

{

	int n; cin>>n;

	map<int, int> mp;

	for(int i=0; i<(1<<n); i++){

		int s; cin>>s;

		mp[s]++;

	}

	priority_queue<int> que;

	que.push(n);

	for(auto itr=mp.rbegin(); itr!=mp.rend(); itr++){

		int c=itr->second;

		if(c>que.size()){

			cout<<"No"<<endl;

			return 0;

		}

		vector<int> v;

		for(int i=0; i<c; i++){

			int x=que.top(); que.pop();

			v.push_back(x);

		}

		for(auto x:v) for(int y=0; y<x; y++) que.push(y);

	}

	cout<<"Yes"<<endl;

	return 0;

}