#include <iostream>

#include <string>

#include <queue>

#include <vector>

#include <set>

#include <map>

#include <algorithm>

#include <utility>

#include <iomanip>



#define ll long long int

#define pb push_back

#define mk make_pair

#define pq priority_queue



using namespace std;

typedef pair<int, int> P;

typedef pair<ll, int> Pl;

const int inf = 1e9;

const ll linf = 1LL << 50;



bool comp(const P &a, const P &b){

		if(a.second != b.second)return a.second < b.second;

		else return a.first < b.first;

}



int main(int argc, char const* argv[])

{

	int n, m;

	cin >> n >> m;

	vector<P> vec;

	for(int i = 0; i < m; i++){

			int a, b;

			cin >> a >> b;

			a--; b--;

			vec.pb(mk(a, b));

	}

	sort(vec.begin(), vec.end(), comp);

	int res = 0;

	int curr = -1;

	for(auto itr = vec.begin(); itr != vec.end(); ++itr){

			if(curr <= (*itr).first){

					res++;

					curr = (*itr).second;

			}

	}

	cout << res << endl;

	return 0;

}
