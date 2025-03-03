#include <iostream>

#include <algorithm>

#include <vector>

#include <queue>

#include <map>

#include <cstring>

#include <cstdio>

#define rep(i,n) for(int i = 0 ; i < n ; i++)

using namespace std;





int W,H;

int sx,sy,gx,gy;

vector< pair<int,int> > e[5];



int memo[1000][1000][5] = {};



int dfs(int x,int y,int c,int r){

	if( memo[x][y][c] != -1 ) return memo[x][y][c];

	if( r == 0 ) return abs(gx-x)+abs(gy-y);

	int g = (c+1)%5;

	int ans = 1e8;

	for(int i = 0 ; i < e[g].size() ; i++){

		ans = min( ans , dfs(e[g][i].first,e[g][i].second,g,r-1) + abs(e[g][i].first-x)+abs(e[g][i].second-y) );

	}

	return memo[x][y][c] = ans;

}

int main(){

	ios_base::sync_with_stdio(false);

	while(cin >> W >> H && W){

		rep(i,5)e[i].clear();

		sx = sy = gx = gy = 1e7;

		

		vector< pair<int,int> > list;

		rep(i,H){

			rep(j,W){

				char c;

				cin >> c;

				if( c == 'S' ) sx = j , sy = i;

				else if( c == 'G' ) gx = j , gy = i;

				else if( c != '.' ) e[c-'1'].push_back(make_pair(j,i)), list.push_back(make_pair(j,i));

			}

		}

		list.push_back(make_pair(sx,sy));

		list.push_back(make_pair(gx,gy));

		int F = !e[0].size() + !e[1].size() + !e[2].size() + !e[3].size() + !e[4].size();

		if( F >= 2){

			cout << "NA" << endl;

			continue;

		}

		pair<int,int> ans = make_pair(1e8,1e8);

		rep(i,5){

			rep(j,list.size()) rep(k,5) memo[list[j].first][list[j].second][k] = -1;

			ans = min(ans,make_pair(dfs(sx,sy,i,4),i));

		}

		if( 1e6 > ans.first ){

			cout << ans.second+1 << " " << ans.first << endl;

		}else{

			cout << "NA" << endl;

		}

	}

}