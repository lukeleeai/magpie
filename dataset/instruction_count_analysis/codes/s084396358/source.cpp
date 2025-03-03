// 'g++ -std=c++17 -O2 -Wall -Wextra -Wfatal-errors -o sample sample.cpp'

#include"stdc++.h"

#define int long long

#define sz(a) (int)(a).size()

 

using namespace std;



template <class T> bool uax( T& a , T b , bool action = true ) { if(action){ return (a>=b)?( true ):( a=b,false );} return (a>=b)?( true ):( false );}

template <class T> bool uin( T& a , T b , bool action = true ) { if(action){ return (a<=b)?( true ):( a=b,false );} return (a<=b)?( true ):( false );}



void dfs(int v,vector<int>&in_edges,vector<int>&dist,vector<int> arr[]){

	for( int i : arr[v] ){

		uax(dist[i],dist[v]+1);

		in_edges[i]--;

		if( in_edges[i] == 0 ) dfs(i,in_edges,dist,arr);

	}

}



void solve() {

        int n , m ; 

        cin >> n >> m ;

        vector<int>arr[n+1];

        vector<int>in_edges(n+1,0);

        int a , b ;

        for( int i = 0 ; i < m ; i++ ){

			cin >> a >> b;

			arr[a].push_back(b);

			in_edges[b]++;

		}

		for(int i = 0 ; i < n ; i++ ){

			arr[0].push_back(i+1);

			in_edges[i+1]++;

		}

		vector<int>dist(n+1,0);

		dfs(0,in_edges,dist,arr);

		cout << (*max_element(dist.begin(),dist.end())) - 1 << endl;

}

 

int32_t main() {

 

        ios_base::sync_with_stdio(false);

        cin.tie(nullptr);

        cout << fixed;

        cout.precision(10);

 

        int q = 1;

        //cin >> q;

        while (q--) {

            solve();

        }

        cout << endl;

        return 0;

}
