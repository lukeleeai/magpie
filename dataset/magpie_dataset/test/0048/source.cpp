#include "stdc++.h"

using namespace std;

int n ,k;

vector<int>vi;

long long mem[200005];

bool vis[200005];

long long solve(int indx ){

	if(indx == n-1)

		return 0;

	if(vis[indx])

		return mem[indx];

	vis[indx] = true;

	mem[indx] = 1e13;

	for(int i = indx+1; i <=min(indx+k , n-1) ; i++){

		mem[indx] = min(mem[indx] , solve(i ) + abs(vi[indx] - vi[i]));

	}

	return mem[indx];

}

//long long n , w;

//vector<pair<long long , long long>>vi;

//long long mem[105][100005];

//bool vis[105][100005];

//long long ans = 0;

//long long sol(int indx , int cost){

//	if(indx == n)

//		return 0;

//	if(vis[indx][cost])return mem[indx][cost];

//	mem[indx][cost] = 0;

//	long long fch = sol(indx + 1 , cost);

//	long long sch = 0;

//	if(mem[indx][cost] + vi[indx].first <= w){

//		sch = sol(indx + 1 , cost + vi[indx].second) + vi[indx].first;

//	}

//	return mem[indx][cost] = max()

//}

int main()

{

//	cin>>n>>w;

//	vi.resize(n);

//	for(int i = 0; i <n ; i++)

//		cin>>vi[i].first>>vi[i].second;

//

//	cout<<sol(0,0);



	cin>>n>>k;

	vi.resize(n);

	for(int i = 0; i <n ; i++)

		cin>>vi[i];

	cout<<solve(0);

	return 0;

}


