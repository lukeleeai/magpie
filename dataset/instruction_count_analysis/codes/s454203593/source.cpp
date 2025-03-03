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



int a[100001];

int b[100001];

set<int> st[100001];



int main(int argc, char const* argv[])

{

	int n, m;

	cin >> n >> m;

	for(int i = 0; i < m; i++){

			cin >> a[i] >> b[i];

			a[i]--;

			b[i]--;

			st[a[i]].insert(b[i]);

	}

	int res = 0;

	set<int> cul = st[0];

	for(int i = 1; i < n; i++){

			if(cul.find(i) != cul.end()){

					res++;

					cul = st[i];

			}else{

					for(auto itr = st[i].begin(); itr != st[i].end(); ++itr){

							cul.insert((*itr));

					}

			}

	}

	cout << res << endl;

	return 0;

}
