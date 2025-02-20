#include <iostream>

#include <string>

#include <algorithm>

#include <set>

#include <vector>

#include <cstring>

#include <climits>

#include <queue>

#include <map>

#include <sstream>

using namespace std;



#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)

#define rep(i,n) REP(i,0,n)

#define EPS 1e-9



const int coin[] = {1,5,10,50,100,500};

const int inf = 999999999;

int c[6],p;



int oturi(int x){

	int ret = 0;

	for(int i=5; i>=0 && x>0; i--){

		ret += (x/coin[i]);

		x -= (x/coin[i])*coin[i];

	}

	return ret;

}

int pay(int x){

	int ret = 0;

	for(int i=5; i>=0 && x>0; i--){

		ret += min(x/coin[i], c[i]);

		x -= min(x/coin[i],c[i]) * coin[i];

	}

	return x==0 ? ret : -1;

}

int main(){

	while(scanf("%d",&p),p){

		scanf("%d%d%d%d%d%d",c,c+1,c+2,c+3,c+4,c+5);

		int sum = 0;

		int ret = INT_MAX;

		

		rep(i,6)sum += coin[i]*c[i];

		

		for(int i=p; i<=sum; i++){

			int t = pay(i);

			if( t!=-1 ){

				ret = min(ret, t+oturi(i-p));

			}

		}

		printf("%d\n",ret);

	}

	return 0;

}