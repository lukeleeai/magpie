#include <iostream>

#include <cstdio>

#include <cmath>

#include <algorithm>

#include <queue>



#define MAX_N 5000



using namespace std;



int N;

int E;

vector<int > in[MAX_N + 1];

vector<int > out[MAX_N + 1];

queue<int > S;

queue<int > L;



bool multi_flag;



bool in_exist(int v){

	bool flag = false;

	if(in[v].empty()) return false;

	for(int i = 0;i < in[v].size();i++){

		if(in[v][i] != -1) return true;

	}

	return false;

}



void solve(){

	for(int i = 1;i <= N;i++){

		if(in_exist(i) == false) S.push(i);

	}



	while(!S.empty()){

		int u = S.front();S.pop();

		L.push(u);

		int entered = 0;

		for(int i = 0;i < out[u].size();i++){

			int to = out[u][i];

			for(int i = 0;i < in[to].size();i++){

				if(in[to][i] == u) in[to][i] = -1;

			}

			

			if(in_exist(to) == false){

				S.push(to);

				entered++;

			}

		}

		if(entered >= 2) multi_flag = true;

	}



	return ;

}



int main(){



	scanf("%d",&N);

	scanf("%d",&E);

	//for(int i = 0;i <= MAX_N;i++){

	//	for(int j = 0;j <= MAX_N;j++){

	//		edge[i][j] = false;

	//	}

	//}

	int _u,_v;

	for(int i = 0;i < E;i++){

		scanf("%d%d",&_u,&_v);

		in[_v].push_back(_u);

		out[_u].push_back(_v);

	}



	solve();



	while(!L.empty()){

		int team = L.front();L.pop();

		printf("%d\n",team);

	}

	if(multi_flag) puts("1");

	else puts("0");



	return 0;

}