#include"stdc++.h"

using namespace std;



const int N = 2e5+5;



int main()

{

	long long n, d, a;

	long long ans = 0, cur = 0;

	vector<pair<long long, long long>> monsters(N);

	queue<pair<long long,long long>> q; //dist , contribution to cur

	cin >> n >> d >> a;

	d *= 2;

	for(int i = 0; i < n; ++i)

		cin >> monsters[i].first >> monsters[i].second;

	sort(monsters.begin(), monsters.begin()+n);



	for(int i = 0; i < n; ++i){

		while(!q.empty()){

			if(q.front().first < monsters[i].first){

				cur -= q.front().second;

				q.pop();

			}

			else

				break;

		}

		monsters[i].second -= (cur*a);

		if(monsters[i].second > 0){

			long long contrib = ((monsters[i].second + a - 1) / a);

			ans += contrib;

			cur += contrib;

			q.push({monsters[i].first+d, contrib});

		}

	}

	cout << ans;

	return 0;

}
