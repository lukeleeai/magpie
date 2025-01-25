#include <iostream>

#include <queue>

using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)

typedef pair<pair<int,int>,int> NODE;

#define X first.second

#define Y first.first

#define depth second



/*ï*/

int ox[] = {-1, 1, 0, 0, 1,1};

int oy[] = { 0, 0,-1, 1,-1,1};



/*ô*/

int ex[] = {-1, 1, 0, 0,-1,-1};

int ey[] = { 0, 0,-1, 1,-1, 1};



int main(){

	int point[100][100];

	int h,w,a,b,t,x,y,s;

	while(cin >> w  && w){

		int ret = 0;

		cin >> h;

		rep(i,100)rep(j,100)point[i][j] = 0;

		cin >> t;

		rep(i,t){

			cin >> a >> b;

			a--;b--;

			point[b][a] = i+1;

		}

		cin >> s;

		rep(P,s){

			cin >> a >> b;

			a--;b--;

			point[b][a] = 50;

			

		//rep(i,h){rep(j,w)cout << point[i][j];cout << endl;}

		int pt[100] = {0};

		rep(i,h)rep(j,w){

			x = j,y = i;

			queue<NODE> Q;

			pair<int,int> dp[100];

			bool done[100][100]={0};

			Q.push( make_pair(make_pair(y,x),0	) );

			while( Q.size() ){

				NODE q = Q.front(); Q.pop();

				if(point[q.Y][q.X]){

					dp[q.depth].first++;

					dp[q.depth].second = point[q.Y][q.X];

			  }

				if( q.Y % 2 == 1){

					rep(L,6){

						if( q.X+ox[L] >=0 && q.X+ox[L] < w && q.Y+oy[L] < h && q.Y+oy[L]>=0 ){

								if( !done[q.Y+oy[L]][q.X+ox[L]] )Q.push( make_pair(make_pair(q.Y+oy[L],q.X+ox[L]),q.depth+1) );

							  	done[q.Y+oy[L]][q.X+ox[L]] = true;

						}

					}

				}else{

					rep(L,6){

						if( q.X+ex[L] >=0 && q.X+ex[L] < w && q.Y+ey[L] < h && q.Y+ey[L]>=0 ){

									if( !done[q.Y+ey[L]][q.X+ex[L]] )Q.push( make_pair(make_pair(q.Y+ey[L],q.X+ex[L]),q.depth+1) );

							  	done[q.Y+ey[L]][q.X+ex[L]] = true;

						}

					}

				}

			}

			rep(I,100){

				if(dp[I].first){

					if(dp[I].first==1)

						pt[dp[I].second-1]++;

					break;

				}

			}

		}

			ret = max(pt[49],ret);

			point[b][a] = 0;

		}

		cout << ret << endl;

	}

	

}