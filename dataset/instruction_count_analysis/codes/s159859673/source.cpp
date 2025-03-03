#include <iostream>

#include <cstdio>

#include <vector>

#include <list>

#include <cmath>

#include <fstream>

#include <algorithm>

#include <string>

#include <queue>

#include <set>

#include <map>

#include <complex>

#include <iterator>

#include <cstdlib>

#include <cstring>

#include <sstream>

#include <stack>

#include <climits>



using namespace std;

typedef long long ll;

typedef pair<int,int> pii;

double EPS=1e-10;

double EQ(double a,double b){

	return abs(a-b)<EPS;

}



struct edge{

	int to;

	int enm;

	int dist;

};

int N,M,L;

vector<edge> G[201];

int d[201][201];

typedef pair<int,pii> ppi;

const int INF=1000000000;



int dijkstra(){

	for(int i=0;i<200;i++)

		for(int j=0;j<200;j++)

			d[i][j]=INF;

	d[0][L]=0;

	priority_queue<ppi,vector<ppi>,greater<ppi> > pq;

	pq.push(make_pair(0,pii(0,L)));

	while(pq.size()){

		ppi p=pq.top();pq.pop();

		int ccost=p.first;

		int cnode=p.second.first;

		int cmoney=p.second.second;

		if(d[cnode][cmoney]<ccost)continue;

		for(int i=0;i<G[cnode].size();i++){

			edge &e=G[cnode][i];

			int nnode=e.to;

			// ツづ「ツづ?つ、

			if(e.dist<=cmoney){

				int ncost=ccost;

				int nmoney=cmoney-e.dist;

				if(d[nnode][nmoney]>ncost){

					d[nnode][nmoney]=ncost;

					pq.push(make_pair(ncost,pii(nnode,nmoney)));

				}

			}

			// ツづ「ツづ?づュツづ按つ「

			{

				int ncost=ccost+e.enm;

				int nmoney=cmoney;

				if(d[nnode][nmoney]>ncost){

					d[nnode][nmoney]=ncost;

					pq.push(make_pair(ncost,pii(nnode,nmoney)));

				}

			}

		}

	}

	int res=INF;

	for(int i=0;i<=L;i++){

		res=min(res,d[N-1][i]);

	}

	return res;

}



void solve(){

	while(cin>>N>>M>>L&&(N|M|L)){

		for(int i=0;i<201;i++)G[i].clear();

		for(int i=0;i<M;i++){

			int from,to,enm,dist;

			cin>>from>>to>>dist>>enm;

			from--;to--;

			edge e;

			e.dist=dist;

			e.to=to;

			e.enm=enm;

			G[from].push_back(e);

			e.to=from;

			G[to].push_back(e);

		}

		int res=dijkstra();

		cout<<res<<endl;

	}

}

int main(){

	solve();

	return 0;

}