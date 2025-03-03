#include <stdio.h>

#include <iostream>

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

#include <sstream>



using namespace std;



#define EPS (1e-10)

#define EQ(a,b) (abs((a) - (b)) < EPS)

#define EQV(a,b) (EQ((a).real(),(b).real()) && EQ((a).imag(),(b).imag()))



typedef long long ll;



const int MAX_SIZE = 10000;



struct edge{

	int to;

	int cost;

	int enemy;

};



class Situation{

public:

	int cost;

	int node;

	int money;



	Situation(int cost_,int node_,int money_){

		cost=cost_;

		node=node_;

		money=money_;

	}

	Situation();



	bool operator<(const Situation &s)const{

		return s.cost < this->cost;

	}

};



int V;



const int MAX_V = 101;



vector<edge> G[MAX_V][MAX_V];

//  éêÉ écèàzÅ½Çè­Å¬RXg

int d[MAX_V][MAX_V];

const int INF = 100000000;



//int prevv[MAX_V];

int L;

int N;

int M;



void dijkstra(int s){

	priority_queue<Situation> que;

	for(int i = 0; i < MAX_V; i++)

		fill(d[i],d[i]+MAX_V,INF);

	d[s][L] = 0;

	que.push(Situation(0,s,L));

	while(!que.empty()){

		Situation p = que.top();

		que.pop();

		int node = p.node;

		int money=p.money;

		if(d[node][money] < p.cost)

			continue;

		for(int i = 0; i < G[node][money].size(); i++){

			edge e = G[node][money][i];

			// ¨àðgÁÄìµÄàç¤ê

			if(money-e.cost>=0){

				if(d[e.to][money-e.cost] > d[node][money]){

					d[e.to][money-e.cost] = d[node][money];

					que.push(Situation(d[e.to][money-e.cost],e.to,money-e.cost));

				}

			}

			// ìÈµÌê

			if(d[e.to][money]>d[node][money]+e.enemy){

				d[e.to][money]=d[node][money]+e.enemy;

				que.push(Situation(d[e.to][money],e.to,money));

			}

		}

	}

}



int main(){



	while(cin>>N>>M>>L&&!(N==0&&M==0&&L==0)){

		for(int i = 0; i < MAX_V; i++)

			for(int j = 0; j < MAX_V; j++)

				G[i][j].clear();

		int from,to,cost,enemy;

		for(int i = 0; i < M; i++){

			cin>>from>>to>>cost>>enemy;

			from--;

			to--;

			edge e;

			e.cost=cost;

			e.to=to;

			e.enemy=enemy;

			

			for(int i = 0; i < MAX_V; i++)

				G[from][i].push_back(e);

			e.to=from;

			for(int i = 0; i < MAX_V; i++)

				G[to][i].push_back(e);

		}

		dijkstra(0);

		int minCost=INF;

		for(int i = 0; i < MAX_V; i++)

			minCost=min(minCost,d[N-1][i]);

		cout<<minCost<<endl;

	}



	return 0;

}