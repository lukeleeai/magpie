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

vector<int> g[1<<18];

int s[1<<18];

int main()

{

	int n; cin>>n;

	for(int i=0; i<(1<<n); i++) cin>>s[i];

	//sort(s, s+(1<<n), greater<int>());

	vector<int> v;

	v.push_back(0);

	for(int i=0; i<n; i++){

		for(int j=0; j<(1<<i); j++){

			v.push_back(v[j]+(1<<i));

			g[v[j]].push_back(v[j]+(1<<i));

		}

	}

	int d[1<<18];

	for(int i=(1<<n)-1; i>=0; i--){

		d[i]=0;

		for(auto y:g[i]) d[i]=max(d[i], d[y]+1);

	}

	map<int, int> mp;

	for(int i=0; i<(1<<n); i++) mp[s[i]]++;

	priority_queue<P> que;

	que.push({d[0], 0});

	for(auto itr=mp.rbegin(); itr!=mp.rend(); itr++){

		int c=itr->second;

		if(c>que.size()){

			cout<<"No"<<endl;

			return 0;

		}

		vector<int> w;

		for(int i=0; i<c; i++){

			P p=que.top(); que.pop();

			w.push_back(p.second);

		}

		for(auto x:w){

			for(auto y:g[x]) que.push({d[y], y});

		}

	}

	/*queue<int> que;

	que.push(0);

	int t=0;

	int num[1<<18];

	while(!que.empty()){

		int x=que.front(); que.pop();

		num[x]=s[t];

		t++;

		for(auto y:g[x]){

			que.push(y);

		}

	}

	for(int i=0; i<(1<<n); i++){

		for(auto y:g[i]){

			if(num[i]<=num[y]){

				cout<<"No"<<endl;

				return 0;

			}

		}

	}*/

	cout<<"Yes"<<endl;

	return 0;

}