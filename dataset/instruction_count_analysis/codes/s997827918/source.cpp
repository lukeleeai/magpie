#include <iostream>

#include <cstdio>

#include <vector>

#include <map>

#include <set>

#include <queue>

#include <stack>

#include <algorithm>

#include <string>

using namespace std;



int N, M;

int H[1502], W[1502];



int sum_h(int i, int j){

	return (H[i] - H[j+1]);

}



int sum_w(int i, int j){

	return (W[i] - W[j+1]);

}



int main(){

	while( cin >> N >> M, N || M ){

		vector<int> h(N), w(M);

		for(int i=0; i < N ; i++ ) cin >> h[i];

		for(int i=0; i < M ; i++ ) cin >> w[i];

		

		// テァツエツッテァツゥツ催・ツ陳?

		fill(H, H + 1500, 0);

		fill(W, W + 1500, 0);

		for(int i=0 ; i < N ; i++ ) H[0] += h[i];

		for(int i=0 ; i < M ; i++ ) W[0] += w[i];

		for(int i=1 ; i < N ; i++ ) H[i] = H[i-1] - h[i-1];

		for(int i=1 ; i < M ; i++ ) W[i] = W[i-1] - w[i-1];

		

		for(int i=0 ; i < N ; i++ ){

			for(int j = i+1 ; j < N ; j++ ){

				h.push_back( sum_h(i, j) );

			}

		}

		for(int i=0 ; i < M ; i++ ){

			for(int j = i+1 ; j < M ; j++ ){

				w.push_back( sum_w(i, j) );

			}

		}

		

		map<int,int> memo;

		for(int i=0 ; i < h.size() ; i++ ){

			if( memo.count( h[i] ) ){

				memo[h[i]]++;

			}else{

				memo[h[i]] = 1;

			}

		}

		int ans = 0;

		for(int i=0 ; i < w.size() ; i++ ){

			if( memo.count( w[i] ) ){

				ans += memo[w[i]];

			}

		}

		cout << ans << endl;

	}

}