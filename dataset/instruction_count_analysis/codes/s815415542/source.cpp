#include "stdc++.h"

#define REP(i,a,b) for(int i=(a);i<(b);i++)

#define RREP(i,a,b) for(int i=(a);i>=(b);i--)

#define pq priotity_queue

#define P pair<int,int>

#define P2 pair<int,P>

#define P3 pair<int,P2>

typedef long long ll; typedef long double ld;

using namespace std;

const int INF=1e9, MOD=1e9+7, around[]={0,1,1,-1,-1,0,-1,1,0,0};

const ll LINF=1e18;

const ld PI=abs(acos(-1));

int h,w,a[210][210],cost[10][10];



int main(){

	cin >> h >> w;

	REP(i,0,10) REP(j,0,10) cin >> cost[i][j];

	REP(i,0,h) REP(j,0,w) cin >> a[i][j];

	

	REP(k,0,10){

		REP(i,0,10){

			REP(j,0,10){

				cost[i][j]=min(cost[i][j], cost[i][k]+cost[k][j]);

			}

		}

	}

	

	int s=0;

	REP(i,0,h){

		REP(j,0,w){

			if(a[i][j]==-1) continue;

			s+=cost[a[i][j]][1];

		}

	}

	

	cout << s << endl;

	return 0;

}
