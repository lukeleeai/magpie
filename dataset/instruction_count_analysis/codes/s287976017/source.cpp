#include <iostream>

#include <algorithm>

#include <vector>

using namespace std;

#define rep(i,n) for(int i = 0 ; i < n ; i++)

struct P{int x,y;P(){}P(int a,int b){x = a , y = b;}};

int operator -(P a, P b){

	return abs(a.x - b.x) + abs(a.y - b.y);

}

int dp[1<<5][5][1000];

#define INF (1<<21)

int main(){	

	int W,H;

	while(cin >> W >> H , W){

		P s , g ;

		vector<P> v[6];

		rep(i,H)rep(j,W){

			char c; cin >> c;

			if(c == 'S') s = P(j,i);

			else if(c == 'G') g = P(j,i);

			else if(c != '.') v[c-'1'].push_back(P(j,i));

		}

		rep(i,1<<5)rep(k,5)rep(j,1000)dp[i][k][j] = INF;

		rep(i,5)rep(j,v[(i+1)%5].size()){

			dp[(1<<i) | (1<<((i+1)%5))][(i+1)%5][j] = s - v[(i+1)%5][j];

		}

		rep(bit,(1<<5)-1)rep(x,5){

			int y = (x+1)%5;

			rep(i,v[x].size()){

				if( dp[bit][x][i] == INF ) break; // <- ツ催適ツ可サ

				rep(j,v[y].size()){

					dp[bit|(1<<y)][y][j] = min( dp[bit|(1<<y)][y][j] , dp[bit][x][i] + (v[x][i]-v[y][j]) );

				}

			}

		}

		int ans = INF , cho = -1;

		rep(i,5) rep( j , v[i].size() ){

			int cst = dp[(1<<5)-1][i][j] + (g - v[i][j]);

			int w = (i+1)%5;

			if(ans >= cst){

				if(ans == cst){

					cho = min(cho, w );

				}else{

					cho = w;

					ans = cst;

				}

			}

		}

		if(ans == INF) cout << "NA" << endl;

		else cout << cho+1 << " " << ans << endl;

		

		

	}

	

}