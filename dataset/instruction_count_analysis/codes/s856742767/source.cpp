#include"stdc++.h"

using namespace std;



#define ll long long

#define pb push_back

#define bit(a , b) (((a)>>(b))&1)



const int maxn = 1e5 + 20;



pair<vector<int> , int> solve(ll n)

{

	vector<int> ans;

	if(n == 1)

	{

		ans.pb(1);

		ans.pb(1);

		return {ans , 1};

	}



	if(n == 2)

	{

		ans.pb(1);

		ans.pb(50);

		ans.pb(50);

		ans.pb(1);



		return {ans , 2};

	}



	vector<int> tmp;

	int F = 0;



	if(n % 2 == 1)

	{

		auto shit = solve(n / 2);

		F = shit.second;

		tmp = shit.first;

	}

	else

	{

		auto shit = solve(n / 2 - 1);

		F = shit.second;

		tmp = shit.first;

	}



	int mx1 = 0 , mx = 0;

	for(auto x : tmp)

	{

		if(x < 50)

			mx1 = max(mx1 , x);

		mx = max(mx , x);

	}



	int ahhh = F;



	for(int i = 0; i < F; i++)

		ans.pb(tmp[i]);

	

	ans.pb(mx1 + 1);

	F++;



	if(mx < 50)

		mx = 49;



	if(n % 2 == 0)

	{

		F++;

		ans.pb(mx + 1);

		ans.pb(mx + 1);

	}



	for(int i = ahhh; i < (int)tmp.size(); i++)

		ans.pb(tmp[i]);



	ans.pb(mx1 + 1);



	return {ans , F};

}



int main()

{

	ios_base::sync_with_stdio(false);

	cin.tie(0);

	cout.tie(0);



	ll n;

	cin >> n;



	vector<int> ans = solve(n).first;



	cout << ans.size() << endl;

	for(auto x : ans)

		cout << x << " ";

	cout << endl;



}
















